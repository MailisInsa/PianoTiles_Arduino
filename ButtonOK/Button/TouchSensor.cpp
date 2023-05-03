#include "TouchSensor.h"
void TouchSensor :: setup() {
      pinMode(Pin1, INPUT);
      pinMode(Pin2, INPUT);
      pinMode(Pin3, INPUT);
      pinMode(Pin4, INPUT);
    }
bool TouchSensor :: Touched() {
      buttonState = digitalRead(Pin1);
      buttonState1 = digitalRead(Pin2);
      buttonState2 = digitalRead(Pin3);
      buttonState3 = digitalRead(Pin4);

      if (buttonState == 1 || buttonState1 == 1 || buttonState2 == 1 || buttonState3 == 1)  {
        return true;
      } else {
        return false;
      }
    }

