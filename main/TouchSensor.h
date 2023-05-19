#include <Arduino.h>

#ifndef _TOUCHSENSOR_H_
#define _TOUCHSENSOR_H_

class TouchSensor{
  private:
    //PIN of TouchSensor
    const int Pin1 = D5; 
    const int Pin2 = D6;
    const int Pin3 = D7;
    const int Pin4 = D8;
  
    //Var
    int buttonState = 0;
    int buttonState1 = 0;
    int buttonState2 = 0;
    int buttonState3 = 0;

  public:
    //Setup
    void setup();
    bool Touched1();
    bool Touched2();
    bool Touched3();
    bool Touched4();
};
#endif


