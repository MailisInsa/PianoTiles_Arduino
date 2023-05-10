#include "BarreLED.h"


BarreLED::BarreLED(){
    ligne[0] = CaseLED.allumer();
    ligne[2] = CaseLED.allumer();
    suivante = nullptr;
}
void BarreLED::FaireDefiler(){
    suivante->ligne = ligne;
}

