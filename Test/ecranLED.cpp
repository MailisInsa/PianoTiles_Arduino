#include "grove_two_rgb_led_matrix.h"
#include "ecranLED.h"
#include "barreLED.h"
#include "caseLED.h"


EcranLED::EcranLED(){
    for(int i = 0; i<sizeof(colonne); i++){
        colonne[i] = new BarreLED();
    }
    for(int i = 0; i<sizeof(colonne)-1; i++){
        colonne[i+1]->assignSuivante(colonne[i]);
    }
    colonne[6]->assignSuivante(colonne[7]);



    //cette boucle for empêche la bonne création d'un objet ecran 
    for(int i=0; i<64; i=i+8){  
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i/8]->getLigne(j/2).getMat1();
            tab[i+j+1] = colonne[i/8]->getLigne(j/2).getMat2();
        }
    }


    
}

uint64_t* EcranLED::getTab(){
    return(tab);
}
