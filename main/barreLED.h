#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"

#ifndef _BARRELED_H_
#define _BARRELED_H_

class BarreLED{
    protected:
    //Une barre de LED comporte 4 Cases
    CaseLED* ligne[4]; 

    public:
    //Constructeur
    BarreLED(); 

    //Fonction permettant de hanger la valeur d'un ligne de LED
    void assignLigne(BarreLED* c);  

    //Fonction permettant de récupérer la valeur de la barre de LED
    CaseLED* getLigne(int i);       
};


#endif
