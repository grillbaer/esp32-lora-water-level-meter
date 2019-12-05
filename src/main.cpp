#include <Arduino.h>
#include <Wire.h>
#include "measure.h"
#include "display.h"
#include "lora.h"
#include "config.h"

void setup() {
  Serial.begin(SERIAL_BAUD);
  Wire.begin(PIN_I2C_DATA, PIN_I2C_CLOCK, ADC_I2C_FREQ);
  setupMeasure();
  setupDisplay();
  lora_init();
}

void loop() {
  double levelMeters = measureLevelMeters();
  
  char buf[100];
  sprintf(buf, "%4.3f m", levelMeters);
  display(buf);
  
  delay(10000);
}
