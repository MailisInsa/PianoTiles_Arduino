#include "GameFacile.h"

void GameFacile::updateGame() {  
 //Compteur pour gerer le delai du jeu
  compteur ++;


  _ecran.EcranInGame(Score);
  bool touched1 = _touch1.Touched();
  bool touched2 = _touch2.Touched();
  bool touched3 = _touch3.Touched();
  bool touched4 = _touch4.Touched();

  // Vérifier si le joueur a appuyé sur le bon capteur tactile
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
  int n;  
  
  //i = random(3); // i prend aleatoirement valeur 0 1 2 3 correspondant a l'affichage aleatoirement des colonnes de MatrixLED
  if (Affiche == false) {
    //On eteint la MatixLED au debut
    ecranLED.EteintTout();
    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    // On allume les colonnes de MatrixLED correspondant à la valeur dans le vecteur
    if(v3[n]==0){
      ecranLED.AllumerCase0();
    }else if(v3[n]==1){
      ecranLED.AllumerCase1();
    }else if(v3[n]==2){
      ecranLED.AllumerCase2();
    }else if(v3[n]==3){
      ecranLED.AllumerCase3();
    }

    //On change aléatoirement l'ordre des entiers dans le vecteur v lorsqu'on a fait le tour de toutes ses valeurs
    if (n==4){
      n=0;
      std::random_shuffle(v3.begin(),v3.end());  
    } else {n++;}
      

    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    Affiche = true;
  }
}