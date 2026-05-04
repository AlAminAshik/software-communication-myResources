
#include <Wire.h>

void setup() {

Wire.begin(0x40);                     //Initialize Arduino as slave with address 0x40
Wire.onReceive(receiveEvent);         //Register event
Serial.begin(9600);                   //start serial for debug             

}

void loop() {
}

//function that executes whenever data is received from master
void receiveEvent(int howMany){
  
 while(0<Wire.available()){             //loop through all but the last
  char cReceivedata = Wire.read();      //print the character
  Serial.print(cReceivedata);         // If '0' is received, turn the LED OFF vice versa
 Serial.println(" ");
 }

}
