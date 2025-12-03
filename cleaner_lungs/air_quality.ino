#include <Air_Quality_Sensor.h>

AirQualitySensor sensor(A0);


void air_quality_setup() {
  while (!Serial);
  Serial.println("Waiting for Air Quality Sensor to initiate");
  delay(10000);

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


bool air_quality_check () {
  int quality = sensor.slope();
  bool air_quality_cleanair = true;

  if (quality != AirQualitySensor::FRESH_AIR) {
    air_quality_cleanair = false;
  } else if(quality == AirQualitySensor::FRESH_AIR) {
    air_quality_cleanair = true;
  }
  return air_quality_cleanair;
}
