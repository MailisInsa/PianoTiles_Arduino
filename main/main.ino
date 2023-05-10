#include "Game.h"
#include "TouchSensor.h"
#include "Ecran.h"

Game game;
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
void setup() {
  
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  game.Init();
  game.chooseMode();
  //Tant que pas"Game Over" et que on est dans mode =0 (mode easy)
  while (game.Over != 1) {
    if (game.mode == 0){
    game.updateGame();
  }
  game.endGame();
}}
