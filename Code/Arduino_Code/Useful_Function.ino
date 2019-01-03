/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
-* File: usefulFunction.ino
-* ------------------------------
-* Author: Luke Blankenberg, Erick Blankenberg
-* Date:   1/2/2019
-*
-* Description:
-*  This file contains functions used in the main file
\*///////////////////////////////////////////////////////

//commented out, dont want redundent code, will be updated later
#include "libraries/HX711.h"
#include "Main.ino"

#define PIN_LED 13

void findZeroTumblers(indexVal){
  //finds all zero tumbler buttons when first testing a lock
  if sticky[indexVal] == 0{
      tumblerOrder[indexVal] = keys[indexVal].tumblerPosition
    } else {
      tumblerOrder[indexVal] += 1
    }
}

void getTumblersReady(){
  // presses buttons already found out, puts tumblers in position to test next button
  int pressButtonCounter = 1
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

void testForSticky(){
  //test other buttons, yields sticky = 1 if any are sticky
  /*
  for(uint8_t indexVal = 0; indexVal < sizeof(sticky) / sizeof(sticky[0]); indexVal++) {
    if feedbackFromSolenoids > 1{
      sticky[index] = 1
    } else{
      
    }
  }
  return sticky
} */

void feedbackFromSolenoids(){
  //This is just to act as a dummy func, will repalce with actual code
}

bool testForOtherSticky(int testVal){
  for(uint8_t indexVal = 0; indexVal < sizeof(sticky) / sizeof(sticky[0]); indexVal++) {
    if testVal != indexval and sticky[indexVal] != 0{
      return true
    }
  }
  return false
}
