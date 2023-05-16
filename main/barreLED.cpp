#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"


BarreLED::BarreLED(){
    for(int i = 0; i<4; i++){
        ligne[i] = new CaseLED();
    }
}

void BarreLED::assignLigne(BarreLED* c){
    for(int i = 0; i<4; i++){
        ligne[i] = c->ligne[i];
    }
}

CaseLED* BarreLED::getLigne(int i){
    return(ligne[i]);
}

