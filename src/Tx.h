#ifndef _TX_LOCAL_H
#define _TX_LOCAL_H

class Tx
{
private:
    static const uint8_t radioNumber = 1;
    static const uint8_t botRadioNumber = 0;
    static const uint8_t packetSize = sizeof(Input);
    uint8_t failures;

public:
    void prepare();
    void sendPacket();
    void init();
    RF24 radio = RF24(CE_PIN, CSN_PIN);
};

#endif