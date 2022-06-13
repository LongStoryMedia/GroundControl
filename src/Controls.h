#ifndef _CONTROLS_LOCAL_H
#define _CONTROLS_LOCAL_H

// Input packet;

class Controls
{
private:
    volatile char t[5];
    volatile char y[5];
    volatile char p[5];
    volatile char r[5];
    volatile char a[2];

public:
    Controls();
    ~Controls();
    void parse(char *raw);
};

#endif