#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <hornet_fonts.h>

// The constructor below determines the type of display,
// and the way how it's connected.
// For more options and documentation see https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Another useful resource is this video: https://www.youtube.com/watch?v=MHogSbRPa28
// For 0.92" generic display:
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C display(U8G2_R0, PIN_A4, PIN_A5);
// For 2.33" Waveshare:
// U8G2_SSD1305_128X32_ADAFRUIT_F_HW_I2C display(U8G2_R0, PIN_A4, PIN_A5);

// For cycling fonts:
uint8_t f = 0;
const uint8_t* fonts[] {
    u8g2_DcsFont_tf,  // looks like a 16-segment display
    u8g2_DcsFontHornet2_BIOS_09_tf,  // for the scratch display
    u8g2_DcsFontHornet3_BIOS_09_tf,  // for the option displays
    u8g2_DcsFontHornet4_BIOS_09_tf,  // for the scratch display
};

void setup()
{
    Serial.begin(9600);
    display.begin();
}

void loop()
{
    // Cycle through fonts
    Serial.println(f);
    display.setFont(fonts[f]);
    f++;
    if (f == sizeof(fonts) / sizeof(fonts[0]))
    {
        f = 0;
    }

    // Write something
    display.clearBuffer();
    display.drawStr(0, 32, "|ABC123");
    display.sendBuffer();

    delay(1000);
}
