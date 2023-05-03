#include <Arduino.h>
#include <U8g2lib.h>
#include "Ecran.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
void setup() {
  // Your setup code goes here
}
Ecran ecran;
//Params
bool DBegin = 0;
bool DInGame = 0;
bool DEndGame = 1;
int Score = 13;
void loop(void) {
  
//Welcome Display 
  ecran.EcranStart();
  ecran.EcranInGame(Score);
  ecran.EcranGameOver(Score);
  }

