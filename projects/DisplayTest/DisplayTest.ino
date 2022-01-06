/*
  LEDTest

  This program demonstrate the handling of the Monochrome OLEDs Shield.
  based on SSD1306 drivers.

  Library: https://github.com/stblassitude/Adafruit_SSD1306_Wemos_OLED
  This example is for a 64x48 size display using I2C to communicate
  3 pins are required to interface (2 I2C and one reset)

  created 20212 by Jonas Schmid (Puzzle ITC GmbH)

  This code is under the GNU Affero General Public License v3.0
  licence and can downloaded from the IT-Ninjas GIT repo:
  https://github.com/puzzle-bbt/arduino
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  initSerial();
    
  // by default, we'll generate the high voltage from the 3.3v line internally! 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  Serial.println();
//    waitForStart();
}

void loop() {
  Serial.println("test text");
  testText();
  Serial.println("test scroll");
  testScroll();
  Serial.println("test lines");
  testLine();
}

void testText() {
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.println("1WWWWWWWWW");
    display.println("L2");
    display.println("L3");
    display.println("L4");
    display.println("L3");
    display.println("L6");
    display.display();
    pause();
    pause();
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(2);
    display.println("2WWWW");
    display.println("L2");
    display.println("L3");
    display.display();
    pause();
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(3);
    display.println("3ABCDE");
    display.display();
    pause();
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(4);
    display.println("4W");
    display.display();
    pause();

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(5);
    display.println("5W");
    display.display();
    pause();

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(6);
    display.println("6");
    display.display();
    pause();

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(7);
    display.println("7");
    display.display();
    pause();
    
    display.println(3.01, 1); // number with one decimal
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.setTextColor(WHITE, BLACK); // 'inverted' text
}

void testScroll() {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    
    display.clearDisplay();
    display.drawPixel(20, 20, WHITE);
    display.drawPixel(20, 40, WHITE);
    display.drawPixel(40, 20, WHITE);
    display.drawPixel(40, 40, WHITE);
    display.display();
    delay(1000);
    
    display.clearDisplay();
    display.println("Hello");
    display.println("World");
    display.println("Lin:3");
    display.println("Lin:4");
    display.drawLine(0,47,display.width()-1,47, WHITE);
    display.display();
    
    delay(1000);
    display.startscrollright(0x00, 0x0F);
    delay(3000);
    display.stopscroll();
    delay(3000);
    
    display.startscrollleft(0x00, 0x05);
    delay(3000);
    display.stopscroll();
    delay(3000);
}

void testLine() {
    display.clearDisplay();
    display.drawLine(0,0,display.width()-1,0, WHITE);
    display.drawLine(0,10,44,10, WHITE);
    display.drawLine(0,11,48,11, WHITE);
    display.drawLine(0,47,display.width()-1,47, WHITE);
    
    display.drawPixel(20, 20, WHITE);
    display.drawPixel(20, 40, WHITE);
    display.drawPixel(40, 20, WHITE);
    display.drawPixel(40, 40, WHITE);
    
    display.display();
    pause();
}
