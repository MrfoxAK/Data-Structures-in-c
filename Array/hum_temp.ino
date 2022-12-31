/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-temperature-humidity-sensor
 */

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
const int sensor_pin = D3;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
//  delay(2000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
//    Serial.print("Humidity: ");
    Serial.print(humi);
//    Serial.print("%");
//
//    Serial.print("  |  "); 
      Serial.print(","); 

//    Serial.print("Temperature: ");
    Serial.print(tempC);
//    Serial.print("°C ~ ");
//    Serial.print(tempF);
//    Serial.println("°F");
    float moisture_percentage;
    int sensor_analog;
    sensor_analog = analogRead(sensor_pin);
    moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
//    Serial.print("Moisture Percentage = ");
    Serial.print(","); 
    Serial.print(moisture_percentage);
    Serial.print("\n");
    delay(1000);
  }
}
