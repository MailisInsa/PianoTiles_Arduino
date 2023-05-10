#include "game.h"

Game game;

void setup() {
  game.setup();
}

void loop() {
  game.chooseMode();
  //Tant que pas"Game Over" et que on est dans mode =0 (mode easy)
  while (game.over != 1 && game.mode = 0) {
    game.updateGame();
  }
  game.endGame();
}
