#pragma once

#include <Arduino.h>

void activatePeripherals(bool active);

void goToDeepSleep(uint32_t sleepMillis);
void afterDeepSleepOrPowerOn(void);
