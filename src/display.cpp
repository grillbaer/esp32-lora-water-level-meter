#include "U8g2lib.h"

#include "display.h"
#include "config.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE , PIN_I2C_CLOCK, PIN_I2C_DATA);


void setupDisplay(void) {
    u8g2.setBusClock(DISP_I2C_FREQ);
    u8g2.begin();
    u8g2.setFont(u8g2_font_crox4hb_tr);
}

void display(char *s) {
    u8g2.clearBuffer();
    u8g2.drawStr(5, 25, s);
    u8g2.sendBuffer();
}
