#include <Arduino.h>

#ifndef _TOUCHSENSOR_H_
#define _TOUCHSENSOR_H_

class TouchSensor{
  private:
    //PIN of TouchSensor
    int Pin;
    //Var
    int buttonState = 0;

  public:
    TouchSensor(int pin);
    //Setup
    void setup();
    bool Touched();
};
#endif


