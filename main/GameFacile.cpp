#include "GameFacile.h"



void GameFacile::updateGame() {  
 //Compteur pour gerer le delai du jeu
  compteur ++;


  _ecran.EcranInGame(Score);
  bool touched1 = _touch1.Touched1();
  bool touched2 = _touch2.Touched2();
  bool touched3 = _touch3.Touched3();
  bool touched4 = _touch4.Touched4();

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

  //On initialise le vecteur v qui contiendra une valeur entre 0 et 3 pour indiquer quelle case allumer
  std::vector<int> v;
  for(int i=0; i<4; i++)
    v.push_back(i);
  
  if (Affiche == false) {
    //On eteint la MatixLED au debut
    ecranLED.EteintTout();
    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    // On allume les colonnes de MatrixLED correspondant au param "i"
    if(v[n]==0){
      ecranLED.AllumerCase0();
    }else if(v[n]==1){
      ecranLED.AllumerCase1();
    }else if(v[n]==2){
      ecranLED.AllumerCase2();
    }else if(v[n]==3){
      ecranLED.AllumerCase3();
    }

    //Lorsqu'on a parcouru toutes les valeurs de v, on shuffle le vecteur pour changer l'ordre d'allumage des cases
    if (n==3){
      n=0;
      std::random_shuffle(v.begin(),v.end());  
    } else {n++;}
      

    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
    Affiche = true;
  }
}