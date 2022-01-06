/*
  WlanTest

  This program works as a HTTP server.
  At program start, it make a connection to the local WiFI. 
  The home page show the state of the onboard LED.
  You can enable or disable the LED with the displayed links.
  
  created 20212 by Jonas Schmid (Puzzle ITC GmbH)

  This code is under the GNU Affero General Public License v3.0
  licence and can downloaded from the IT-Ninjas GIT repo:
  https://github.com/puzzle-bbt/arduino
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "123456"

ESP8266WebServer server(80);

void setup() {
  initSerial();

  // onboard LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  connectToWiFi();
 
  initWebserver();
  Serial.println("HTTP server started");
}

void loop() {
//  int led_state = digitalReadOutputPin(LED_BUILTIN);
  server.handleClient();
}
