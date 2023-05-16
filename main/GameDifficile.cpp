#include "Game.h"

void Game::Init() {
  _touch1.setup();
  _touch2.setup();
  _touch3.setup();
  _touch4.setup();
  _ecran.EcranStart();
  Over = false;
  Affiche = false;
  Score = 0;
  compteur = 0;
  
  
  // Attendre jusqu'à ce qu'un des touch sensors soit activé
  bool isTouched = false;
  while (!isTouched) {
    if (_touch1.Touched1() || _touch2.Touched2() || _touch3.Touched3() || _touch4.Touched4()) {
      isTouched = true;
    }
    delay(1000); // Attendre 100 millisecondes avant de vérifier à nouveau
  }
  
  // Démarrer le jeu une fois qu'un touch sensor est activé
  //_ecran.EcranInGame(Score);
  
  //Initialisation de la LED matrix et des variables
  // ...
}

void Game::chooseMode() {
   bool touched1 = _touch1.Touched1();
   bool touched2 = _touch2.Touched2();
   if (touched1){
     mode = 0;
   }
   else if (touched2){
     mode = 1;
   }
}

 void Game::AfficheMat(){
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
  i = random(3);
  if (Affiche == false) {
    ecranLED.EteintTout();
    tableau = ecranLED.getTab();
    for(int i=0; i<64; i++){
      pic3[i] = tableau[i];
    }
    matrix.displayFrames(pic3, 2000, true, 1);
 
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


void Game::updateGame() {
  // Code pour gérer le jeu en cours ici
 
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



void Game::endGame() {
  _ecran.EcranGameOver(Score);
}
