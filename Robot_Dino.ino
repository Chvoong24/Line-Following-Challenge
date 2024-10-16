#include <Servo.h>
#include <stdbool.h>
Servo servoL;
Servo servoR;

int servoLpin = 6;
int servoRpin = 7;


int IRvalL;
int IRvalR;
int photoSensorVal;

// int LEDpin = 10;

int threshL = 150;
int threshR = 300;

bool whiteLeft = false;
bool whiteRight = false;




void forward(int xDelay)
{
  servoL.writeMicroseconds(1600);
  servoR.writeMicroseconds(1400);
  delay(xDelay);
}

void backward(int xDelay)
{
  servoL.writeMicroseconds(2300);
  servoR.writeMicroseconds(700);
  delay(xDelay);
}


void pivotLeft(int xDelay)
{
  servoL.writeMicroseconds(1400);
  servoR.writeMicroseconds(1300);
  delay(xDelay);
}

void pivotRight(int xDelay)
{
  servoL.writeMicroseconds(1600);
  servoR.writeMicroseconds(1700);
  delay(xDelay);
}

void sweepRight(int xDelay)
{
  servoL.writeMicroseconds(1650);
  servoR.writeMicroseconds(1460);
  delay(xDelay);
}

void sweepLeft(int xDelay)
{
  servoL.writeMicroseconds(1530);
  servoR.writeMicroseconds(1400);
  delay(xDelay);
}

void stop(int xDelay)
{
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1500);
  delay(xDelay);
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
  //photoSensorVal = analogRead(A4);
  //delay(40);  
  //Serial.println("LEFT VAL");
  Serial.println(IRvalL); 


  if (IRvalL > threshL){
    Serial.println("LEFT WHITE");
        whiteLeft = true;
      }
  else {
    Serial.println("LEFT BLACK");
    whiteLeft = false;
  }

  //Serial.println("RIGHT VAL");
  //Serial.println(IRvalR); 
  
  if(IRvalR < threshR){
    //Serial.println("RIGHT WHITE");
    whiteRight = true;
      }
  else {
    //Serial.println("RIGHT BLACK");
    whiteRight = false;
  }

  if(whiteLeft == true && whiteRight == true || whiteLeft == false && whiteRight == false)
  {
    forward(30);
  }
  else if(whiteLeft == false && whiteRight == true)
   {
      pivotLeft(30);
    // pivotLeft();
   }

   else if(whiteLeft == true && whiteRight == false)
 {
    pivotRight(30);
    // pivotRight();
  }

}