/*
  ButtonTest

  This program demonstrate the scanning of input buttons.
  It use the two buttons on the Monochrome OLEDs Shield.

  created 20212 by Jonas Schmid (Puzzle ITC GmbH)

  This code is under the GNU Affero General Public License v3.0
  licence and can downloaded from the IT-Ninjas GIT repo:
  https://github.com/puzzle-bbt/arduino
*/

// constants won't change. They're used here to set pin numbers:
const int buttonA = 14;     // GPIO14 => WeMos D1 mini: Pin D5
const int buttonB = 12;     // GPIO12 => WeMos D1 mini: Pin D6

// variables will change:
int buttonStateA = 0;
int buttonStateB = 0;

void setup() {
  initSerial();
  
  // initialize the buttons as inputs
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() {
  buttonStateA = digitalRead(buttonA);
  buttonStateB = digitalRead(buttonB);

  Serial.print("Pressed buttons: ");
  
  if (buttonStateA == LOW) {
    Serial.print("A ");
  }
  if (buttonStateB == LOW) {
    Serial.print("B");
  }
  Serial.println();
  delay(200);
}
