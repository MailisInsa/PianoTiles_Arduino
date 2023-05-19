#include "Game.h"

void Game::Init() {
  //Initialisation des variables
  _touch1.setup();
  _touch2.setup();
  _touch3.setup();
  _touch4.setup();
  _ecran.EcranStart();
  Over = false;
  Affiche = false;
  Score = 0;
  compteur = 0;
  for(int i=0; i<4; i++)
    v3.push_back(i);
  
  for(int i=0; i<6; i++)
    v5.push_back(i);

  // Attendre jusqu'à ce qu'un des touch sensors soit activé
  // Démarrer le jeu une fois qu'un touch sensor est activé
  bool isTouched = false;
  while (!isTouched) {
    if (_touch1.Touched() || _touch2.Touched() || _touch3.Touched() || _touch4.Touched()) {
      isTouched = true;
    }
    delay(1000); // Attendre 1000 millisecondes avant de vérifier à nouveau
  } 
}

//Choisir le mode de jeu: Facile ou Difficile
void Game::chooseMode() {
   bool touched1 = _touch1.Touched();
   bool touched2 = _touch2.Touched();
   if (touched1){
     mode = 0;
   }
   else if (touched2){
     mode = 1;
   }
}


int Game::endGame() {
  //Exception si jamais le score du joueur est négatif
  try{
    _ecran.EcranGameOver(Score);
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() <<std::endl;
    return -1;
  }
  return 0;
}





