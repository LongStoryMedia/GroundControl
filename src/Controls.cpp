#include "Controls.h"
#include <string.h>
#include <stdlib.h>

Input Controls::parse(char *raw)
{
    Input input;
    // inputPacket.thrust = 0;
    // // constrain(map(analogRead(thrustPin), 0, 3600, 1000, 0), 0, 1000);
    // inputPacket.roll = 0;
    // // constrain(map(analogRead(rollPin), 100, 3700, -500, 500), -500, 500);
    // inputPacket.pitch = 0;
    // // constrain(map(analogRead(pitchPin), 100, 3550, 500, -500), -500, 500);
    // inputPacket.yaw = 0;
    // // constrain(map(analogRead(yawPin), 100, 3550, -500, 500), -500, 500);
    // inputPacket.thrust = (inputPacket.thrust < 25 || inputPacket.thrust > 1000) ? 0 : inputPacket.thrust;
    // inputPacket.roll = inputPacket.roll > -25 && inputPacket.roll < 25 ? 0 : inputPacket.roll;
    // inputPacket.pitch = inputPacket.pitch > -25 && inputPacket.pitch < 25 ? 0 : inputPacket.pitch;
    // inputPacket.yaw = inputPacket.yaw > -25 && inputPacket.yaw < 25 ? 0 : inputPacket.yaw;
    // if (inputPacket.lockAlt == 1 && lockedThrust == 0)
    // {
    //     lockedThrust = inputPacket.thrust;
    // }
    // else if (inputPacket.lockAlt == 0 && lockedThrust > 0)
    // {
    //     lockedThrust = 0;
    // }
    char *thrust = "";
    char *yaw = "";
    char *pitch = "";
    char *roll = "";
    char *iPtr = "";
    for (int i = 0; i < RAW_INPUT_DATA_LEN; i++)
    {
        if (raw[i] == (char)"t")
        {
            iPtr = "t";
            i++;
        }
        if (raw[i] == (char)"y")
        {
            iPtr = "y";
            i++;
        }
        if (raw[i] == (char)"p")
        {
            iPtr = "p";
            i++;
        }
        if (raw[i] == (char)"r")
        {
            iPtr = "r";
            i++;
        }
        if (raw[i] == (char)"a")
        {
            iPtr = "a";
            i++;
        }
        if (raw[i] == (char)"|")
        {
            break;
        }
        if (iPtr == "t")
        {
            strcat(thrust, &(raw[i]));
        }
        if (iPtr == "y")
        {
            strcat(yaw, &(raw[i]));
        }
        if (iPtr == "p")
        {
            strcat(pitch, &(raw[i]));
        }
        if (iPtr == "r")
        {
            strcat(roll, &(raw[i]));
        }
        if (iPtr == "a")
        {
            input.lockAlt = atoi(&(raw[i]));
        }
    }

    input.thrust = atoi(thrust);
    input.yaw = atoi(yaw);
    input.pitch = atoi(pitch);
    input.roll = atoi(roll);

    return input;
}