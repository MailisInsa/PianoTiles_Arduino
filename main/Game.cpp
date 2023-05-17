#include "Game.h"

void Game::Init() {
  _touch1.setup();
  _touch2.setup();
  _touch3.setup();
  _touch4.setup();
  _ecran.EcranStart();
  Over = false;
  Affiche = false;
  Score = 0;
  compteur = 0;
  
  
  // Attendre jusqu'à ce qu'un des touch sensors soit activé
  // Démarrer le jeu une fois qu'un touch sensor est activé
  bool isTouched = false;
  while (!isTouched) {
    if (_touch1.Touched1() || _touch2.Touched2() || _touch3.Touched3() || _touch4.Touched4()) {
      isTouched = true;
    }
    delay(1000); // Attendre 100 millisecondes avant de vérifier à nouveau
  } 
}

//Choisir le mode de jeu: Facile ou Difficile
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
 


int Game::endGame() {
  try{
    _ecran.EcranGameOver(Score);
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() <<std::endl;
    return -1; //va peut-être planter parce que cette fonction ne retourne rien
  }
  return 0;
}





