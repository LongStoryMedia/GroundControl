#ifndef TX_H
#define TX_H

typedef struct
{
    char *lineOne;
    char *lineTwo;
} menu, menuPtr;
typedef void (*atCb)(menu lines);

class Tx
{
private:
    // pins
    static const uint8_t thrustPin = THRUST_PIN;
    static const uint8_t yawPin = YAW_PIN;
    static const uint8_t rollPin = ROLL_PIN;
    static const uint8_t pitchPin = PITCH_PIN;
    static const uint8_t radioNumber = 1;
    static const uint8_t botRadioNumber = 0;
    static const uint8_t packetSize = sizeof(State);
    uint8_t failures;

public:
    void prepare();
    void sendPacket();
    void init();
    RF24 radio = RF24(CE_PIN, CSN_PIN);
};

#endif