#include "Game.h"
#include "TouchSensor.h"
#include "Ecran.h"
#include "grove_two_rgb_led_matrix.h"
#include "caseLED.h"
#include "barreLED.h"
#include "ecranLED.h"
GameDifficile game;
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
//LED MATRIX
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
    #define SERIAL SerialUSB
#else
    #define SERIAL Serial
#endif

void waitForMatrixReady() {
    delay(1000);
}

GroveTwoRGBLedMatrixClass matrix;
EcranLED ecran;

void setup() {
   Wire.begin();
    SERIAL.begin(115200);
    waitForMatrixReady();
    uint16_t VID = 0;
    VID = matrix.getDeviceVID();
    if (VID != 0x2886) {
        SERIAL.println("Can not detect led matrix!!!");
        while (1);
    }
    uint32_t version = 0;
    version = matrix.getTestVersion();
    SERIAL.print("version = ");
    SERIAL.println(version, HEX);
    SERIAL.println("Matrix init success!!!");
  
}
//MATRIX LED
uint8_t pic3[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0x12, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                 };

void loop() {
  game.Init();
  //game.chooseMode();
  
  //Tant que pas"Game Over"
  while (game.Over == false) {
    game.AfficheMat();
    game.updateGame();
  }
 game.endGame(); 
}
