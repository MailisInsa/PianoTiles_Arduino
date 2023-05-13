#include "Game.h"

void Game::Init() {
  _touch1.setup();
  _touch2.setup();
  _touch3.setup();
  _touch4.setup();
  _ecran.EcranStart();
  Over = false;
  Score = 0;
  
  // Attendre jusqu'à ce qu'un des touch sensors soit activé
  bool isTouched = false;
  while (!isTouched) {
    if (_touch1.Touched1() || _touch2.Touched2() || _touch3.Touched3() || _touch4.Touched4()) {
      isTouched = true;
    }
    delay(1000); // Attendre 100 millisecondes avant de vérifier à nouveau
  }
  
  // Démarrer le jeu une fois qu'un touch sensor est activé
  //_ecran.EcranInGame(Score);
  
  //Initialisation de la LED matrix et des variables
  // ...
}

void Game::chooseMode() {
   bool touched1 = _touch1.Touched1();
   bool touched2 = _touch2.Touched2();
   if (touched1){
     mode = 0;
   }
   else if (touched2){
     mode = 1;
   }
}

void Game::updateGame() {
  // Code pour gérer le jeu en cours ici
 
  _ecran.EcranInGame(Score);
  bool touched1 = _touch1.Touched1();
  bool touched2 = _touch2.Touched2();
  bool touched3 = _touch3.Touched3();
  bool touched4 = _touch4.Touched4();

  // Vérifier si le joueur a appuyé sur le bon capteur tactile
  if (touched1) {
    Score++;
  } else if (touched2) {
    Score++;
  } else if (touched3) {
    Score++;
  } else if (touched4 ) {
    Score++;
  }
  else{
  Over = true;
}
}
void Game::endGame() {
  _ecran.EcranGameOver(Score);
}
