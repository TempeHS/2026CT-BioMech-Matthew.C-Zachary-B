# Air Quality Sensor

## Link for air quality library: 
https://github.com/Seeed-Studio/Grove_Air_quality_Sensor
Version 1.0.2

## Base code from: 
https://wiki.seeedstudio.com/Grove-Air_Quality_Sensor_v1.3/

### The Air Quality sensor will be on pin A0.

### I believe the setup prints " waiting to init..", until it has initiated, then if it has not after 20 seconds, then it prints "Sensor error".
#### End of 17/11/25
----------------------------------
### Added serial monitor setup in source file. Debugged part of this file.
#### End of 19/11/25
----------------------------------
### Finished serial monitor setup. Tried to run the code on an arduino board. Had some Technical issues with computers.
#### End of 24/11/25
----------------------------------
### Code finally uploaded to arduino board. Code works, and can print to serial monitor the value of the sensor, and how fresh the air is.
#### End of 26/11/25
----------------------------------
### Added functions so that the led and speaker can read the sensors to activate. Added a function that sets the variable cleanair to either true of false if there is any pollution.
### If the sensor reads anything above (AirQualitySensor::FRESH_AIR), it will set the variable cleanair to false, which can then indicate to the led and buzzer to go off.
#### End of 1/12/25
----------------------------------
### Made "air_quality_check();" a bool function, and made it return a value based on whether there was any pollution detected.
### Also fixed up the main file due to issues with led function
### The main function air_quality is mostly useless now, and only really exists because it is an original loop.
### Removed main funcion air_quality to save space and make the ino file cleaner
#### End of 3/12/25
----------------------------------
### Error with the setup of air quality sensor is fixed with the removal of the "sensor.init" part.
### Redid "air_quality_check()", and also added printing to serial into it, for degugging
### Re-removed air_quality(), as it was readded by Matthew
#### End of 8/12/25
----------------------------------