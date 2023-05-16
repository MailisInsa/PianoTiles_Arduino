#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"

CaseLED::CaseLED(){
    allume = false;
    LedMat[0] = {0xff}; //0xff = 255 = éteint
    LedMat[1] = {0xff};
    }
void CaseLED::allumer(){
    allume = true;
    LedMat[0] = {170};  //170 = bleu
    LedMat[1] = {170};
    }
void CaseLED::eteindre(){
    allume = false;
    LedMat[0] = {0xff};
    LedMat[1] = {0xff};
    }

bool CaseLED::EstAllume(){return(allume);}

uint64_t CaseLED::getMat1(){return(LedMat[0]);};

uint64_t CaseLED::getMat2(){return(LedMat[1]);};
