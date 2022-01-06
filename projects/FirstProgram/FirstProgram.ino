/*
  FirstProgram

  This is a first program for demonstrate:
  - the structur of a program
  - distibute a program to more files
  - compile and upload to arduino
  - serial monitor

  created 20212 by Jonas Schmid (Puzzle ITC GmbH)

  This code is under the GNU Affero General Public License v3.0
  licence and can downloaded from the IT-Ninjas GIT repo:
  https://github.com/puzzle-bbt/arduino
*/

// import libraries and declare variables
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(200); // get the serial interface time to initialize
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("The counter has the value: ");
  counter = updateCounter(counter);
  Serial.println(counter);
  // wait for a second
  delay(1000);  
}
