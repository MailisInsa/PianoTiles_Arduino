#include <grove_two_rgb_led_matrix.h>
#include "caseLED.h"

CaseLED::CaseLED(){allume = false;}
void CaseLED::allumer(){
    allume = true;
    pic[0] = {170};
    pic[1] = {170};
    }
void CaseLED::eteindre(){
    allume = false;
    pic[0] = {255};
    pic[1] = {255};
    }
bool CaseLED::EstAllume(){return(allume);}
uint64_t CaseLED::getMat1(){return(pic[0])};
uint64_t CaseLED::getMat2(){return(pic[1])};

