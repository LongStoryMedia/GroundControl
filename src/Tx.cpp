#include "config.h"
// #include "printf.h"
State packet;
uint16_t lockedThrust;

uint8_t address[][6] = {"bird", "nest"};

void Tx::prepare()
{
    packet.thrust = 0;
    // constrain(map(analogRead(thrustPin), 0, 3600, 1000, 0), 0, 1000);
    packet.roll = 0;
    // constrain(map(analogRead(rollPin), 100, 3700, -500, 500), -500, 500);
    packet.pitch = 0;
    // constrain(map(analogRead(pitchPin), 100, 3550, 500, -500), -500, 500);
    packet.yaw = 0;
    // constrain(map(analogRead(yawPin), 100, 3550, -500, 500), -500, 500);
    packet.thrust = (packet.thrust < 25 || packet.thrust > 1000) ? 0 : packet.thrust;
    packet.roll = packet.roll > -25 && packet.roll < 25 ? 0 : packet.roll;
    packet.pitch = packet.pitch > -25 && packet.pitch < 25 ? 0 : packet.pitch;
    packet.yaw = packet.yaw > -25 && packet.yaw < 25 ? 0 : packet.yaw;
    if (packet.lockAlt == 1 && lockedThrust == 0)
    {
        lockedThrust = packet.thrust;
    }
    else if (packet.lockAlt == 0 && lockedThrust > 0)
    {
        lockedThrust = 0;
    }
}

void Tx::init()
{
    // initialize the transceiver on the SPI bus
    radio.begin();

    // radio.setPALevel(RF24_PA_LOW); // RF24_PA_MAX is default.

    // save on transmission time by setting the radio to only transmit the
    // number of bytes we need to transmit
    radio.setPayloadSize(packetSize); // default value is the maximum 32 bytes

    // set the TX address of the RX node into the TX pipe
    radio.openWritingPipe(address[radioNumber]); // always uses pipe 0

    // set the RX address of the TX node into a RX pipe
    // radio.openReadingPipe(botRadioNumber, address[botRadioNumber]); // using pipe 1

    radio.stopListening(); // put radio in TX mode

    radio.enableDynamicAck();
    radio.setAutoAck(true);

    failures = 0;
    // For debugging info
    // printf_begin();             // needed only once for printing details
    // radio.printDetails();       // (smaller) function that prints raw register values
    // radio.printPrettyDetails(); // (larger) function that prints human readable data
}

void Tx::sendPacket()
{
    radio.flush_tx();

    if (!radio.write(&packet, packetSize, true))
    {
        failures++;
        radio.reUseTX();
    }
    else
    {
        failures = 0;
    }

    if (failures >= 10)
    {
        radio.powerDown();
        radio.flush_tx();
        radio.powerUp();
        radio.flush_tx();
        init();
    }
}
