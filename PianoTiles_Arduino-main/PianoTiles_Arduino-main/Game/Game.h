#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
//#include matrix
#include "touchsensor.h"
#include "ecran.h"

class Game {
  private:
    TouchSensor _touch1;
    TouchSensor _touch2;
    TouchSensor _touch3;
    TouchSensor _touch4;
    Ecran _ecran;
    

  public:
    int mode;
    int Score
    bool Over;
    void setup();
    void chooseMode();
    void updateGame();
    void endGame();
};

#endif

