#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "TouchSensor_Copie.h"
#include "Ecran.h"
#include "ecranLED.h"
#include "grove_two_rgb_led_matrix.h"
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

class Game {
  protected:
    //Les différents boutons
    TouchSensorCopie _touch1{D5};
    TouchSensorCopie _touch2{D6};
    TouchSensorCopie _touch3{D7};
    TouchSensorCopie _touch4{D8};

    //L'écran d'affichage des messages de score et d'instructions
    Ecran _ecran;

    //Ecran LED pour l'affichage des cases à suivre
    EcranLED ecranLED;
    GroveTwoRGBLedMatrixClass matrix;

    //Compteur utilisé comme timer pour que le joueur appuie sur une touche dans un temps limité
    int compteur;

    //vecteurs utilisés pour modifier aléatoirement l'ordre d'allumage des cases
    std::vector<int> v3;
    std::vector<int> v5;
    
    //Variable correspondant au mode de difficulté
    int mode;

    //Score du joueur
    int Score;

    //Variable pour savoir si la matrice de LED affiche ou non des cases
    bool Affiche;
    
  public:
    //Booléen pour savoir si la partie est perdue
    bool Over;

    //Fonction pour l'initialisation du jeu
    void Init();

    //Fonction pour choisir le mode de difficulté
    void chooseMode();
    
    //Fonction pour terminer le jeu en cas de partie perdue
    int endGame();
};

#endif
