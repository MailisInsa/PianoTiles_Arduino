#include "Ecran.h"
#include <U8g2lib.h>
  void Ecran::EcranStart(){
  U8G2_SH1107_SEEED_128X128_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
  u8g2.begin();
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(20,50,"Welcome to Piano");// write something to the internal memory
  u8g2.drawStr(60,60," Tiles!");// write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(20,50,"Click on button to ");// write something to the internal memory
  u8g2.drawStr(60,60,"start!");// write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
}
  void Ecran:: EcranInGame(int Score){
  //Setup
  U8G2_SH1107_SEEED_128X128_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
  u8g2.begin(); 
  u8g2.clearBuffer();
  char score_str[10];
  itoa(Score, score_str, 10);
  u8g2.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
  u8g2.drawStr(50,50,"Score:");
  u8g2.drawStr(60,60,score_str);
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  
  }

  void Ecran:: EcranGameOver(int Score){
  //Setup
  U8G2_SH1107_SEEED_128X128_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
  u8g2.begin();
  u8g2.clearBuffer();
  char score_str[10];
  itoa(Score, score_str, 10); 
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(40,50,"Game Over!");
  u8g2.drawStr(50,60,"Score:");
  u8g2.drawStr(65,70,score_str);
  u8g2.sendBuffer();  // transfer internal memory to the display
  delay(1000);  
  }
