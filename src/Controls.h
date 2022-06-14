#ifndef _CONTROLS_LOCAL_H
#define _CONTROLS_LOCAL_H

#define RAW_INPUT_DATA_LEN 21

#include "Input.h"

class Controls
{
private:
    volatile char t[5];
    volatile char y[5];
    volatile char p[5];
    volatile char r[5];
    volatile char a[2];

public:
    Input parse(char *raw);
};

#endif