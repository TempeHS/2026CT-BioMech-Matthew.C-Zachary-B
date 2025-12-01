#include <Air_Quality_Sensor.h>

AirQualitySensor sensor(A0);

bool cleanair = true;

void air_quality_setup() {
  while (!Serial);
  Serial.println("Waiting for Air Quality Sensor to initiate");
  delay(20000);

  if (sensor.init()) {
    
    Serial.println("Air Quality Sensor ready.");
  } else {
    Serial.println("Air Quality Sensor ERROR!");
  }
}

void air_quality() {
  int quality = sensor.slope();

  Serial.print("Air Quality Sensor value: ");
  Serial.println(sensor.getValue());

  if (quality == AirQualitySensor::FORCE_SIGNAL) {
    Serial.println("High pollution! Force signal active.");
  } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
    Serial.println("High pollution!");
  } else if (quality == AirQualitySensor::LOW_POLLUTION) {
    Serial.println("Low pollution!");
  } else if (quality == AirQualitySensor::FRESH_AIR) {
    Serial.println("Fresh air.");
  }

  delay(1000);
}

void air_quality_read () {
  sensor.getValue(); // Reads the numerical value of the sensor
}

void air_quality_check () {
  int quality = sensor.slope();

  if (quality == AirQualitySensor::FORCE_SIGNAL || quality == AirQualitySensor::HIGH_POLLUTION || quality == AirQualitySensor::LOW_POLLUTION) {
    cleanair = false;
  } else if(quality == AirQualitySensor::FRESH_AIR) {
    cleanair = true;
  }
}

void air_quality_status () {
  sensor.slope();
}