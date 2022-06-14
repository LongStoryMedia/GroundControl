#ifndef _LOCAL_INPUT_H
#define _LOCAL_INPUT_H

#include <stdint.h>

typedef struct Input
{
    int16_t yaw;
    int16_t pitch;
    int16_t roll;
    uint16_t thrust;
    uint8_t lockAlt;
} Input;

#endif