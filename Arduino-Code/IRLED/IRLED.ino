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

int threshL = 970;
int threshR = 600;
int threshMid = 80;

bool whiteLeft = false;
bool whiteRight = false;
bool blackMiddle = true;

bool oscillatingRight = true; 


// Movement functions for the robot
void forward(int xDelay) {
  servoL.writeMicroseconds(1700); 
  servoR.writeMicroseconds(1300); 
  delay(xDelay);
}

void pivotLeft(int xDelay) {
  servoL.writeMicroseconds(1500); 
  servoR.writeMicroseconds(1100); 
  delay(xDelay);
}

void pivotRight(int xDelay) {
  servoL.writeMicroseconds(1700);
  servoR.writeMicroseconds(1800); 
  delay(xDelay);
}

void sweepRight(int xDelay) {
  servoL.writeMicroseconds(1650);
  servoR.writeMicroseconds(1400); 
  delay(xDelay);
}

void sweepLeft(int xDelay) {
  
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1300);
  delay(xDelay);
}

void stop(int xDelay) {
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
  IRvalL = analogRead(A0);
  IRvalR = analogRead(A5);
  photoSensorVal = analogRead(A4);
 // Serial.println(IRvalL); 

  if (IRvalL < threshL){
    Serial.println("LEFT WHITE");
        whiteLeft = true;
      }
  else {
    Serial.println("LEFT BLACK");
    whiteLeft = false;
  }
  // Serial.println(IRvalR); 

Serial.println(IRvalR);
  if(IRvalR < threshR){
    Serial.println("RIGHT WHITE");
    whiteRight = true;
      }
  else {
   Serial.println("RIGHT BLACK");
    whiteRight = false;
     }

//Serial.println(photoSensorVal);

  if(photoSensorVal > threshMid)
  {
    Serial.println("Middle White");
    blackMiddle = false;
  }
  else
  {
    Serial.println("Middle Black");
    blackMiddle = true;
  }

if (blackMiddle) {
    // If the middle sensor detects black, oscillate between left and right
    if (oscillatingRight) {
      sweepRight(10);  // Shorter delay for faster oscillation
      oscillatingRight = false;  // Next time, oscillate left
    } else {
      sweepLeft(10);   // Shorter delay for faster oscillation
      oscillatingRight = true;   // Next time, oscillate right
    }
    forward(5); // Shorter forward movement for quicker oscillation
  } else {
    // If middle sensor detects white, correct course based on side sensors
    if (!whiteLeft && whiteRight) {
      pivotLeft(30);  // Pivot left to correct
    } else if (whiteLeft && !whiteRight) {
      pivotRight(30); // Pivot right to correct
    } else {
      stop(30);  // If unsure, stop and re-evaluate
    }
  }


//  // Adjust robot's movement to ensure the middle sensor is always on black
//   if (blackMiddle) {
//     // If middle sensor is on black, adjust based on side sensors
//     if (whiteLeft && whiteRight) {
//       forward(30);  // Move straight if both sides are white and middle is black
//     } else if (!whiteLeft && whiteRight) {
//       sweepLeft(30);  // If left is on black and right on white, adjust left
//     } else if (whiteLeft && !whiteRight) {
//       sweepRight(30);  // If right is on black and left on white, adjust right
//     } else {
//       forward(30);  // Default to moving forward if middle is on black
//     }
//   } else {
//     // If middle sensor is not on black, make adjustments to correct course
//     if (!whiteLeft && whiteRight) {
//       pivotLeft(30);  // If left is black, pivot left to get back on the line
//     } else if (whiteLeft && !whiteRight) {
//       pivotRight(30); // If right is black, pivot right to get back on the line
//     } else {
//       stop(30);       // If no clear direction, stop and re-evaluate
//     }
//   }

  
}