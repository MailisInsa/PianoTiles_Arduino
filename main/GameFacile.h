#ifndef GAMEFACILE_H
#define GAMEFACILE_H

#include "Game.h"


class GameFacile:public Game{
  public:
  //Fonction pour la mise à jour du Score
  void updateGame();

  //Fonction pour la mise à jour des cases de LED
  void AfficheMat();
};

#endif
