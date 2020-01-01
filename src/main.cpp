#include <Arduino.h>
#include <Wire.h>
#include <freertos/FreeRTOS.h>
#include <esp_sleep.h>
#include <driver/gpio.h>
#include <driver/rtc_io.h>

#include "config.h"
#include "measure.h"
#include "display.h"
#include "lora.h"

static const uint8_t PINS_TO_ISOLATE[] = {
    PIN_PUMP,
    PIN_PERIPHERALS,
    PIN_I2C_DATA,
    PIN_I2C_CLOCK,
    TTN_PIN_DIO0,
    TTN_PIN_DIO1,
    TTN_PIN_SPI_MISO,
    TTN_PIN_SPI_MOSI,
    TTN_PIN_SPI_SCLK,
};

static const uint8_t PINS_TO_PULL_LOW[] = {
    TTN_PIN_NSS,
};

static void activatePeripherals(boolean active)
{
  //    Serial.printf("Peripherals %s\n", active ? "ON" : "OFF"); // why does this disturb SPI on both pin 25 and 17
  digitalWrite(PIN_PERIPHERALS, active ? PERIPHERALS_ACTIVE : !PERIPHERALS_ACTIVE);
}

static void preparePinsForDeepSleep()
{
  for (uint16_t i = 0; i < sizeof(PINS_TO_ISOLATE) / sizeof(PINS_TO_ISOLATE[0]); i++)
  {
    rtc_gpio_isolate((gpio_num_t)PINS_TO_ISOLATE[i]);
  }

  for (uint16_t i = 0; i < sizeof(PINS_TO_PULL_LOW) / sizeof(PINS_TO_PULL_LOW[0]); i++)
  {
    rtc_gpio_pullup_dis((gpio_num_t)PINS_TO_PULL_LOW[i]);
    rtc_gpio_set_direction((gpio_num_t)PINS_TO_PULL_LOW[i], RTC_GPIO_MODE_OUTPUT_ONLY);
    rtc_gpio_set_level((gpio_num_t)PINS_TO_PULL_LOW[i], 0);
  }
}

static void resetPins()
{
  for (uint16_t i = 0; i < sizeof(PINS_TO_ISOLATE) / sizeof(PINS_TO_ISOLATE[0]); i++)
  {
    rtc_gpio_hold_dis((gpio_num_t)PINS_TO_ISOLATE[i]);
  }

  for (uint16_t i = 0; i < sizeof(PINS_TO_PULL_LOW) / sizeof(PINS_TO_PULL_LOW[0]); i++)
  {
    rtc_gpio_hold_dis((gpio_num_t)PINS_TO_PULL_LOW[i]);
  }
}

void setup()
{
  resetPins();

  Serial.begin(SERIAL_BAUD);

  pinMode(PIN_PERIPHERALS, OUTPUT);
  pinMode(PIN_PUMP, OUTPUT);
  digitalWrite(PIN_PUMP, !PUMP_ACTIVE);

  activatePeripherals(true);
  delay(PERIPHERALS_READY_MILLIS);

  Wire.begin(PIN_I2C_DATA, PIN_I2C_CLOCK, ADC_I2C_FREQ);

  setupMeasurement();

#ifdef USE_DISPLAY
  setupDisplay();
#endif
  setupLora();
}

void loop()
{
  const unsigned long startMillis = millis();

  double levelMeters = measureLevelMeters();

  char buf[100];
  sprintf(buf, "%4.3f m", levelMeters);
#ifdef USE_DISPLAY
  display(buf);
#endif

  sendMeasurement(levelMeters);

  const unsigned long stopMillis = millis();
  // already elapsed, also handle millis overflow:
  unsigned long elapsedMillis = (stopMillis - startMillis) > 0 ? (stopMillis - startMillis) : 0;
  const unsigned long remainingMillis = MEASUREMENT_INTERVAL_MILLIS - elapsedMillis;

  activatePeripherals(false);

  Serial.printf("Deep sleep for %.3fs ...\n", remainingMillis * 1e-3);
  Serial.flush();

  preparePinsForDeepSleep();

  esp_sleep_enable_timer_wakeup(remainingMillis * 1e3);
  esp_deep_sleep_start();
}
