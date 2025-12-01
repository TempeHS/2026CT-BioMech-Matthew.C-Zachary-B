# Dust Sensor

Dust Sensor detects dust concentration in the air

It will be used to detect small concentrations of dust, aiming to allow for avoidance of all dust in the air.
The sensor is also capable of detecting cigarette dust

------------------------------------------------------------------------------------------------------------------------------------------------
17/11/25

- Copied base code from Seeed Studio Wiki for Grove dust sensor 
Link: https://wiki.seeedstudio.com/Grove-Dust_Sensor/

The dust sensor will be on pin 8.

Upload testing has not been done due to lack of setup of other files (led.ino specifically)
Zach has begun work on air quality sensor *DO NOT TOUCH AIR QUALITY SENSOR FILE AT ALL*

End of 17/11/25

------------------------------------------------------------------------------------------------------------------------------------------------
26/11/25

 - Tested dust sensor functionality

 Dust sensor outputted values that were reasonable, this means the dust sensor we have is functional

- Changed dust sensor measuring dust to binary detection of dust

Used Copilot to change dust sensor from measuring concentrations of dust in values, now the sensor measures if there is dust or no dust
The serial monitor shows if the sensors detects dust

End of 26/11/25

------------------------------------------------------------------------------------------------------------------------------------------------
1/12/25

 - Testing binary detection system 

