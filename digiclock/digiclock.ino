// digiclock.ino

#include "tft_setup.h"
#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
}

void loop() {
  uint16_t cal[5];
  tft.setRotation(1);  // Landscape orientation!
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.print("Touch corners ... ");
  tft.calibrateTouch(cal, TFT_MAGENTA, TFT_BLACK, 15);
  tft.println("done.");

  Serial.printf("cal: {%d, %d, %d, %d, %d}\n",
                cal[0], cal[1], cal[2], cal[3], cal[4]);
  delay(10000);
}