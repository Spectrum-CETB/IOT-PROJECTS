#include <SPI.h>
#include "RF24.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

char msg[1]; //SCK -> 13//MISO -> 12//MOSI -> 11//CSN -> 10//CE -> 9
RF24 radio(9, 10);
const uint64_t pipe = 0b00000;
String val;
int i = 0,x , y;


byte spaceplane[8] = {
  0b00000,
  0b00111,
  0b00100,
  0b01010,
  0b11011,
  0b01010,
  0b00100,
  0b00111
};
byte spaceplane1[8] = {
  0b00000,
  0b11100,
  0b00100,
  0b01010,
  0b00111,
  0b01010,
  0b00100,
  0b11100
};
void setup() {
  lcd.begin(16, 2);
  lcd.createChar(4, spaceplane);
  lcd.createChar(5, spaceplane1);
  lcd.setCursor(0, 0);
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("WELCOME TO");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("THE SPACE GAME ");
  delay(100);
  lcd.setCursor(15, 2);
  lcd.write(4);
  delay(100);
  lcd.setCursor(16, 2);
  lcd.write(4);
  delay(100);
  lcd.setCursor(17, 2);
  lcd.write(4);
  delay(100);
  lcd.setCursor(18, 2);
  lcd.write(4);
  delay(100);
  lcd.setCursor(19, 2);
  lcd.write(4);
  delay(2000);
  lcd.clear();
}
void loop()
{
  int a , b;

  a = analogRead(A0);
  b = analogRead(A1);

  if ( a > 1000 && 490 < b < 525 )   //// right
  {
    x++;
    delay(300);
  }

  if ( 490 < a < 525 && b < 10 ) //////// left
  {

    x--;
    delay(300);
  }

  if ( a < 10  && 490 < b < 595 ) //////// down

  {
    y = 1;
    delay(250);
  }

  if ( a > 1000  && 490 < b < 530 )  //////// up

  {
    y = 0;
    delay(250);
  }

  if (x == 15)
  {
    x = 15;
  }


  lcd.setCursor(x, y);
  lcd.write(4);
  delay(500);
  lcd.clear();

}
