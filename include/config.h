#pragma once

#include <Arduino.h>

// Serial
#define SERIAL_BAUD    115200

// I2C for display and ADC
//#define USE_DISPLAY
#define PIN_I2C_CLOCK  4
#define PIN_I2C_DATA   2
#define DISP_I2C_FREQ 1000000
#define ADC_I2C_FREQ   400000

// Peripherals power supply for sensor, ADC and LoRa
#define PIN_PERIPHERALS            25
#define PERIPHERALS_ACTIVE       HIGH
#define PERIPHERALS_READY_MILLIS  800                   // [ms] wait time for peripherals to be ready

// Pump and valve
#define PIN_PUMP                   26
#define PUMP_ACTIVE              HIGH

// Pressure/water level measurement ADC conversion
#define PRS_ADC_GAIN                      GAIN_SIXTEEN  // 16x gain  +/- 0.256 V  1 bit = 0.0078125 mV
#define PRS_ADC_VOLT_PER_BIT              0.0078125e-3  // [V/bit] ADC resolution
#define PRS_SENSOR_VCC                    3.25          // [V] at sensor bridge
#define LEVEL_VOLT_PER_METER (PRS_SENSOR_VCC * 4.11e-3) // [V/m] sensor voltage depending on water level (pressure)
#define LEVEL_TUBING_OFFSET_METERS       -0.068         // [m] level offset correction for pressure loss in tubing

// Pressure measurement timing
#define PUMP_START_MILLIS                          400  // [ms] waiting time for pump start
#define PUMP_TIMEOUT_MILLIS                       3500  // [ms] measure no longer than this
#define PRS_SINGLE_MEASURE_SAMPLES                   9  // sample count for getting median
#define PRS_SINGLE_MEASURE_INTV_MICROS            1000  // [us] between samples
#define PRS_MEASURE_STABILIZE_LEVEL              0.002  // [m] max level delta to assume a stabilized level
#define PRS_MEASURE_STABILIZE_INTV_MILLIS          200  // [ms] between looking for stabilized level

// Battery voltage measurement ADC conversion
#define BAT_STABILIZE_MILLIS                       200  // [ms] waiting time before battery measurement after pump stop
#define BAT_ADC_GAIN                          GAIN_TWO  // 2x gain  +/- 2.048 V  1 bit = 0.0625 mV
#define BAT_ADC_VOLT_PER_BIT                 0.0625e-3  // [V/bit] ADC resolution
#define BAT_ADC_VOLT_PER_BAT_VOLT (6.8e3/(33e3+6.8e3))  // [V/V] ADC voltage per battery voltage (voltage divider)

// LoRa RFM95W connection
#define TTN_SPI_HOST      HSPI_HOST
#define TTN_SPI_DMA_CHAN  1
#define TTN_PIN_SPI_SCLK  14
#define TTN_PIN_SPI_MOSI  13
#define TTN_PIN_SPI_MISO  12
#define TTN_PIN_NSS       15 // SPI CS
#define TTN_PIN_RXTX      TTN_NOT_CONNECTED
#define TTN_PIN_RST       2          //TODO: Set to TTN_NOT_CONNECTED? It isn't connected!
#define TTN_PIN_DIO0      32
#define TTN_PIN_DIO1      33

// Measurement and transmission interval
#define MEASUREMENT_INTERVAL_MILLIS  300000             // high enough for 35ms airtime to stay below 30s/day
