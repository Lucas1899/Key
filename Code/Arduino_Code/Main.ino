/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
-* File: Main.ino
-* ------------------------------
-* Author: Luke Blankenberg, Erick Blankenberg
-* Date:   1/2/2019
-*
-* Description:
-*  This program controls the KeyKruncher lock destroyer.
\*///////////////////////////////////////////////////////

#include "libraries/HX711.h"

#define PIN_LED 13

// Creates struct with paraeters loadcell (HX711), calibration factor (float),
// solenoidPWN(unsigned integer 8 digits)
typedef struct {
  HX711   loadCell,
  float   loadCell_calibrationFactor,
  uint8_t solenoidPWM
} keyModule;

// Creates set of structs for each key, pins inputed.
// 7050 is from example code, 440 lb max scale set up, TODO CHANGE TO CORRECT VALUE
keyModule keyOne   = {HX711(1 ,  2), -7050.0, 3 };
keyModule keyTwo   = {HX711(4 ,  5), -7050.0, 6 };
keyModule keyThree = {HX711(7 ,  8), -7050.0, 9 };
keyModule keyFour  = {HX711(12, 11), -7050.0, 10};
keyModule keyFive  = {HX711(14, 15), -7050.0, 16};
keyModule keys[]   = {keyOne, KeyTwo, keyThree, keyFour, keyFive};

void setup() {
  // Sets up solenoid pins
  for(uint8_t indexVal = 0; indexVal < sizeof(keys) / sizeof(keys[0]); indexVal++) {
    pinMode(keys[indexVal].solenoidPWM, OUTPUT);
    analogWrite(keys[indexVal].solenoidPWM, 0);
    keys[indexVal].loadCell.tare();
    keys[indexVal].loadCell.set_scale(keys[indexVal].loadCell_calibrationFactor);
  }

  // Sets up basic IO
  // -> Serial
  Serial.begin(9600);
  // -> LED
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);
}

void loop() {

  //get name of input
  //is input > current value
  //if greater replace, if not do nothing
  //if value suddenly drops off, stop, go to next input
}
