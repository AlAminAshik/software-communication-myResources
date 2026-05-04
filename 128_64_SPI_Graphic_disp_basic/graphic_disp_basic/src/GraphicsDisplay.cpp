#include <GraphicsDisplay.h>
#include <cstdint>
#include <U8g2lib.h>

// GraphicsDisplay::GraphicsDisplay(const u8g2_cb_t* u8g2, uint8_t clock, uint8_t data, uint8_t cs) {
//     this->u8g2 = U8G2_R0;
//     this->clock = clock;
//     this->data = data;
//     this->cs = cs;
// }

bool GraphicsDisplay::setup() {
    U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, clock, data, cs);
    u8g2.begin();
    return true;
}

void GraphicsDisplay::drawIntroScreen() {
    u8g2.firstPage();
    do {
        u8g2.setFont(u8g2_font_8x13B_tr); // Large bold font
        u8g2.setCursor(5, 25);
        u8g2.print("Steeltech");
        u8g2.setCursor(4, 40);
        u8g2.print("Industries");
        u8g2.setCursor(5, 55);
        u8g2.print("Limited");
    } while (u8g2.nextPage());
}

void GraphicsDisplay::updateDisplay(int numPipeNo, int numDamagedPipe, const char* weight, const char* footer) {
    u8g2.firstPage();
  do {
    // Main border
    u8g2.drawFrame(0, 0, 128, 64);

    u8g2.setFont(u8g2_font_6x13_tr);
    u8g2.setCursor(5, 16);  u8g2.print(StrPipeNo);
    u8g2.setCursor(5, 32);  u8g2.print(StrWeight);
    u8g2.setCursor(5, 48);  u8g2.print(StrDamagedPipe);

    // Values (English numbers, bold)
    u8g2.setFont(u8g2_font_6x13_tr);
    u8g2.setCursor(80, 16);  u8g2.print(numPipeNo);
    u8g2.setCursor(80, 32);  u8g2.print(numDamagedPipe);
    u8g2.setCursor(57, 48);  u8g2.print(weight);

    // Buttons (smaller font inside filled rectangles)
    u8g2.setFont(u8g2_font_6x13_tr);
    // Draw filled rectangles
    u8g2.drawBox(96, 0, 32, 64);   // Right side for buttons
    // Draw button texts (in white color on black background)
    u8g2.setDrawColor(0); // Switch to "erase" color for text
    u8g2.setCursor(100, 16); u8g2.print(StrBtn1);
    u8g2.drawTriangle(96,16-13+6, 96,29-13-4+5, 99,22-13+4);
    u8g2.setCursor(100, 37); u8g2.print(StrBtn2);
    u8g2.drawTriangle(96,37-13+6, 96,50-13-4+5, 99,43-13+4);
    u8g2.setCursor(100, 59); u8g2.print(StrBtn3);
    u8g2.drawTriangle(96,58-13+6, 96,71-13-4+5, 99,64-13+4);
    u8g2.setDrawColor(1); // Reset to normal drawing
    
    // Footer (smaller font)
    u8g2.setFont(u8g2_font_5x8_tr);
    u8g2.drawBox(0, 55, 62, 8);   // Right side for buttons
    u8g2.setDrawColor(0); // Switch to "erase" color for text
    u8g2.setCursor(5, 62);
    u8g2.print(footer);
    u8g2.setDrawColor(1); // Reset to normal drawing
  } 
  while (u8g2.nextPage());
}

void GraphicsDisplay::clearDisplay() {
    u8g2.clearDisplay();
}