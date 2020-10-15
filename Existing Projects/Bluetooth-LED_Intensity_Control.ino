#include<SoftwareSerial.h>
SoftwareSerial BTserial(2,3); //Bluetooh HC-05 connection to Arduino Nano


void setup() {
  Serial.begin(9600); //Start Serial Monitor of Arduino
  BTserial.begin(38400);//Bluetooth Serial at 38400 baud rate (default for HC-05)
  //Define LED pin numbers and Output
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
}



void loop() {
//When the data flows from Android to Bluetooth,Read the data and identify integers in data


if(BTserial.available()>2)
  {
  int tenth=BTserial.parseInt();
  int eleventh=BTserial.parseInt();
  int twelfth=BTserial.parseInt();


//Write the intensity value (0-255) to given LED bulb
  analogWrite(10,tenth);
  analogWrite(11,eleventh);
  analogWrite(5,twelfth);


//Print the Intensity of the LED in Serial Monitor
  Serial.print(tenth);
  Serial.print(',');
  Serial.print(eleventh);
  Serial.print(',');
  Serial.println(twelfth);

  }
}
