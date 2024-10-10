#include <Servo.h>
#include <stdbool.h>
Servo servoL;
Servo servoR;

int servoLpin = 6;
int servoRpin = 7;


int IRvalL;
int IRvalR;

// int LEDpin = 10;

int threshL = 600;
int threshR = 100;



void forward()
{
  // delay(10);
  servoL.writeMicroseconds(1600);
  servoR.writeMicroseconds(1400);
  // delay(20);
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
  servoL.writeMicroseconds(1400);
  servoR.writeMicroseconds(1500);
  delay(20);
}

void pivotRight()
{
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1600);
  delay(20);
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
  delay(40);  
  // Serial.println("LEFT VAL");
  // Serial.println(IRvalL); 


  if (IRvalL < threshL){
    Serial.println("LEFT WHITE");

      }
  else {
    Serial.println("LEFT BLACK");
  }

  // Serial.println("RIGHT VAL");
  // Serial.println(IRvalR); 
  
  if(IRvalR < threshR){
    Serial.println("RIGHT WHITE");
      }
  else {
    Serial.println("RIGHT BLACK");
  }

  if(IRvalR < threshL && IRvalR < threshR)
  {
    forward();
    // IRvalL = analogRead(/*Analog pin for left IR sensor*/ A4);
    // IRvalR = analogRead(/*Analog pin for right IR sensor*/A5);

  }

  else if(IRvalL < threshL)
   {
     pivotRight();
    //  IRvalL = analogRead(/*Analog pin for left IR sensor*/ A4);
   }

   else if(IRvalR < threshR)
 {
    pivotLeft();
    //  IRvalR = analogRead(/*Analog pin for right IR sensor*/A5);
  }

}