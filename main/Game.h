#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
//#include matrix
#include "TouchSensor.h"
#include "Ecran.h"
#include "ecranLED.h"
#include "grove_two_rgb_led_matrix.h"
#include <stdexcept>

class Game {
  protected:
    TouchSensor _touch1;
    TouchSensor _touch2;
    TouchSensor _touch3;
    TouchSensor _touch4;
    Ecran _ecran;
    EcranLED ecranLED;
    GroveTwoRGBLedMatrixClass matrix;
    int compteur;

    

  public:
    int mode;
    int Score;
    bool Over;
    bool Affiche;
    void Init();
    void chooseMode();
    //void updateGame();
    void endGame();
    //void AfficheMat();
};

class GameDifficile:public Game{
  public:
  void updateGame();
  void AfficheMat();
};

class GameFacile:public Game{
  public:
  void updateGame();
  void AfficheMat();
};

#endif
