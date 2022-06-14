#include "Controls.h"

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
    for (int i = 0; i < RAW_INPUT_DATA_LEN; i++)
    {
    }
    return input;
}