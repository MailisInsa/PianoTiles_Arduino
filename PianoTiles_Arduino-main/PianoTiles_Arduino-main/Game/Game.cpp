#include "game.h"

void Game::setup() {
  _touch1.setup();
  _touch2.setup();
  _touch3.setup();
  _touch4.setup();
  _ecran.EcranStart();
  //LedMatrix
}

void Game::chooseMode() {
   bool touched1 = _touchSensor1.Touched1();
   bool touched2 = _touchSensor2.Touched2();
   if (touched1){
     mode = 0;
   }
   else if (touched2){
     mode = 1;
   }
}

void Game::updateGame() {
  // Code pour gérer le jeu en cours ici
  _ecran.EcranInGame(_score);
  bool touched1 = _touchSensor1.Touched1();
  bool touched2 = _touchSensor2.Touched2();
  bool touched3 = _touchSensor3.Touched3();
  bool touched4 = _touchSensor4.Touched4();

  // Vérifier si le joueur a appuyé sur le bon capteur tactile
  if (touched1 && _ledMatrix.LastLigne(0)) {
    Score++;
  } else if (touched2 && _ledMatrix.LastLigne(1)) {
    Score++;
  } else if (touched3 && _ledMatrix.LastLigne(2)) {
    Score++;
  } else if (touched4 && _ledMatrix.LastLigne(3)) {
    Score++;
  }
  else{
    Over = 1;
  }
}

void Game::endGame() {
  _ecran.EcranGameOver(_score);
}
