#include <Servo.h>
Servo servoL;
Servo servoR;

int servoLpin = 6;
int servoRpin = 7;


int IRvalL;
int IRvalR;

// int LEDpin = 10;

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


void pivotLeft()
{
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(800);
}

void pivotRight()
{
  servoL.writeMicroseconds(2200);
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
  // pinMode(LEDpin, OUTPUT);
  servoL.attach(servoLpin); 
  servoR.attach(servoRpin);
}

void loop() {
  IRvalL = analogRead(/*Analog pin for left IR sensor*/ A4);
  IRvalR = analogRead(/*Analog pin for right IR sensor*/A5);
  delay(20);  
  Serial.println("LEFT VAL");
  Serial.println(IRvalL);      
  if (IRvalL < threshL){
    Serial.println("LEFT White");
      }
  else {
    Serial.println("LEFT Black");
  }

  Serial.println("RIGHT VAL");
  Serial.println(IRvalR); 
  
  if(IRvalR < threshR){
    Serial.println("RIGHT White");
      }
  else {
    Serial.println("RIGHT Black");
  }

  while(IRvalR < threshL && IRvalR < threshR)
  {
    forward();
    IRvalL = analogRead(/*Analog pin for left IR sensor*/ A4);
    IRvalR = analogRead(/*Analog pin for right IR sensor*/A5);

  }

  while(IRvalL < threshL)
   {
     pivotRight();
       IRvalL = analogRead(/*Analog pin for left IR sensor*/ A4);
   }

   while(IRvalR < threshR)
 {
    pivotLeft();
     IRvalR = analogRead(/*Analog pin for right IR sensor*/A5);
  }

}