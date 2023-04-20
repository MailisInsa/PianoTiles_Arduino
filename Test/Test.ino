#include "grove_two_rgb_led_matrix.h"

#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
    #define SERIAL SerialUSB
#else
    #define SERIAL Serial
#endif

GroveTwoRGBLedMatrixClass matrix;
void setup() {
    Wire.begin();
    SERIAL.begin(115200);
    delay(1000);
    uint32_t version = 0;
    version = matrix.getTestVersion();
    SERIAL.print("version = ");
    SERIAL.println(version, HEX);
    SERIAL.println("Matrix init success!!!");

}
uint64_t pic[2];
pic[0] = {170};
pic[1] = {255};

uint64_t* ligne[4];
for(int i=0; i<4; i++){
    ligne[i] = pic;
}

uint64_t** colonne[8];
for(int i=0; i<8; i++){
    colonne[i] = ligne;
}

void loop() {
    matrix.displayFrames(colonne, 2000, true, 1);
    delay(5000);
}