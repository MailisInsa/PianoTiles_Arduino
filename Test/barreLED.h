#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"


#ifndef _BARRELED_H_
#define _BARRELED_H_

class BarreLED{
    protected:
    //une barre de LED comprend 4 cases
    CaseLED* ligne[4];
    BarreLED* suivante;

    public:
    BarreLED(); //constructeur
    CaseLED getLigne(int i);
    void FaireDefiler();
    BarreLED* getSuivante();
    void assignSuivante(BarreLED* b);
};


#endif
