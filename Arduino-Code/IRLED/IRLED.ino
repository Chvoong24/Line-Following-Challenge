#include <Servo.h>
Servo servoL;
Servo servoR;

int servoLpin = 0;
int servoRpin = 0;


int IRvalL= 0;
int IRvalR = 0;

int LEDpin = 10;

int threshL = 1020;
int threshR = 0;



void forward()
{
  servoL.writeMicroseconds(700);
  servoR.writeMicroseconds(2300);
}

void backward(double seconds)
{
  servoL.writeMicroseconds(2300);
  servoR.writeMicroseconds(700);
  delay(seconds * 1000);
  stop(0.5);
}


void pivotLeft(double seconds)
{
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(700);
  delay(seconds * 1000);
  stop(0.5);
}

void pivotRight()
{
  servoL.writeMicroseconds(2300);
  servoR.writeMicroseconds(1500);
  stop(0.5);
}

void sweepRight(double seconds)
{
  servoL.writeMicroseconds(2300);
  servoR.writeMicroseconds(1000);
  delay(seconds * 1000);
  stop(0.5);
}

void sweepLeft(double seconds)
{
  servoL.writeMicroseconds(1700);
  servoR.writeMicroseconds(700);
  delay(seconds * 1000);
  stop(0.5);
}

void stop(double seconds)
{
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1500);
  delay(seconds * 1000);
}


void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  servoL.attach(servoLpin); 
  servoR.attach(servoRpin);
}

void loop() {
  IRvalL = analogRead(/*Analog pin for left IR sensor*/ A1);
  IRvalR = analogRead(/*Analog pin for right IR sensor*/)
  // Serial.println(IRval);
  // delay(1);        
  // if (IRval < thresh){
  //   digitalWrite(LEDpin,1);
  //   Serial.println("White");
  //     }
  // else {
  //   digitalWrite(LEDpin,0);
  //   Serial.println("Black");
  // }

  while(IRValR < threshL && IRValR < threshR)
  {
    Forward();
  }

  while(IRvalL < threshL)
  {
    pivotRight();
  }

  while(IRValR < threshR)
  {
    pivotLeft();
  }

}