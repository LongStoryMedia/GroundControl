/*****************************************************************************
 * | File      	:   DEV_Config.c
 * | Author      :   Waveshare team
 * | Function    :   Hardware underlying interface
 * | Info        :
 *----------------
 * |	This version:   V2.0
 * | Date        :   2019-07-08
 * | Info        :   Basic version
 *
 ******************************************************************************/
#include "DEV_Config.h"

#if USE_DEV_LIB
pthread_t t1;
UWORD pwm_dule = 100;
struct sched_param param;
pthread_attr_t attr;
void *BL_PWM(void *arg)
{

    UWORD i = 0;
    for (i = 0;; i++)
    {
        if (i > 64)
            i = 0;
        if (i < (pwm_dule / 16))
            LCD_BL_1;
        else
            LCD_BL_0;
    }
}
#endif
void DEV_SetBacklight(UWORD Value)
{
    gpioPWM(LCD_BL, Value);
}

/*****************************************
                GPIO
*****************************************/
void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
    gpioWrite(Pin, Value);
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
    return gpioRead(Pin);
}

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{
    if (Mode == 0 || Mode == PI_INPUT)
    {
        gpioSetMode(Pin, PI_INPUT);
        gpioSetPullUpDown(Pin, PI_PUD_UP);
    }
    else
    {
        gpioSetMode(Pin, PI_OUTPUT);
    }
}

/**
 * delay x ms
 **/
void DEV_Delay_ms(UDOUBLE xms)
{
    gpioDelay(xms * 1000);
}

static void DEV_GPIO_Init(void)
{
    DEV_GPIO_Mode(LCD_CS, 1);
    DEV_GPIO_Mode(LCD_RST, 1);
    DEV_GPIO_Mode(LCD_DC, 1);
    DEV_GPIO_Mode(LCD_BL, 1);

    DEV_GPIO_Mode(KEY_UP_PIN, 0);
    DEV_GPIO_Mode(KEY_DOWN_PIN, 0);
    DEV_GPIO_Mode(KEY_LEFT_PIN, 0);
    DEV_GPIO_Mode(KEY_RIGHT_PIN, 0);
    DEV_GPIO_Mode(KEY_PRESS_PIN, 0);
    DEV_GPIO_Mode(KEY1_PIN, 0);
    DEV_GPIO_Mode(KEY2_PIN, 0);
    DEV_GPIO_Mode(KEY3_PIN, 0);
    LCD_CS_1;
    LCD_BL_1;
}
/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_ModuleInit(void)
{
    // if(wiringPiSetup() < 0)//use wiringpi Pin number table
    if (gpioInitialise() < 0)
    { // use BCM2835 Pin number table
        DEBUG("set pigpio lib failed	!!! \r\n");
        return 1;
    }
    else
    {
        DEBUG("set pigpio lib success  !!! \r\n");
    }
    DEV_GPIO_Init();
    /** NOTE: find equivalent!!! */
    // wiringPiSPISetup(0, 40000000);
    spiOpen(0, 40000000, 0);
    gpioSetMode(LCD_BL, PI_OUTPUT);
    gpioSetPWMrange(LCD_BL, 4000);
    gpioPWM(LCD_BL, 512);

    return 0;
}

void DEV_SPI_WriteByte(uint8_t Value)
{
    spiWrite(0, (char *)&Value, 1);
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
    spiWrite(0, (char *)pData, Len);
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_ModuleExit(void)
{
    spiClose(0);
}