// GxEPD_Hello World Example by Jean-Marc Zingg
//
// Created by Jean-Marc Zingg based on demo code from Good Display,
// available on http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// The e-paper displays are available from:
//
// https://www.aliexpress.com/store/product/Wholesale-1-54inch-E-Ink-display-module-with-embedded-controller-200x200-Communicate-via-SPI-interface-Supports/216233_32824535312.html
//
// http://www.buy-lcd.com/index.php?route=product/product&path=2897_8363&product_id=35120
// or https://www.aliexpress.com/store/product/E001-1-54-inch-partial-refresh-Small-size-dot-matrix-e-paper-display/600281_32815089163.html
//
// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

// include library, include base class, make path known
#include <GxEPD.h>
#include <GxDEPG0266BN/GxDEPG0266BN.h>      // 2.66" b/w 152x296, SSD1680, TTGO T5 V2.66, TTGO T5 V2.4.1

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 19, /*RST=*/ 4); // LILYGO® TTGO T5 2.66
GxEPD_Class display(io, /*RST=*/ 4, /*BUSY=*/ 34); // LILYGO® TTGO T5 2.66

const char text[] = "Hello World!";
const char title[] = "BBT";
const char exampleText[] = "A Example demo.";

void setup()
{
  Serial.begin(19200);
  Serial.println("..");
  Serial.println("setup");
  sleep(1);
  display.init(19200); // enable diagnostic output on Serial
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);

  drawTitle(2, 20, title);
  drawText(2, 40, exampleText);

  display.fillRect(100, 100, 7, 7, GxEPD_BLACK);
  display.drawPixel(103, 103, GxEPD_WHITE);

  display.update();

  Serial.println("display.powerDown()");
  display.powerDown();
}

void loop() {};

void drawTitle(int x, int y, const char text[]) {
  display.setFont(&FreeMonoBold18pt7b);
  printCurrentFontBounds();
  display.setCursor(x, y);
  display.print(text);
}

void drawText(int x, int y, const char text[]) {
  display.setFont(&FreeMono9pt7b);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
  display.setCursor(x, y);
  display.print(text);
}

void printCurrentFontBounds() {
  Serial.println("---------------------");
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds("BBT", 0, 0, &tbx, &tby, &tbw, &tbh);
  Serial.print("text position x:");
  Serial.print(tbx);
  Serial.print(" y:");
  Serial.print(-tby);
  Serial.print(" and space requirements w:");
  Serial.print(tbw);
  Serial.print(" h:");
  Serial.println(tbh);
  Serial.println("---------------------");
}

void drawHelloWorldForDummies()
{
  // This example function/method can be used with full buffered graphics AND/OR paged drawing graphics
  // for paged drawing it is to be used as callback function
  // it will be executed once or multiple times, as many as needed,
  // in case of full buffer it can be called directly, or as callback
  // IMPORTANT: each iteration needs to draw the same, to avoid strange effects
  // use a copy of values that might change, don't read e.g. from analog or pins in the loop!
  //Serial.println("drawHelloWorldForDummies");
  const char text[] = "Hello World!";
  // most e-papers have width < height (portrait) as native orientation, especially the small ones
  // in GxEPD rotation 0 is used for native orientation (most TFT libraries use 0 fix for portrait orientation)
  // set rotation to 1 (rotate right 90 degrees) to have enough space on small displays (landscape)
  display.setRotation(1);
  // select a suitable font in Adafruit_GFX
  display.setFont(&FreeMonoBold9pt7b);
  // on e-papers black on white is more pleasant to read
  display.setTextColor(GxEPD_BLACK);
  // Adafruit_GFX has a handy method getTextBounds() to determine the boundary box for a text for the actual font
  int16_t tbx, tby; uint16_t tbw, tbh; // boundary box window
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh); // it works for origin 0, 0, fortunately (negative tby!)
  // center bounding box by transposition of origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.fillScreen(GxEPD_WHITE); // set the background to white (fill the buffer with value for white)
  display.setCursor(x, y); // set the postition to start printing text
  display.print(text); // print some text
  //Serial.println("drawHelloWorldForDummies done");
}
