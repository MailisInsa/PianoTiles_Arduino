#include "TouchSensor.h"
void TouchSensor :: setup() {
      pinMode(Pin1, INPUT);
      pinMode(Pin2, INPUT);
      pinMode(Pin3, INPUT);
      pinMode(Pin4, INPUT);
    }
bool TouchSensor :: Touched1() {
      buttonState = digitalRead(Pin1);

      if (buttonState == 1)  {
        return true;
      } else {
        return false;
      }
    }
bool TouchSensor :: Touched2() {
      
      buttonState1 = digitalRead(Pin2);

      if ( buttonState1 == 1 )  {
        return true;
      } else {
        return false;
      }
    }
bool TouchSensor :: Touched3() {

      buttonState2 = digitalRead(Pin3);


      if ( buttonState2 == 1 )  {
        return true;
      } else {
        return false;
      }
    }
bool TouchSensor :: Touched4() {

      buttonState3 = digitalRead(Pin4);

      if (buttonState3 == 1)  {
        return true;
      } else {
        return false;
      }
    }
