#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"
#include <random>


BarreLED::BarreLED(){
    for(int i = 0; i<sizeof(ligne); i++){
        ligne[i] = new CaseLED();
    }
    ligne[0]->allumer(); //lignes pour tester
    ligne[2]->allumer();
    //suivante = nullptr;
}

void BarreLED::FaireDefiler(){
    suivante->ligne[0] = ligne[0];
    suivante->ligne[1] = ligne[1];
    suivante->ligne[2] = ligne[2];
    suivante->ligne[3] = ligne[3];
}

CaseLED* BarreLED::getLigne(int i){
    return(ligne[i]);
}

BarreLED* BarreLED::getSuivante(){
    return(suivante);
}

void BarreLED::assignSuivante(BarreLED* b){
    this->suivante = b;
}

void BarreLED::AllumerCaseRandom(){
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0,3);
    //on commence par éteindre les autres cases
    for(int i=0; i<4; i++){
        ligne[i]->eteindre();
    }
    //on allume une case random
    ligne[distr(eng)]->allumer();
}
