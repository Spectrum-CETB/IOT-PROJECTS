// up streaming


#include <SoftwareSerial.h> //Software Serial library
SoftwareSerial espSerial(9, 10); //Pin 2 and 3 act as RX and TX. Connect them to TX and RX of ESP8266
#define DEBUG true
String mySSID = "abc"; // WiFi SSID
String myPWD = "poiuytrewq"; // WiFi Password
String myAPI = "S7J9J8D26V9UWYV4"; // API Key
String myHOST = "api.thingspeak.com";
String myPORT = "80";
String myFIELD1 = "field1";
int sendVal;
void setup()
{
Serial.begin(115200);
espSerial.begin(115200);
espData("AT+RST", 1000, DEBUG); //Reset the ESP8266 module
espData("AT+CWMODE=1", 1000, DEBUG); //Set the ESP mode as station mode
espData("AT+CWJAP=\"" + mySSID + "\",\"" + myPWD + "\"", 1000, DEBUG); //Connect to WiFi network
delay(1000);
}
void loop()
{
/* Here, I'm using the function random(range) to send a random value to the
ThingSpeak API. You can change this value to any sensor data
so that the API will show the sensor data
*/
sendVal = analogRead(A0); // Send a random number between 1 and 1000
String sendData = "GET /update?api_key=" + myAPI + "&" + myFIELD1 + "=" + String(sendVal);
espData("AT+CIPMUX=1", 1000, DEBUG); //Allow multiple connections
espData("AT+CIPSTART=0,\"TCP\",\"" + myHOST + "\"," + myPORT, 1000, DEBUG);
espData("AT+CIPSEND=0," + String(sendData.length() + 4), 1000, DEBUG);
espSerial.find(">");
espSerial.println(sendData);
Serial.print("Value to be sent: ");
Serial.print(sendVal);
espData("AT+CIPCLOSE=0", 1000, DEBUG);
delay(1000);
}
String espData(String command, const int timeout, boolean debug)
{
Serial.print("AT Command ==> ");
Serial.print(command);
Serial.println(" ");
String response = "";
espSerial.println(command);
delay(1000);
if (debug)
{
//Serial.print(response);
}
return response;
}
