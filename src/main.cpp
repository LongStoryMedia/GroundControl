#include "config.h"

Tx tx;
// #ifndef TFT
// Lcd lcd;
// #endif
uint32_t t, p, program_start;
// void loopRate(int freq);
// void togglePower();
// void buttonPress();

// const char *ssid = "LONGZZ";
// const char *password = "6u!tar00GG@ftw";
// WiFiServer server(80);
// String header;

int main(void)
{

  wiringPiSetup();
  tx.init();
  while (1)
  {
    t = micros();
    tx.prepare();
    // buttonPress();
    tx.sendPacket();
  }
  return 0;
}

// void setup()
// {
//   // Serial.begin(115200);
//   tx.init();
//   // lcd.init();
//   // lcd.writeLine(F("Starting controller"), (row)lcd.lineOne);
//   delay(1000);
//   // pinMode(GPIO_NUM_5, INPUT_PULLDOWN);
//   // esp_sleep_enable_ext0_wakeup(GPIO_NUM_27, 0);
//   p = 0;
// }

// void loop()
// {
//   t = micros();
//   tx.prepare();
//   // buttonPress();
//   tx.sendPacket();
//   // lcd.refreshDisplay();
// }

// void buttonPress()
// {
//   if (digitalRead(GPIO_NUM_5) == HIGH)
//   {
//     if (p == 0)
//     {
//       packet.lockAlt = packet.lockAlt == 0 ? 1 : 0;
//       p = t;
//     }
//     if (t - 2000000 > p)
//     {
//       lcd.writeLine(F("Shutting Down"), (row)lcd.lineOne);
//       delay(1000);
//       lcd.stop();
//       esp_deep_sleep_start();
//     }
//   }
//   else
//   {
//     p = 0;
//   }
// }