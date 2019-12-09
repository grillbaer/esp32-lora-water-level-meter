#include <Arduino.h>

#include "TTNSession.h"

#include "hal/hal_esp32.h"

extern HAL_ESP32 ttn_hal;

TTNSession::TTNSession()
{
    // do NOT initialize here because
    // we want to keep state over deep sleep in
    // RTC_DATA_ATTR memory.
}

void TTNSession::reset()
{
    netid = 0;
    devaddr = 0;
    memset(artKey, 0, sizeof(artKey));
    memset(nwkKey, 0, sizeof(nwkKey));
    seqnoUp = 0;
    checksum = 0;
    adrTxPow = 0;
    datarate = 0;
}

bool TTNSession::isValid()
{
    return checksum == calcChecksum() && devaddr != 0;
}

static uint16_t arrayChecksum(u1_t *array, uint16_t size)
{
    uint16_t cs = 1;
    for (int i = 0; i < size; i++)
    {
        cs = cs * 7 - 3 + array[i];
    }

    return cs;
}

uint16_t TTNSession::calcChecksum()
{
    uint16_t cs = 59;
    cs = 17 * cs + netid;
    cs = 13 * cs + devaddr;
    cs = 71 * cs + seqnoUp;
    cs = 5 * cs + arrayChecksum(artKey, sizeof(artKey));
    cs = 23 * cs + arrayChecksum(nwkKey, sizeof(nwkKey));
    cs = 7 * cs + datarate + 5 * adrTxPow;

    return cs;
}

void TTNSession::readFromLMIC()
{
    ttn_hal.enterCriticalSection();
    LMIC_getSessionKeys(&netid, &devaddr, nwkKey, artKey);
    seqnoUp = LMIC_getSeqnoUp();
    adrTxPow = LMIC.adrTxPow;
    datarate = LMIC.datarate;
    ttn_hal.leaveCriticalSection();
    checksum = calcChecksum();
}

void TTNSession::readSeqnoFromLMIC()
{
    ttn_hal.enterCriticalSection();
    seqnoUp = LMIC_getSeqnoUp();
    ttn_hal.leaveCriticalSection();
    checksum = calcChecksum();
}

void TTNSession::writeToLMIC()
{
    ttn_hal.enterCriticalSection();
    LMIC_setSession(netid, devaddr, nwkKey, artKey);
    LMIC_setSeqnoUp(seqnoUp);
    LMIC_setDrTxpow(datarate, adrTxPow);
    ttn_hal.leaveCriticalSection();
}

void TTNSession::print()
{
    Serial.printf(
        "netid=%08lX\n"
        "devaddr=%08lX\n"
        "seqnoUp=%d\n"
        "datarate=%d\n"
        "adrTxPow=%d\n"
        "checksum=%d\n"
        "expected checksum=%d\n",
        (ulong)netid, (ulong)devaddr, (int)seqnoUp, (int)datarate, (int)adrTxPow,
        (int)checksum, (int)calcChecksum());
}
