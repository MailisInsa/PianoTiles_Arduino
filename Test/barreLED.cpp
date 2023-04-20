#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"


BarreLED::BarreLED(){
    for(int i = 0; i<sizeof(ligne); i++){
        ligne[i] = new CaseLED();
    }
    ligne[0]->allumer(); //lignes pour tester
    ligne[2]->allumer();
    suivante = nullptr;
}
void BarreLED::FaireDefiler(){
    suivante->ligne[0] = this->ligne[0];
    suivante->ligne[1] = this->ligne[1];
    suivante->ligne[2] = this->ligne[2];
    suivante->ligne[3] = this->ligne[3];
}

CaseLED BarreLED::getLigne(int i){
    return(*ligne[i]);
}

BarreLED* BarreLED::getSuivante(){
    return(suivante);
}

void BarreLED::assignSuivante(BarreLED* b){
    this->suivante = b;
}
