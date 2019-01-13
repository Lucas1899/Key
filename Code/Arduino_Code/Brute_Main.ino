/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
-* File: Brute)Main.ino
-* ------------------------------
-* Author: Luke Blankenberg
-* Date:   1/12/2019
-*
-* Description:
-*  This program controls the KeyKruncher lock destroyer.
-*  Brute combinations
\*///////////////////////////////////////////////////////

#include "libraries/HX711.h"
#include "Servo.h"

#define PIN_LED     13


Servo keyOne;
Servo keyTwo;
Servo keyThree;
Servo keyFour;
Servo keyFive;
Servo keyLatch;
Servo keys[] = {keyOne, KeyTwo, keyThree, keyFour, keyFive, keyLatch};
const uint8_t NUM_BUTTONS = sizeof(keys) / sizeof(keys[0]);


void setup() {
  keyOne.attach(3);
  keyTwo.attach(5);
  keyThree.attach(6);
  keyFour.attach(9);
  keyFive.attach(10);
  keyLatch.attach(11);
}

void loop() {
  // goes through all combos
  for(int a = 0; a = 5; a++) {
    for(int b = 0; b = 5; b++) {
      for(int c = 0; c = 5; c++) {
        for(int d = 0; d = 5; d++) {
          for(int e = 0; e = 5; e++) {
            // check that there are no gaps in combo
            // (can't go from first buttons to third buttons)
            int loopList[] = [a, b, c, d, e];
            bool fine = false;
            bool lock = false;
            for(int index = 0; index < sizeof(keys) / sizeof(keys[0]); index++){
              // check that no gaps exist, all 0's fine as do nothing and then skip
              if loopList[index] >= 1 {
                // check that every number >= 1 has something right below it, no gaps
                for(int test = 0; test < sizeof(keys) / sizeof(keys[0]); test++){
                  if loopList[test] == loopList[index - 1]{
                    fine = true;
                    // lock makes it that once get that something is below, then it is fine
                    lock = true;
                  } else if lock == false{
                    fine = false;
                  }
                }
                lock = false;
              } else {
                // skip
              }
            }
            if fine == false {
              // skip combo, has gaps
            } else {
              // go thorugh sequence of pushing buttons
              bool doneYet = false;
              for(int counter = 0; counter = 5: counter++){
                // check if sequence done (if did none on last entry,
                // must be done as there are no gaps)
                if doneYet == false{
                  bool gotOne = false;
                  for(int index = 1; index < sizeof(keys) / sizeof(keys[0]); index++) {
                    if loopList[index] == counter and loopList[index] != 0 {
                      keys[index].write(45);
                      gotOne = true;
                    }
                  }
                  delay(30);
                  // set them back once pressed
                  for(int index = 0; index < sizeof(keys) / sizeof(keys[0]); index++) {
                    if loopList[index] == counter {
                      keys[index].write(0);
                    }
                  }
                  if gotOne = false {
                    doneYet = true;
                  }
                }
              }
              keys[5].write(180);
              delay(30);
              keys[5].write(0);
              // find some way to check if turned all the way, if so then stop
            }
          }
        }
      }
    }
  }
}
