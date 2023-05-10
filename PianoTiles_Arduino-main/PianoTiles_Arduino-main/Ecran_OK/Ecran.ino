#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1107_SEEED_128X128_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  u8g2.begin();
}
char a[] = "0";
bool DBegin = 0;
bool DInGame = 0;
bool DEndGame = 1;
void loop(void) {
  //const char c = (const char)a;
//Welcome Display 
  if (not DInGame and DBegin and not DEndGame) {
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(5,20,"Welcome to Piano");// write something to the internal memory
  u8g2.drawStr(40,40," Tiles!");// write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(5,20,"Click on button to ");// write something to the internal memory
  u8g2.drawStr(40,40,"start!");// write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
  }
  //Ingame Display 
  else if (DInGame and not DBegin and not DEndGame) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
  u8g2.drawStr(50,50,"Score:");
  u8g2.drawStr(60,60,a);
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  
  a[0] = a[0]+1;
  }
  //Game Over Display 
  else {
  //else if  (not DInGame and not DBegin and DEndGame) {
  u8g2.clearBuffer(); 
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(40,50,"Game Over!");
  u8g2.drawStr(50,60,"Score:");
  u8g2.drawStr(65,70,a);
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);  
  a[0] = a[0]+1;
  }
}
