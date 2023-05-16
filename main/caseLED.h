#include "grove_two_rgb_led_matrix.h"

#ifndef _CASELED_H_
#define _CASELED_H_

class CaseLED{
    protected:
    //état de la case soit allume = true si LED allumée allume = false si éteinte
    bool allume;

    //Matrice contenant la couleur de chaque LED
    uint64_t LedMat[2];

    public:
    //Constructeur
    CaseLED();

    //Allumer une case donc les 2 LEDs
    void allumer();

    //Eteindre une case
    void eteindre();

    //Permet de connaitre l'état de la case LED
    bool EstAllume();

    //Permet d'obtenir la valeur de chacune des LED de la case
    uint64_t getMat1();
    uint64_t getMat2();
};


#endif
