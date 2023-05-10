#include "BarreLED.h"


BarreLED::BarreLED(){
    ligne = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}
    suivante = nullptr;
}
void BarreLED::FaireDefiler(){
    suivante->ligne = ligne;
}

