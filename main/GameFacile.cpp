#include "GameFacile.h"



void GameFacile::updateGame() {  
 //Compteur pour gerer de delai du jeu
  compteur ++;
    
  _ecran.EcranInGame(Score);
  bool touched1 = _touch1.Touched1();
  bool touched2 = _touch2.Touched2();
  bool touched3 = _touch3.Touched3();
  bool touched4 = _touch4.Touched4();

  // Vérifier si le joueur a appuyé sur le bon capteur tactile
  //&ecran.getDerniereCeolonne()->getLigne(0).EstAllume() //-> true si la case 0 est allumée
  if(compteur<3){
    if (touched1 & ecranLED.getDerniereColonne()->getLigne(0)->EstAllume()) {
      Score++;
      compteur = 0;
      Affiche = false;
    } else if (touched2 & ecranLED.getDerniereColonne()->getLigne(1)->EstAllume()) {
      Score++;
      compteur = 0;
      Affiche = false;
    } else if (touched3 & ecranLED.getDerniereColonne()->getLigne(2)->EstAllume()) {
      Score++;
      compteur = 0;
      Affiche = false;
    } else if (touched4 & ecranLED.getDerniereColonne()->getLigne(3)->EstAllume() ) {
      Score++;
      compteur = 0;
      Affiche = false;
    }
 
  } else Over = true;
}


//Initialisation de la LED matrix et des variables et gerer l'affichage
 void GameFacile::AfficheMat(){
  int i=0;
  uint8_t pic3[]={0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0x12, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                 };
  uint64_t* tableau;
  i = random(3); // i prendre aleatoirement valeur 0 1 2 3 correspondant a l'affichage aleatoirement des colonnes de MatrixLED
  if (Affiche == false) {
    //On eteint la MatixLED au debut
    ecranLED.EteintTout();
    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
  // On allume les colonnes de MatrixLED correspondant au param "i"
    if(i==0){
      ecranLED.AllumerCase0();
    }else if(i==1){
      ecranLED.AllumerCase1();
    }else if(i==2){
      ecranLED.AllumerCase2();
    }else if(i==3){
      ecranLED.AllumerCase3();
    }

    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    Affiche = true;
  }
}