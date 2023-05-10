#include <Arduino.h>
#include <U8g2lib.h>
#include "Ecran.h"
#include "Game.h"

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
Game game;
//Params
bool DBegin = 0;
bool DInGame = 0;
bool DEndGame = 1;
void loop(void) {.
  
//Welcome Display 
  ecran.EcranStart();
  ecran.EcranInGame(game.Score);
  ecran.EcranGameOver(game.Score);
  }

