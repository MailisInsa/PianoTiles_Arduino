#include "GameDifficile.h"

void GameDifficile::updateGame(){
  compteur ++;
    
  _ecran.EcranInGame(Score);
  bool touched1 = _touch1.Touched();
  bool touched2 = _touch2.Touched();
  bool touched3 = _touch3.Touched();
  bool touched4 = _touch4.Touched();

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


void GameDifficile::AfficheMat(){
  int i=0;
   uint8_t pic3[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0x12, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                 };
  uint64_t* tableau;
  int n;

  if (Affiche == false) {
    ecranLED.EteintTout();
    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
 
    if(v5[n]==0){
      ecranLED.AllumerCase0();
    }else if(v5[n]==1){
      ecranLED.AllumerCase1();
    }else if(v5[n]==2){
      ecranLED.AllumerCase2();
    }else if(v5[n]==3){
      ecranLED.AllumerCase3();
    }else if(v5[n]==4){
      ecranLED.AllumerCase1();
      ecranLED.AllumerCase3();
    }else if(v5[n]==5){
      ecranLED.AllumerCase0();
      ecranLED.AllumerCase2();
    }
    //On change aléatoirement l'ordre des entiers dans le vecteur v lorsqu'on a fait le tour de toutes ses valeurs
    if (n==6){
      n=0;
      std::random_shuffle(v5.begin(),v5.end());  
    } else {n++;}

    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    Affiche = true;
  }
}
