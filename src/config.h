#ifndef _CONFIG_LOCAL_H
#define _CONFIG_LOCAL_H

#include <pigpio.h>
#include <iostream>
#include <stdint.h>
#include <RF24/RF24.h>
#include <RF24/nRF24L01.h>

#include "LCD/DEV_Config.h"
#include "LCD/LCD_2inch.h"
#include "LCD/GUI/GUI_Paint.h"
#include "LCD/GUI/GUI_BMP.h"

#define CE_PIN 0
#define CSN_PIN 0

typedef struct Input
{
    int16_t yaw;
    int16_t pitch;
    int16_t roll;
    uint16_t thrust;
    uint8_t lockAlt;
} Input;

extern Input packet;

#define RAW_INPUT_DATA_LEN 21

#include "Controls.h"
#include "Tx.h"

#endif