#pragma once

#include <Arduino.h>

#define SERIAL_BAUD    115200
#define PIN_I2C_CLOCK  4
#define PIN_I2C_DATA   5

#define PIN_SENSOR    14
#define SENSOR_ACTIVE HIGH
#define PIN_PUMP      12
#define PUMP_ACTIVE   HIGH

#define DISP_I2C_FREQ 1000000
#define ADC_I2C_FREQ   400000

#define ADC_GAIN             GAIN_SIXTEEN           // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
#define ADC_VOLT_PER_BIT     0.0078125e-3           // [V/bit] ADC resolution
#define SENSOR_VCC           3.25                   // [V] at sensor bridge
#define VOLT_PER_METER       (SENSOR_VCC * 4.05e-3) // [V/m] sensor voltage depending on water level (pressure)
#define TUBING_OFFSET_METERS -0.06                  // [m] level offset correction for tubings pressure loss

#define SENSOR_READY_MILLIS            100        // [ms] wait time for sensor ready
#define PUMP_START_MILLIS             1000        // [ms] wait time for pump start
#define PUMP_TIMEOUT_MILLIS          10000        // [ms] measure no longer than this
#define SINGLE_MEASURE_SAMPLES           9        // sample count for getting median
#define SINGLE_MEASURE_INTV_MICROS    1000        // [us] between samples
#define MEASURE_STABILIZE_LEVEL       0.01        // [m] max delta to assume a stabilized level
#define MEASURE_STABILIZE_INTV_MILLIS  500        // [ms] between looking for stabilized level
