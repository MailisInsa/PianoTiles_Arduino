#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"


#ifndef _BARRELED_H_
#define _BARRELED_H_

class BarreLED{
    protected:
    //une barre de LED comprend 4 cases
    uint64_t ligne[8];
    BarreLED* suivante;

    public:
    BarreLED(){}; //constructeur
    void FaireDefiler(){};
}


#endif