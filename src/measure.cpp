#include <Wire.h>
#include <Adafruit_ADS1015.h>

#include "config.h"

Adafruit_ADS1115 ads(0x48); // ADDR to GND

void setupMeasurement()
{
    ads.setGain(ADC_GAIN);
    ads.begin();
}

static void activatePump(boolean active)
{
    Serial.printf("Pump %s\n", active ? "ON" : "OFF");
    digitalWrite(PIN_PUMP, active ? PUMP_ACTIVE : !PUMP_ACTIVE);
}

static int compare_int16(const void *a, const void *b)
{
    int16_t ia = *((int *)a);
    int16_t ib = *((int *)b);
    return (ia > ib) - (ia < ib);
}

static double readLevelMeters(uint16_t samples, uint32_t intervalMicros)
{
    int16_t readings[samples];
    Serial.print("  readings [ ");
    for (uint16_t i = 0; i < samples; i++)
    {
        readings[i] = ads.readADC_Differential_0_1();
        Serial.printf("%d ", (int)readings[i]);
        delayMicroseconds(intervalMicros);
    }
    Serial.println(" ]");

    qsort(readings, samples, sizeof(int16_t), compare_int16);
    int16_t medianReading = readings[samples / 2];

    double voltage = medianReading * ADC_VOLT_PER_BIT;
    double levelMeters = voltage / VOLT_PER_METER;

    Serial.printf("ADC reading %d => voltage %.2fmV => level=%.3fm\n",
                  (int)medianReading, voltage * 1000, levelMeters);

    return levelMeters;
}

double measureLevelMeters()
{
    // read zero level (sensor's resistor bridge error)
    double zeroLevel = readLevelMeters(SINGLE_MEASURE_SAMPLES, SINGLE_MEASURE_INTV_MICROS);
    Serial.printf("Zero level: %.3fm\n", zeroLevel);

    // pump and measure until level stabilizes
    ulong pumpStartMillis = millis();
    activatePump(true);
    delay(PUMP_START_MILLIS);

    uint16_t maxCycles = (PUMP_TIMEOUT_MILLIS - PUMP_START_MILLIS) / MEASURE_STABILIZE_INTV_MILLIS;
    double level = zeroLevel;
    double lastLevel;
    uint16_t cycle = 0;
    do
    {
        lastLevel = level;
        cycle++;
        delay(MEASURE_STABILIZE_INTV_MILLIS);
        level = readLevelMeters(SINGLE_MEASURE_SAMPLES, SINGLE_MEASURE_INTV_MICROS);
        Serial.printf("cycle=%d maxCycles=%d lastLevel=%.3f level=%.3f\n", (int)cycle, (int)maxCycles, lastLevel, level);
    } while (level - lastLevel > MEASURE_STABILIZE_LEVEL && cycle < maxCycles);

    activatePump(false);
    ulong pumpStopMillis = millis();

    double finalLevel = level - zeroLevel + TUBING_OFFSET_METERS;
    Serial.printf("===> LEVEL: %.3f m (pump on for %.2f s)\n", finalLevel, (pumpStopMillis - pumpStartMillis) * 1e-3);

    return finalLevel;
}
