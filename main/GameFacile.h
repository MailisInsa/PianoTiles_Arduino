#ifndef GAMEFACILE_H
#define GAMEFACILE_H

#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;

class GameFacile:public Game{
  public:
  void updateGame();
  void AfficheMat();
};

#endif
