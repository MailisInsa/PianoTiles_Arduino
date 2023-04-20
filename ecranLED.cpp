#include "EcranLED.h"


EcranLED::EcranLED(){
    for(int i = 0; i<sizeof(colonne)-1; i++){
        colonne[i+1]->suivante = colonne[i];
    }
    colonne[6]->suivante = colonne[7];
    for(int i=0; i<64; i=i+8){
        for(int j=0; j<8; j=j+2){
            tab[i+j] = colonne[i].ligne[j].getMat1();
            tab[i+j+1] = colonne[i].ligne[j].getMat2();
        }
    }
}




