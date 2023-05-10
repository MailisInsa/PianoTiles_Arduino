#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"


#ifndef _ECRANLED_H_
#define _ECRANLED_H_

class EcranLED{
    protected:
    //un écran LED comprend 8 barres de LED
    BarreLED* colonne[8];
    uint64_t tab[64];

    public:
    EcranLED(); //constructeur
    uint64_t* getTab();
    BarreLED* getDerniereColonne();
    void AllumerCase();
    void Defiler();
};


#endif
