#include "TouchSensor.h"
TouchSensor::TouchSensor(int pin){
  Pin = pin;
  buttonState = 0;
}

//Setup touchsensor correspondant a la broche, le mettre en mode INPUT
void TouchSensor :: setup() {
      pinMode(Pin, INPUT);
}
//Vérifier si le touchSensor est touché
bool TouchSensor :: Touched() {
      buttonState = digitalRead(Pin);

      if (buttonState == 1)  {
        return true;
      } else {
        return false;
      }
}
