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
#include "power.h"

void setup()
{
  afterDeepSleepOrPowerOn();

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
  double batteryVoltage = measureBatteryVoltage();

#ifdef USE_DISPLAY
  char buf[100];
  sprintf(buf, "%4.3f m", levelMeters);
  display(buf);
#endif

  sendMeasurement(levelMeters, batteryVoltage);

  const unsigned long stopMillis = millis();
  // already elapsed, also handle millis overflow:
  unsigned long elapsedMillis = (stopMillis - startMillis) > 0 ? (stopMillis - startMillis) : 0;
  const unsigned long remainingMillis = MEASUREMENT_INTERVAL_MILLIS - elapsedMillis;

  activatePeripherals(false);
  goToDeepSleep(remainingMillis);
}
