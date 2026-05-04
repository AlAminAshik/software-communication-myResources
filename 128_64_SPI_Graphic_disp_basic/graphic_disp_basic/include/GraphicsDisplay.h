#include <cstdint>  // For uint8_t, etc.
#include <U8g2lib.h>    // Graphics library for monochrome displays
#include <SPI.h> // Specific display driver

#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

class GraphicsDisplay {
private:
    //const u8g2_cb_t* u8g2;
    uint8_t clock = PA5; // Default pin for clock
    uint8_t data = PA7;  // Default pin for data;
    uint8_t cs = PA3;    // Default pin for chip select
    char StrPipeNo[20] = "Production:";
    char StrWeight[20] = "Weight:";
    char StrDamagedPipe[20] = "Damaged:";

    char StrBtn1[10] = "Tare";
    char StrBtn2[10] = "Dmg";
    char StrBtn3[10] = "Coil";

public:
    U8G2_ST7920_128X64_1_SW_SPI u8g2;
    GraphicsDisplay() : u8g2(U8G2_R0, clock, data, cs) {}
    bool setup();
    void drawIntroScreen();
    void updateDisplay(int numPipeNo, int numDamagedPipe, const char* weight, const char* footer);
    void clearDisplay();
};

#endif // GRAPHICSDISPLAY_H