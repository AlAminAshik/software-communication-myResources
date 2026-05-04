
#include <Wire.h>
int MQ91 = A0;

void setup() {
Wire.begin();
pinMode(MQ91, INPUT);
Serial.begin(9600);
}

void loop() {
  int MQ91Sensor = analogRead(MQ91);

 Wire.beginTransmission(0x40);
 Wire.write("No.");
 Wire.write(MQ91Sensor);
 Wire.endTransmission();
 delay(1000);

}
