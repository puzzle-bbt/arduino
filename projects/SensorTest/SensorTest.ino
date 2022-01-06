/*
  SensorTest

  This program show the temperature and humidity from the DHT11 sensor.
  It use the 'DHT Sensor Library' for get the data.
  
  created 20212 by Jonas Schmid (Puzzle ITC GmbH)

  This code is under the GNU Affero General Public License v3.0
  licence and can downloaded from the IT-Ninjas GIT repo:
  https://github.com/puzzle-bbt/arduino
*/

#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // Type of sensor in use

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor


void setup() { 
  initSerial();
  // Initialize DHT11
  dht.begin();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  getMeasurment();
  pause();
}

void getMeasurment() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%;  Temperature: "));
  Serial.print(t);
  delay(100);
  Serial.print(F("°C "));
  Serial.print(F(";  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.println();
  delay(100);
}
