#line 1 "/Users/scott.long/Nextcloud/platformio/GroundControl/i2cInputs/main.cpp"
#include <Arduino.h>
#include <stdint.h>
#include <Wire.h>

#define ADDRESS 0x08

char throttle[5];
char yaw[5];
char pitch[5];
char roll[5];
char lockAlt[2];

void postI2c()
{
  itoa(analogRead(1), throttle, 10);
  itoa(analogRead(0), yaw, 10);
  itoa(analogRead(3), pitch, 10);
  itoa(analogRead(2), roll, 10);
  itoa(digitalRead(8), lockAlt, 10);

  Wire.write("t");
  Wire.write(throttle);
  Wire.write("y");
  Wire.write(yaw);
  Wire.write("p");
  Wire.write(pitch);
  Wire.write("r");
  Wire.write(roll);
  Wire.write("a");
  Wire.write(lockAlt);
}

void setup()
{
  Wire.begin(ADDRESS);
  Wire.onRequest(postI2c);
}

void loop()
{
}