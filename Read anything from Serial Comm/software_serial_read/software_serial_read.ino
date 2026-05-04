void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);


}

void loop()
{
  // Displays information when new sentence is available.
  Serial.println("Place RFID tag near the module")
  while (Serial.available() > 0){
  int x = Serial.read();
  }
    if (value == 28754) {                   //if id of newtag matches with Tisha
    Serial.print("\nWelcome Tisha\n");    //serial monitor display
    else if (value == 9211) {            //if id of newtag matches with Ayman
    Serial.print("\nWelcome Ayman\n ");  //serial monitor check

}