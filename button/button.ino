
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
//define pin of button
const int buttonPin = 2;
int buttonState = 0;
int colors[8] = {BLACK, BLUE, RED, GREEN, CYAN, MAGENTA, YELLOW, WHITE};
int x = 160;
int y = 0;
int xDir = 1;
int yDir = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.print("Starting up");
  tft.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  for(int i = 0; i < 240; i+=10) {
    for(int j = 0; j < 320; j+=10) {
      int color;
      if(i == y && j == x) {
        color = WHITE;
      } else {
        color = GREEN;
      }
      tft.fillRect(i, j, 10, 10, color);
    }
  }
  y += yDir * 10;
  x += xDir * 10;

  if(x < 10 || x > 300) {
    xDir *= -1;
  }
  if(y < 10 || y > 220) {
    yDir *= -1;
  }
  
}

void clear() {
  tft.fillScreen(ILI9340_BLACK);
  tft.setCursor(0, 0);
}

