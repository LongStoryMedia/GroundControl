/*
 *
 */

#include "spi.h"
#include <pigpio.h>
#include <iostream>

SPI::SPI()
{
}

void SPI::begin(int busNo, uint32_t spi_speed)
{
    if (this->spiIsInitialized)
    {
        return;
    }

    spiIsInitialized = true;
    gpioInitialise();
    spiHandle = spiOpen(0, spi_speed, PI_SPI_FLAGS_AUX_SPI(1));
    // if (spiHandle != 0)
    // {
    //     std::cout << "BAD HANDLE. check that " << busNo << " is correct bus";
    // }
}

void SPI::init(uint32_t speed)
{
}

uint8_t SPI::transfer(char tx)
{
    char rbuf = 0;
    spiXfer(spiHandle, &tx, &rbuf, 1);
    return rbuf;
}

void SPI::transfernb(char *tbuf, char *rbuf, uint32_t len)
{
    spiXfer(spiHandle, tbuf, rbuf, len);
}

SPI::~SPI()
{
}
