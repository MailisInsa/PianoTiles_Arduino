#ifndef GAMEDIFFICILE_H
#define GAMEDIFFICILE_H


#include "Game.h"


class GameDifficile:public Game{
  public:
  //Fonction pour la mise à jour du score
  void updateGame();

  //Fonction pour la mise à jour des cases de LED
  void AfficheMat();
};

#endif
