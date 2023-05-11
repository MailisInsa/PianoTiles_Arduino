#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"
#include <random>


#ifndef _BARRELED_H_
#define _BARRELED_H_

class BarreLED{
    protected:
    //une barre de LED comprend 4 cases
    CaseLED* ligne[4];
    BarreLED* suivante;

    public:
    BarreLED(); //constructeur
    void assignLigne(BarreLED* c);
    CaseLED* getLigne(int i);
    void FaireDefiler();
    BarreLED* getSuivante();
    void assignSuivante(BarreLED* b);
    void AllumerCaseRandom();       //fonction pour allumer l'une des cases aléatoirement
};


#endif
