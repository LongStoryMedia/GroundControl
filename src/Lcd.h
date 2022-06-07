#ifndef LCD_H
#define LCD_H

#define COLUMS 20
#define ROWS 4

typedef enum
{
    one,
    two
} row;

#ifndef TFT
class Lcd
{
private:
    void writeLabels();
    uint32_t lastRefresh;

public:
    enum
    {
        lineOne,
        lineTwo
    };
    LiquidCrystal_I2C screen = LiquidCrystal_I2C(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);
    void init();
    void stop();
    void writeState();
    void writeLine(const __FlashStringHelper *lineOne, row row);
    void writeLine(char *lineOne, row row);
    void writeLine(String lineOne, row row);
    void refreshDisplay();
};
#endif
#endif