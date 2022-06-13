#include "config.h"

#define GREEN_PIN 4
#define RED_PIN 27
#define BLUE_PIN 22
#define LED_PIN 23

uint32_t t, p;

Tx tx;


int main(void)
{
  gpioInitialise();
  gpioSetMode(GREEN_PIN, PI_OUTPUT);
  gpioSetMode(RED_PIN, PI_OUTPUT);
  gpioSetMode(BLUE_PIN, PI_OUTPUT);
  gpioSetMode(LED_PIN, PI_OUTPUT);
  // gpioSetPWMfrequency(GREEN_PIN, 90000);
  // gpioSetPWMfrequency(RED_PIN, 0);
  // gpioSetPWMfrequency(BLUE_PIN, 0);
  // // tx.init();
  // // while (1)
  // // {
  gpioWrite(LED_PIN, 1);
  gpioPWM(GREEN_PIN, 5);
  gpioPWM(RED_PIN, 175);
  gpioPWM(BLUE_PIN, 0);
  // //   // tx.prepare();
  // //   // tx.sendPacket();
  // // }
  /* Module Init */
  if (DEV_ModuleInit() != 0)
  {
    DEV_ModuleExit();
    exit(0);
  }
  printf("2inch LCD demo...\r\n");
  LCD_2IN_Init();
  LCD_2IN_Clear(WHITE);
  LCD_SetBacklight(1000);

  UDOUBLE Imagesize = LCD_2IN_HEIGHT * LCD_2IN_WIDTH * 2;
  UWORD *BlackImage;
  if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
  {
    printf("Failed to apply for black memory...\r\n");
    exit(0);
  }

  // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
  Paint_NewImage(BlackImage, LCD_2IN_WIDTH, LCD_2IN_HEIGHT, 90, WHITE, 16);
  Paint_Clear(WHITE);
  Paint_SetRotate(ROTATE_270);
  // /* GUI */
  printf("drawing...\r\n");
  // /*2.Drawing on the image*/
  Paint_DrawPoint(5, 10, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  Paint_DrawPoint(5, 25, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
  Paint_DrawPoint(5, 40, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawPoint(5, 55, BLACK, DOT_PIXEL_4X4, DOT_STYLE_DFT);

  Paint_DrawLine(20, 10, 70, 60, RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(70, 10, 20, 60, RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(170, 15, 170, 55, RED, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(150, 35, 190, 35, RED, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);

  Paint_DrawRectangle(20, 10, 70, 60, BLUE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawRectangle(85, 10, 130, 60, BLUE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  Paint_DrawCircle(170, 35, 20, GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawCircle(170, 85, 20, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  Paint_DrawString_EN(5, 70, "hello world", &Font16, WHITE, BLACK);
  Paint_DrawString_EN(5, 90, "waveshare", &Font20, RED, IMAGE_BACKGROUND);

  Paint_DrawNum(5, 160, 123456789, &Font20, GREEN, IMAGE_BACKGROUND);
  Paint_DrawString_CN(5, 200, "΢ѩ����", &Font24CN, IMAGE_BACKGROUND, BLUE);

  // /*3.Refresh the picture in RAM to LCD*/
  LCD_2IN_Display((UBYTE *)BlackImage);
  int i2cHandle = i2cOpen(1, 0x08, 0);

  while (1)
  {
    char buffer[RAW_INPUT_DATA_LEN];
    if (i2cReadDevice(i2cHandle, buffer, RAW_INPUT_DATA_LEN) == RAW_INPUT_DATA_LEN)
    {
      // const char *inputData = (const char[1])buffer[0];
      // printf((const char *)buffer[0]);
      std::cout << buffer;
    }
  }

  DEV_Delay_ms(2000);

  free(BlackImage);
  BlackImage = NULL;
  gpioTerminate();
  return 0;
}
