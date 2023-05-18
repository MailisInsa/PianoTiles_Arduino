#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "TouchSensor.h"
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
    TouchSensor _touch1;
    TouchSensor _touch2;
    TouchSensor _touch3;
    TouchSensor _touch4;

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

  public:
    //Variable correspondant au mode de difficulté
    int mode;

    //Score du joueur
    int Score;

    //Booléen pour savoir si la partie est perdue
    bool Over;

    //Variable pour savoir si la matrice de LED affiche ou non des cases
    bool Affiche;

    //Fonction pour l'initialisation du jeu
    void Init();

    //Fonction pour choisir le mode de difficulté
    void chooseMode();
    
    //Fonction pour terminer le jeu en cas de partie perdue
    int endGame();
};

#endif
