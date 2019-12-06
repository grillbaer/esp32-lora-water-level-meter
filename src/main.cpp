#include <Arduino.h>
#include <Wire.h>
#include "freertos/FreeRTOS.h"

#include "config.h"
#include "measure.h"
#include "display.h"
#include "lora.h"

void setup()
{
  Serial.begin(SERIAL_BAUD);
  Wire.begin(PIN_I2C_DATA, PIN_I2C_CLOCK, ADC_I2C_FREQ);
  setupMeasurement();
  setupDisplay();
  setupLora();
}

void loop()
{
  const unsigned long startMillis = millis();

  double levelMeters = measureLevelMeters();

  char buf[100];
  sprintf(buf, "%4.3f m", levelMeters);
  display(buf);

  sendMeasurement(levelMeters);

  const unsigned long stopMillis = millis();
  // already elapsed, also handle millis overflow:
  unsigned long elapsedMillis = (stopMillis - startMillis) > 0 ? (stopMillis - startMillis) : 0;
  const unsigned long remainingMillis = MEASUREMENT_INTERVAL_MILLIS - elapsedMillis;

  Serial.printf("Sleeping %.3fs ...\n", remainingMillis * 1000.0);
  delay(remainingMillis);
}
