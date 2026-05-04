void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // Displays information when new sentence is available.
  while (Serial.available() > 0){   //write something on the serial monitor
    Serial.write(Serial.read());    //send data through the TX pin of the board
    //Serial.print(Serial.read());  //this would print the decimal value
  }
}