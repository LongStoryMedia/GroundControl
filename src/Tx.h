#ifndef _TX_LOCAL_H
#define _TX_LOCAL_H

#define CE_PIN 0
#define CSN_PIN 0

#include <stdint.h>

#include <RF24/RF24.h>
#include <RF24/nRF24L01.h>

#include "Input.h"

class Tx
{
private:
    static const uint8_t radioNumber = 1;
    static const uint8_t botRadioNumber = 0;
    static const uint8_t packetSize = sizeof(Input);
    uint8_t failures;

public:
    void sendPacket(Input inputPacket);
    void init();
    RF24 radio = RF24(CE_PIN, CSN_PIN);
};

#endif