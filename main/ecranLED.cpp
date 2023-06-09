#include "grove_two_rgb_led_matrix.h"
#include "ecranLED.h"
#include "barreLED.h"
#include "caseLED.h"


EcranLED::EcranLED(){
    for(int i = 0; i<sizeof(colonne); i++){
        colonne[i] = new BarreLED();
    }

    //Cette boucle for initialise le tableau de valeurs pour l'affichage
    for(int i=0; i<64; i=i+8){  
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i/8]->getLigne(j/2)->getMat1();
            tab[i+j+1] = colonne[i/8]->getLigne(j/2)->getMat2();
        }
    }
}

void EcranLED::Defiler(){
    for(int i = sizeof(colonne)-1; i>0; i--){
        colonne[i]->assignLigne(colonne[i-1]);
    }
}

uint64_t* EcranLED::getTab(){
    //On commence par mettre à jour le tab
    for(int i=0; i<64; i=i+8){  
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i/8]->getLigne(j/2)->getMat1();
            tab[i+j+1] = colonne[i/8]->getLigne(j/2)->getMat2();
        }
    }
    return(tab);
}

BarreLED* EcranLED::getDerniereColonne(){
    return(colonne[0]);
}

void EcranLED::EteintTout(){
    colonne[0]->getLigne(0)->eteindre();
    colonne[0]->getLigne(1)->eteindre();
    colonne[0]->getLigne(2)->eteindre();
    colonne[0]->getLigne(3)->eteindre();
}

void EcranLED::AllumerCase0(){
    colonne[0]->getLigne(0)->allumer();
}

void EcranLED::AllumerCase1(){
    colonne[0]->getLigne(1)->allumer();
}

void EcranLED::AllumerCase2(){
    colonne[0]->getLigne(2)->allumer();
}

void EcranLED::AllumerCase3(){
    colonne[0]->getLigne(3)->allumer();
}
