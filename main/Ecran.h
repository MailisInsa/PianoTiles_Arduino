#include <Arduino.h>
#include <U8g2lib.h>
#include <stdexcept>
#include <iostream>

#ifndef _ECRAN_H_
#define _ECRAN_H_

class Ecran{
  public:
    void EcranStart();
    void EcranInGame(int Score);
    void EcranGameOver(int Score);
};

#endif
