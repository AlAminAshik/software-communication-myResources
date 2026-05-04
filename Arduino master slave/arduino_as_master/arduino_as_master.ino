int incomingByte = 0;

void setup() {
Serial.begin(9600);
Serial1.begin(9600); //serial 2 means arduino mega pin 16(TX) and 17(RX)

}

void loop() {

if(Serial1.available()>0){              //only output when something is found in serial
  incomingByte = Serial1.parseInt();    //read the first number before space, parseint only finds number
 Serial.print(incomingByte);            //print the first number before space
 Serial.print(" ");                     //add space after first number
incomingByte = Serial1.parseInt();      //read the second number before space
  Serial.print(incomingByte);           //print the second number before space
  Serial.print(" ");                    //add space after second number
incomingByte = Serial1.parseInt();      //read the third number before space
  Serial.println(incomingByte);         //print the third number and add enter

  
  String  incomingByte = Serial1.readString();  //useful to read only one data that is can be decimal number
 Serial.print(incomingByte);            //print the string. use "incomingByte.toDouble()" to convert string to number
}
}
