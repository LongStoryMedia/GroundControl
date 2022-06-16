#include "Tx.h"
#include <iostream>

uint8_t address[][6] = {"bird", "nest"};
uint16_t lockedThrust;

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

void Tx::sendPacket(Input inputPacket)
{
    radio.flush_tx();

    if (!radio.write(&inputPacket, packetSize, true))
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
