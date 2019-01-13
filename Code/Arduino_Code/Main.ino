/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
-* File: Main.ino
-* ------------------------------
-* Author: Luke Blankenberg, Erick Blankenberg
-* Date:   1/2/2019
-*
-* Description:
-*  This program controls the KeyKruncher lock destroyer.
-*  Attempts clever algorythms
\*///////////////////////////////////////////////////////

#include "libraries/HX711.h"
#include "usefulFunction.ino"

#define PIN_LED     13

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
// 7050 is from example code, 440 lb max scale set up, CHANGE TO CORRECT VALUE
keyModule keyOne   = {HX711(1 ,  2), -7050.0, 3,  0, 0};
keyModule keyTwo   = {HX711(4 ,  5), -7050.0, 6,  0, 0};
keyModule keyThree = {HX711(7 ,  8), -7050.0, 9,  0, 0};
keyModule keyFour  = {HX711(12, 11), -7050.0, 10, 0, 0};
keyModule keyFive  = {HX711(14, 15), -7050.0, 16, 0, 0};
keyModule keys[]   = {keyOne, KeyTwo, keyThree, keyFour, keyFive};
const uint8_t NUM_BUTTONS = sizeof(keys) / sizeof(keys[0]);

QueueArray<uint8_t> findHardKeys() {
  QueueArray<uint8_t> stickyIndexes;
  for(int index = 0; index < NUM_BUTTONS; index++) {
    // TODO do test procedure here.
    bool isSticky = false;
    if(isSticky) {
      stickyIndexes.enqueue(index);
    }
  }
  return stickyIndexes;
}

void getTumblersReady(uint8_t[NUM_BUTTONS, NUM_BUTTONS] lastPath) {

}

void setup() {
  // Sets up solenoid pins
  for(uint8_t indexVal = 0; indexVal < NUM_BUTTONS; indexVal++) {
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
  uint8_t tumblerPositions[NUM_BUTTONS] = {0};
  // -> While we have not run out of buttons
  uint8_t solutionArray[NUM_BUTTONS, NUM_BUTTONS] = {NULL_BUTTON};
  for(uint8_t step = 0; step < NUM_BUTTONS; step++) {
    QueueArray<uint8_t> resultedInSticky;
    QueueArray<uint8_t> wasNotSticky;
    getTumblersReady(solutionArray);
  }
  // Reports data
  while(1) {
    for(uint8_t step = 0; step < NUM_BUTTONS; step++) {
      for(uint8_t index = 0; index < NUM_BUTTONS; index++) {

      }
    }
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }











  //goes thorugh buttons, finds their tumbler positions
  if itNum > 5{
    print("Error! Couldn't put buttons into 6 tumbler positions")
    //flash LED 3 times?
  }
  for(uint8_t indexVal = 0; indexVal < sizeof(keys) / sizeof(keys[0]); indexVal++) {
    int sticky = 0
    getTumblersReady();
    findHardKeys();
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
