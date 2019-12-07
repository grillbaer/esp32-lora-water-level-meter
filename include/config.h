#pragma once

#include <Arduino.h>

// Serial
#define SERIAL_BAUD    115200

// I2C display and ADC
#define PIN_I2C_CLOCK  4
#define PIN_I2C_DATA   5
#define DISP_I2C_FREQ 1000000
#define ADC_I2C_FREQ   400000

// Measurement pins
#define PIN_SENSOR    25
#define SENSOR_ACTIVE HIGH
#define PIN_PUMP      26
#define PUMP_ACTIVE   HIGH

// Measurement ADC conversion
#define ADC_GAIN             GAIN_SIXTEEN           // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
#define ADC_VOLT_PER_BIT     0.0078125e-3           // [V/bit] ADC resolution
#define SENSOR_VCC           3.25                   // [V] at sensor bridge
#define VOLT_PER_METER       (SENSOR_VCC * 4.11e-3) // [V/m] sensor voltage depending on water level (pressure)
#define TUBING_OFFSET_METERS -0.068                 // [m] level offset correction for tubings pressure loss

// Measurement timing
#define SENSOR_READY_MILLIS            100        // [ms] wait time for sensor ready
#define PUMP_START_MILLIS              400        // [ms] wait time for pump start
#define PUMP_TIMEOUT_MILLIS           3500        // [ms] measure no longer than this
#define SINGLE_MEASURE_SAMPLES           9        // sample count for getting median
#define SINGLE_MEASURE_INTV_MICROS    1000        // [us] between samples
#define MEASURE_STABILIZE_LEVEL      0.002        // [m] max delta to assume a stabilized level
#define MEASURE_STABILIZE_INTV_MILLIS  200        // [ms] between looking for stabilized level

// LoRa RFM95W 
#define TTN_SPI_HOST      HSPI_HOST
#define TTN_SPI_DMA_CHAN  1
#define TTN_PIN_SPI_SCLK  14
#define TTN_PIN_SPI_MOSI  13
#define TTN_PIN_SPI_MISO  12
#define TTN_PIN_NSS       15 // SPI CS
#define TTN_PIN_RXTX      TTN_NOT_CONNECTED
#define TTN_PIN_RST       2
#define TTN_PIN_DIO0      39
#define TTN_PIN_DIO1      16

// Measurement and transmission interval
#define MEASUREMENT_INTERVAL_MILLIS  120000       // high enough for 35ms airtime to stay below 30s/day