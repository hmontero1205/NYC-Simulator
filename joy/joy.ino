#define joyX A0
#define joyY A1

//include the libraries
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9340.h>
//define port numbers for lcd
#define TFT_MOSI  11
#define TFT_CLK   13
#define TFT_CS    10
#define TFT_RESET  9
#define _sclk 13
#define _miso 12
#define _mosi 11
#define _cs 10
#define _dc 9
#define _rst 8
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#include <SPI.h>
Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);
int prev = 0;
void setup() {
  Serial.begin(9600);
  int prev = analogRead(joyX);
  tft.begin();
  tft.fillScreen(BLACK);
}
 
void loop() {
  //tft.fillScreen(BLACK);
  //tft.setCursor(0, 0);
  // put your main code here, to run repeatedly:
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
}
