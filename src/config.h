#ifndef CONFIG_H
#define CONFIG_H

#define DEBUG false

#include "types.h"

#if defined TFT
#include <TFT_eSPI.h> // Hardware-specific library
#else
// #include <LiquidCrystal_I2C.h>
#endif
#include "../lib/RF24/RF24.h"
#include "../lib/RF24/nRF24L01.h"
#include "../lib/RF24/RF24.cpp"
// #include <WiFi.h>

#define THRUST_PIN 0
#define YAW_PIN 0
#define ROLL_PIN 0
#define PITCH_PIN 0
#define CE_PIN 0
#define CSN_PIN 0

#include "Tx.h"
// #include "Lcd.h"

extern State packet;
extern uint16_t lockedThrust;

#endif