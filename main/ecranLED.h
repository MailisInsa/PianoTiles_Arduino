#include "grove_two_rgb_led_matrix.h"
#include "barreLED.h"
#include "caseLED.h"


#ifndef _ECRANLED_H_
#define _ECRANLED_H_

class EcranLED{
    protected:
    //Un écran LED comprend 8 barres de LED
    BarreLED* colonne[8];
    //tableau permettant l'affichage correct des données sur l'écran LED
    uint64_t tab[64];

    public:
    //Constructeur
    EcranLED(); 

    //Fonction pour faire défiler les cases à la ligne suivante
    void Defiler();

    //Fonction permettant de récupérer le tableau de valeurs pour l'affichage LED
    uint64_t* getTab();

    //Fonction pour la récupération des valeurs de la dernière colonne, pour comparaison avec les boutons
    BarreLED* getDerniereColonne();

    //Fonction mettant toutes les valeurs du tableau sur noir
    void EteintTout();

    //Fonctions permettant d'allumer une case
    void AllumerCase0();
    void AllumerCase1();
    void AllumerCase2();
    void AllumerCase3();    
};


#endif
