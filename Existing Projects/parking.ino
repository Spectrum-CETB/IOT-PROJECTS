#include <Servo.h>

Servo servo1;


const int analogInPin1 = A0;
const int analogInPin2 = A1;
const int analogInPin3 = A2;
//const int analogInPin4 = A3;

const int servo_sensor1 = A3;
//const int servo_sensor2 = A5;

int led = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int x1, y1, z1;

const int servo_1 = 6;
//const int servo_2 =7;

int value_1 = 0;
int value_2 = 0;
void setup()
{
  pinMode (analogInPin1, INPUT);
  pinMode (analogInPin2, INPUT);
  pinMode (analogInPin3, INPUT);
  //pinMode (analogInPin4,INPUT);

  pinMode(servo_sensor1, INPUT);
  //pinMode(servo_sensor2,INPUT);

  servo1.attach(servo_1);
  //servo2.attach(servo_2);

  pinMode (led, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  Serial.begin(9600);
 
  
  

}

void loop()
{

  value_1 = analogRead(servo_sensor1);
  //value_2 = analogRead(servo_sensor2);

  // servo 1 code //

  {
    if (analogRead(A3) < 500)
    {
      servo1.write(90);
      delay(3000);
    }

  }

  if (analogRead(A3) > 500)
  {
    servo1.write(0);
    delay(60);
  }

  // servo 2 code //

  {
    /*if (analogRead(A5)<500)
      {
        servo2.write(90);
        delay(3000);
      }

      }

      if (analogRead(A5)>500)
      {
        servo2.write(0);
        delay(60);
      }*/


    // Parking Slot 1 IR & Led
    if (analogRead(A0) < 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led, HIGH);
      x1 = 1;
    }

    else if (analogRead(A0) > 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led, LOW);
      x1 = 0;
    }

    // Parking Slot 2 IR & Led
    if (analogRead(A1) < 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led1, HIGH);
      y1 = 1;
    }

    else if (analogRead(A1) > 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led1, LOW);
      y1 = 0;
    }

    // Parking Slot 3 IR & Led
    if (analogRead(A2) < 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led2, HIGH);
      z1 = 1;
    }

    else if (analogRead(A2) > 500) // if the IR sensor value is < 500 then the motor will start rotating
    {
      digitalWrite(led2, LOW);
      z1 = 0;
    }
    if (x1 * y1 * z1 == 1)
    {Serial.println("sorry !! parking space full");
      while (x1 * y1 * z1 == 1)
      {
        servo1.write(0);
        delay(60);
      }
    }
  }
}