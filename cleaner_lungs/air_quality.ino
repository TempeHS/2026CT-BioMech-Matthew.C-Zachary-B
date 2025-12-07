#include <Air_Quality_Sensor.h>

AirQualitySensor sensor(A0);


void air_quality_setup() {
  // Wait up to 5s for USB Serial (non-blocking)
  unsigned long start = millis();
  while (!Serial && (millis() - start) < 5000) {
    delay(10);
  }

  if (Serial) Serial.println("Serial connected (ASCII test).");

  Serial.println("Waiting for Air Quality Sensor to initiate (1s)");
  delay(1000);
}


void air_quality() {
  int quality = sensor.slope();

  // Print sensor value in a safe, ASCII-friendly form
  long numericValue = (long) sensor.getValue();           // cast to numeric
  Serial.print("Air Quality Sensor value (numeric): ");
  Serial.print(numericValue);
  Serial.print(" | hex: 0x");
  Serial.println((unsigned long)numericValue, HEX);

  // Also print slope numeric so we don't accidentally print binary/strings
  Serial.print("Air quality slope (numeric): ");
  Serial.println(quality);

  if (quality == AirQualitySensor::FORCE_SIGNAL) {
    Serial.println("High pollution! Force signal active.");
  } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
    Serial.println("High pollution!");
  } else if (quality == AirQualitySensor::LOW_POLLUTION) {
    Serial.println("Low pollution!");
  } else if (quality == AirQualitySensor::FRESH_AIR) {
    Serial.println("Fresh air.");
  } else {
    Serial.println("Unknown quality code.");
  }

  delay(1000);
}


// ...existing code...
bool air_quality_check () {
  int quality = sensor.slope();
  return (quality == AirQualitySensor::FRESH_AIR);
}