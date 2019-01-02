/*
 * File: Main.ino
 * ------------------------------
 * Author: Luke Blankenberg, Erick Blankenberg
 * Date:   1/2/2019
 *
 * Description:
 *  This program controls the KeyKruncher lock destroyer.
 */
#include "libraries/HX711.h"

typedef struct {
  HX711   loadCell,
  uint8_t solenoidPWM
} keyModule;

keyModule keyOne   = {HX711(1 ,  2),  3};
keyModule keyTwo   = {HX711(4 ,  5),  6};
keyModule keyThree = {HX711(7 ,  8),  9};
keyModule keyFour  = {HX711(12, 11), 10};
keyModule keyFive  = {HX711(14, 15), 16};

keyModule keys[] = {keyOne, KeyTwo, keyThree, keyFour, keyFive};

void setup() {
    for(uint8_t indexVal = 0; indexVal < sizeof(keys) / sizeof(keys[0]))
}

void loop() {
  // put your main code here, to run repeatedly:
  //get name of input
  //is input > current value
  //if greater replace, if not do nothing
  //if value suddenly drops off, stop, go to next input
}
