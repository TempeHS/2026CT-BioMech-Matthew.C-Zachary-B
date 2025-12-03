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
