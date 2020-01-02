#include <driver/rtc_io.h>

#include "config.h"

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

void activatePeripherals(bool active)
{
    //TODO: why does this disturb SPI on both pin 25 and 17? Can it be reactivated for other SPI pins?
    //    Serial.printf("Peripherals %s\n", active ? "ON" : "OFF");
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

void goToDeepSleep(uint32_t sleepMillis)
{
    Serial.printf("Deep sleep for %.3fs ...\n", sleepMillis * 1e-3);
    Serial.flush();

    preparePinsForDeepSleep();

    esp_sleep_enable_timer_wakeup(sleepMillis * 1e3);
    esp_deep_sleep_start();
}

void afterDeepSleepOrPowerOn(void)
{
    resetPins();
}
