#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
//#include matrix
#include "TouchSensor.h"
#include "Ecran.h"
#include "ecranLED.h"
#include "grove_two_rgb_led_matrix.h"

class Game {
  private:
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
    void updateGame();
    void endGame();
    void AfficheMat();
  //   // Redéfinition de l'opérateur d'assignation: Copie les membres: Utile pour crrer des variations deu jeu sans reinitialiser tous
  // GameDifficile& operator=(const GameDifficile& other) {
  //   // Vérifier l'auto-attribution
  //   if (this == &other) {
  //     return *this;
  //   }
    
  //   // Copier les membres de l'objet source vers l'objet courant
  //   // Assurez-vous de copier tous les membres nécessaires
    
  //   // Exemple de copie de membres
  //   this->_touch1 = other._touch1;
  //   this->_touch2 = other._touch2;
  //     this->_touch2 = other._touch2;
  //     this->_touch2 = other._touch2;
  //this -> _ecran = other._ecran;
  //  this -> ecranLED = other.ecranLED;
   // this -> matrix = other.matrix;
    
  //   // ...
    
  //   // Retourner l'objet courant
  //   return *this;
  // }
};

#endif
