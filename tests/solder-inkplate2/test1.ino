
#ifndef ARDUINO_INKPLATE2
#error "Wrong board selection for this example, please select Soldered Inkplate2 in the boards menu."
#endif

#include "Inkplate.h"

Inkplate display;

#define DELAY_S 1000

unsigned long myTime;

void printTime(String prefix) {
  Serial.print("Time: (");
  Serial.print(prefix);
  Serial.print(") ");
  myTime = millis();
  Serial.println(myTime);
}

void setup() {
  Serial.begin(19200);
  delay(2000);
  Serial.println();
  Serial.println("The program has started successfully.");
  display.begin();        // Init library (you should call this function ONLY ONCE)
  display.clearDisplay(); // Clear any data that may have been in (software) frame buffer.
}

void loop() {
  printTime("new loop");
  display.clearDisplay();
  display.setTextColor(1);
  display.setTextSize(2);
  display.setCursor(5, 5);
  display.print("Example Demo");

  display.setCursor(55, 24);
  display.print("BBT");

  display.setTextColor(2);
  display.setTextSize(3);
  display.setCursor(15, 44);
  display.print("Jonas");
  display.setCursor(80, 74);
  display.print("Schmid");
  display.display();
  printTime("5");
  delay(DELAY_S * 100);
}
