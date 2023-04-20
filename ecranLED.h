
#include "BarreLED.h"


#ifndef _ECRANLED_H_
#define _ECRANLED_H_

class EcranLED{
    protected:
    //un écran LED comprend 8 barres de LED
    BarreLED colonne[8];
    uint8_t tab[64];

    public:
    EcranLED(){}; //constructeur
}


#endif