#include "TouchSensor_Copie.h"
TouchSensorCopie::TouchSensorCopie(int pin){
  Pin = pin;
  buttonState = 0;
}

//Setup touchsensor correspondant a chaque broche, les mettre en mode INPUT
void TouchSensorCopie :: setup() {
      pinMode(Pin, INPUT);
}
//Vérifier si le touchSensor est touché
bool TouchSensorCopie :: Touched() {
      buttonState = digitalRead(Pin);

      if (buttonState == 1)  {
        return true;
      } else {
        return false;
      }
}
