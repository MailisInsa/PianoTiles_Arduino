#include "grove_two_rgb_led_matrix.h"

#ifndef _CASELED_H_
#define _CASELED_H_

class CaseLED{
    protected:
    //état de la case soit allume = true si LED allumée allume = false si éteinte
    bool allume;
    uint8_t LedMat[2];

    public:
    CaseLED(); //constructeur
    void allumer(); //fonction pour allumer la case
    void eteindre(); //fonction pour éteindre la case
    bool EstAllume(); //méthode pour connaître l'état de la LED
    uint8_t getMat1();
    uint8_t getMat2();
};


#endif
