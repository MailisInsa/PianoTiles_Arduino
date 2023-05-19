#include <Arduino.h>

#ifndef _TOUCHSENSORCOPIE_H_
#define _TOUCHSENSORCOPIE_H_

class TouchSensorCopie{
  private:
    //PIN of TouchSensor
    int Pin;
    //Var
    int buttonState = 0;

  public:
    TouchSensorCopie(const int pin);
    //Setup
    void setup();
    bool Touched();
};
#endif


