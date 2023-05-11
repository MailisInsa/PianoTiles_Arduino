#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"


#ifndef _ECRANLED_H_
#define _ECRANLED_H_

class EcranLED{
    protected:
    //un écran LED comprend 8 barres de LED
    BarreLED* colonne[8];
    uint8_t tab[64];

    public:
    EcranLED(); //constructeur
    uint8_t* getTab();
    BarreLED* getDerniereColonne();
    void AllumerCase();
    void Defiler();
    //void TESTDefiler();
    
    void AllumerCase0();
    void AllumerCase1();
    void AllumerCase2();
    void AllumerCase3();    
    
};


#endif
