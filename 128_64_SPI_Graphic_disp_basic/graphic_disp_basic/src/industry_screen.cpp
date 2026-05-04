/* connection of the display with stm32 bluepill
Dispaly       STM32
 * BLK        GND
 * BLA        3.3V
 * PSB        GND
 * E (SCK)    PA5
 * RW (MOSI)  PA7
 * RS (CS)    PA3
 * 
 * VCC        5V
 * GND        GND
*/

#include <Arduino.h>
#include <GraphicsDisplay.h>

GraphicsDisplay display;

#define tare_button PC13
#define damage_button PC14
#define coil_button PA9

#define Count_trigger PB0

int numPipeNo = 0;
char numWeight[] = "000.0";  // Removed "kg"
int numDamagedPipe = 0;
//String footerText;

unsigned long previousMillis = 0; // Variable to store the time of the last update
int i = 0;


void tareFunction(){
    // Tare button pressed
    numDamagedPipe = 0;
    numPipeNo = 0;
    display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Tared");
}
void damageFunction(){
    // Damage button pressed
    numDamagedPipe++;
    display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Damaged");
}
void coilFunction(){
    // Coil button pressed
    numPipeNo++;
    display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Coiled");
}
void countFunction(){
    // Count triggered
    numPipeNo++;
    display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Counted");
}


void setup() {
  display.setup();
  pinMode(tare_button, INPUT_PULLUP);
  pinMode(damage_button, INPUT_PULLUP);
  pinMode(coil_button, INPUT_PULLUP);
  pinMode(Count_trigger, INPUT_PULLUP);

  display.drawIntroScreen();
  delay(3000);  // Show intro for 5 seconds
  //display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Ongshak 01");

  attachInterrupt(digitalPinToInterrupt(tare_button), tareFunction, FALLING);
  attachInterrupt(digitalPinToInterrupt(damage_button), damageFunction, FALLING);
  attachInterrupt(digitalPinToInterrupt(coil_button), coilFunction, FALLING);
  attachInterrupt(digitalPinToInterrupt(Count_trigger), countFunction, FALLING);
}

void loop() {
    unsigned long currentMillis = millis(); // get the current time in milliseconds
  if(currentMillis - previousMillis > 3000) { // if more than 3 seconds have passed since the last update
    previousMillis = currentMillis; // reset the previousMillis to the currentMillis
    if(i == 0){
      display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Ongshak 01");
    }
    else if (i == 1){
      display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Data need..");
    }
    else if (i == 2){
      display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Data Sent!");
    }
    else i = -1;
    i++;
    display.updateDisplay(numPipeNo, numDamagedPipe, numWeight, "Footer");
  }
  delay(200);
}
