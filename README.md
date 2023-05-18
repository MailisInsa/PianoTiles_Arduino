# PianoTiles_Arduino

Ce projet effectué sur une carte Arduino ESP8622, et codé en C++ consiste à reproduire le jeu Piano Tiles, ou Guitar Hero.
Le programme principal se trouve dans le dossier main. Pour compiler le projet à partir d'un IDE Arduino, il faut commencer par configurer l'IDE pour la carte ESP8266, puis choisir la carte "NodeMCU 1.0 (ESP-12E Module)". Penser aussi à activer les exceptions (Tools/C++ exceptions/"Enabled").

Pour pouvoir utiliser les écrans d'affichage, nous avons utilisé deux librairies externes : 
 - U8g2lib, qui se télécharge via le gestionnaire de librairies de l'IDE
 - Seeed_RGB_LED_Matrix, présente sur un gitHub libre d'accès

Nous avons ensuite créé plusieurs classes liées à :
 - l'écran d'affichage du score et des instructions (Ecran),
 - l'écran d'affichage LED pour les cases à toucher (ecranLED, barreLED, caseLED), 
 - aux boutons pour la validation des touches (TouchSensor),
 - au jeu en lui même, pour son fonctionnement et sa difficulté (Game, GameFacile, GameDifficile)
