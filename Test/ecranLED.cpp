#include "grove_two_rgb_led_matrix.h"
#include "ecranLED.h"
#include "barreLED.h"
#include "caseLED.h"


EcranLED::EcranLED(){
    colonne[0] = new BarreLED();
    for(int i = 1; i<sizeof(colonne); i++){
        colonne[i] = new BarreLED();
        colonne[i-1]->assignSuivante(colonne[i]);
    }
    
    colonne[5]->getLigne(1).allumer();

    //cette boucle for initialise le tab
    for(int i=0; i<64; i=i+8){  
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i/8]->getLigne(j/2).getMat1();
            tab[i+j+1] = colonne[i/8]->getLigne(j/2).getMat2();
        }
    }
}

uint64_t* EcranLED::getTab(){
    for(int i=0; i<64; i=i+8){  
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i/8]->getLigne(j/2).getMat1();
            tab[i+j+1] = colonne[i/8]->getLigne(j/2).getMat2();
        }
    }
    return(tab);
}

BarreLED* EcranLED::getDerniereColonne(){
    return(colonne[7]);
}

void EcranLED::AllumerCase(){
    colonne[0]->AllumerCaseRandom();
}

void EcranLED::Defiler(){
    for(int i = sizeof(colonne)-1; i>0; i--){
        colonne[i-1]->FaireDefiler();
    }
}
