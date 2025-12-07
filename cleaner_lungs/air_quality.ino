#include <Air_Quality_Sensor.h>

AirQualitySensor sensor(A0);


void air_quality_setup() {
  // Wait up to 5s for USB Serial (non-blocking)
  unsigned long start = millis();
  while (!Serial && (millis() - start) < 5000) {
    delay(10);
  }

  if (Serial) Serial.println("Serial connected");

  Serial.println("Waiting for Air Quality Sensor to initiate (1s)");
  delay(1000);
  Serial.println("Air Quality Sensor Initiated");
}

bool air_quality_check () {
  bool air_quality_cleanair;
  int quality = sensor.slope();
  if (quality == AirQualitySensor::FRESH_AIR) {
    air_quality_cleanair = true;
    Serial.println("Air Clean");
  } else {
    air_quality_cleanair = false;
    Serial.println("Air not clean");
  }
  return air_quality_cleanair;
}