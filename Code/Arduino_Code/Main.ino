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
#include "usefulFunction.ino"
#include "libraries/QueueArray.h" https://playground.arduino.cc/Code/QueueArray#Download

#define PIN_LED 13

// Creates struct with paraeters loadcell (HX711), calibration factor (float),
// solenoidPWN(unsigned integer 8 digits),  tumberPositon (uint 1 digit).
// tumberPosition is the REVERSE of the order the ubttons are to be pushed
// (higher is pushed first), as pushing a button increase its and all prior
// pushed buttons tuber position by 1 when entering the combination.
typedef struct {
  HX711   loadCell,
  float   loadCell_calibrationFactor,
  uint8_t solenoidPWM
  uint1_t tumblerPosition
  float   pressure
} keyModule;

// Creates set of structs for each key, pins inputed.
// 7050 is from example code, 440 lb max scale set up, TODO CHANGE TO CORRECT VALUE
keyModule keyOne   = {HX711(1 ,  2), -7050.0, 3,  0, 0};
keyModule keyTwo   = {HX711(4 ,  5), -7050.0, 6,  0, 0};
keyModule keyThree = {HX711(7 ,  8), -7050.0, 9,  0, 0};
keyModule keyFour  = {HX711(12, 11), -7050.0, 10, 0, 0};
keyModule keyFive  = {HX711(14, 15), -7050.0, 16, 0, 0};
keyModule keys[]   = {keyOne, KeyTwo, keyThree, keyFour, keyFive};
// in tumblerOrder, first entry is the tumbler number of key 1,
// second is of key 2, etc.
int tumblerOrder[] = [0, 0, 0, 0, 0]

func findZeroTumblers(sticky, itNum){
  //finds all zero tumbler buttons when first testing a lock
  if sticky == 0{
      tumblerOrder[indexVal] = keys[indexVal].tumblerPosition
    } else {
      tumblerOrder[indexVal] += 1
    }
}

func getTumblersReady(){
  // presses buttons already found out, puts tumblers in position to test next button
  pressButtonCounter = 1
  bool buttonsLeftToPress = true
  uint1_t pressList[] = {0, 0, 0, 0, 0}

  while buttonsLeftToPress == true {
    if pressButtonCounter > 5{
      print("Error! Pressed more buttons than exist!")
      //flash LED 4 times?
    }
    for(uint8_t indexVal = 0; indexVal < sizeof(keys) / sizeof(keys[0]); indexVal++) {
      if pressButtonCounter = keys[indexVal].tumblerPosition{
        pressList[indexVal] = 1
      }
    }
    if pressList != {0, 0, 0, 0, 0} {
      //press buttons in list at same time
      pressList = {0, 0, 0, 0, 0}
    } else{
      buttonsLeftToPress = flase
    }
    pressButtonCounter += 1
  }
}

func testIfSticky(){
  //test other buttons, yields sticky = 1 if any are sticky

  //iterate over solenoids{
    if feedbackFromSolenoids > 1{
      sticky = 1
    } else{
    }
  //}
  return sticky
}

func feedbackFromSolenoids(){
  //This is just to act as a dummy func, will repalce with actual code
}

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
  int itNum = 0
  int keyToTest = 0
}

void loop() {
  // Solves the lock
  // -> Finds available buttons
  for(int index = 0; index < )
  // -> While we have not run out of buttons
  while() {

  }
  // Reports data
  while(1) {

  }
  //goes thorugh buttons, finds their tumbler positions
  if itNum > 5{
    print("Error! Couldn't put buttons into 6 tumbler positions")
    //flash LED 3 times?
  }
  for(uint8_t indexVal = 0; indexVal < sizeof(keys) / sizeof(keys[0]); indexVal++) {
    int sticky = 0
    getTumblersReady();
    sticky = testIfSticky();
    if itNum == 0{
      findZeroTumblers(sticky, itNum);
    } else if sticky == 1{
      tumberOrder[indexVal] = keys[indexVal].tumblerPosition;
    } else {
      keys[indexVal].tumblerPosition += 1;
    }
    itNum += 1
  }
  // implement reversing order found
