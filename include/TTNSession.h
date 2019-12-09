#pragma once

#include "lmic/lmic.h"

/*
 * Used to save and restore LMIC session before and after deep sleep.
 */
class TTNSession
{
public:
  TTNSession();

  void reset();
  bool isValid();

  void readFromLMIC();
  void readSeqnoFromLMIC();
  void writeToLMIC();
  void print();

private:
  uint32_t netid;
  uint32_t devaddr;
  uint8_t nwkKey[16];
  uint8_t artKey[16];
  uint32_t seqnoUp;
  uint16_t checksum;
  int8_t adrTxPow;
  uint8_t datarate;

  uint16_t calcChecksum();
};
