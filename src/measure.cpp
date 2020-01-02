#include <Wire.h>
#include <Adafruit_ADS1015.h>

#include "config.h"

Adafruit_ADS1115 ads(0x48); // chip ADDR is connected to GND

void setupMeasurement()
{
    ads.begin();
}

static void activatePump(bool active)
{
    Serial.printf("Pump %s\n", active ? "ON" : "OFF");
    digitalWrite(PIN_PUMP, active ? PUMP_ACTIVE : !PUMP_ACTIVE);
}

static int compareInt16(const void *a, const void *b)
{
    int16_t ia = *((int *)a);
    int16_t ib = *((int *)b);
    return (ia > ib) - (ia < ib);
}

static double readLevelMeters(uint16_t samples, uint32_t intervalMicros)
{
    ads.setGain(PRS_ADC_GAIN);
    int16_t readings[samples];
    Serial.print("  pressure readings [ ");
    for (uint16_t i = 0; i < samples; i++)
    {
        readings[i] = ads.readADC_Differential_0_1();
        Serial.printf("%d ", (int)readings[i]);
        delayMicroseconds(intervalMicros);
    }
    Serial.println(" ]");

    qsort(readings, samples, sizeof(int16_t), compareInt16);
    int16_t medianReading = readings[samples / 2];

    double voltage = medianReading * PRS_ADC_VOLT_PER_BIT;
    double levelMeters = voltage / LEVEL_VOLT_PER_METER;

    Serial.printf("Pressure ADC reading %d => voltage %.2fmV => level=%.3fm\n",
                  (int)medianReading, voltage * 1000, levelMeters);

    return levelMeters;
}

double measureLevelMeters()
{
    // read zero level (sensor's resistor bridge error)
    double zeroLevel = readLevelMeters(PRS_SINGLE_MEASURE_SAMPLES, PRS_SINGLE_MEASURE_INTV_MICROS);
    Serial.printf("Zero level: %.3fm\n", zeroLevel);

    // pump and measure until level stabilizes
    ulong pumpStartMillis = millis();
    activatePump(true);
    delay(PUMP_START_MILLIS);

    uint16_t maxCycles = (PUMP_TIMEOUT_MILLIS - PUMP_START_MILLIS) / PRS_MEASURE_STABILIZE_INTV_MILLIS;
    double level = zeroLevel;
    double lastLevel;
    uint16_t cycle = 0;
    do
    {
        lastLevel = level;
        cycle++;
        delay(PRS_MEASURE_STABILIZE_INTV_MILLIS);
        level = readLevelMeters(PRS_SINGLE_MEASURE_SAMPLES, PRS_SINGLE_MEASURE_INTV_MICROS);
        Serial.printf("cycle=%d maxCycles=%d lastLevel=%.3f level=%.3f\n",
                      (int)cycle, (int)maxCycles, lastLevel, level);
    } while (level - lastLevel > PRS_MEASURE_STABILIZE_LEVEL && cycle < maxCycles);

    activatePump(false);
    ulong pumpStopMillis = millis();

    double finalLevel = level - zeroLevel + LEVEL_TUBING_OFFSET_METERS;
    Serial.printf("===> LEVEL: %.3f m (pump on for %.2f s)\n",
                  finalLevel, (pumpStopMillis - pumpStartMillis) * 1e-3);

    return finalLevel;
}

double measureBatteryVoltage()
{
    delay(BAT_STABILIZE_MILLIS);

    ads.setGain(BAT_ADC_GAIN);
    int16_t reading = ads.readADC_SingleEnded(2);
    double voltage = reading * BAT_ADC_VOLT_PER_BIT;
    double batteryVoltage = voltage / BAT_ADC_VOLT_PER_BAT_VOLT;

    Serial.printf("Battery ADC reading %d => ADC voltage %.2fmV => battery voltage=%.3fm\n",
                  (int)reading, voltage * 1000, batteryVoltage);

    return batteryVoltage;
}
