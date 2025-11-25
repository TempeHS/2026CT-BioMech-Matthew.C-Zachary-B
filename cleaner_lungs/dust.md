Dust Sensor detects dust concentration in the air

It will be used to detect small concentrations of dust, aiming to allow for avoidance of all dust in the air.
The sensor is also capable of detecting cigarette dust

------------------------------------------------------------------------------------------------------------------------------------------------
17/11/25
- Copied base code from Seeed Studio Wiki for Grove dust sensor 
Link: https://wiki.seeedstudio.com/Grove-Dust_Sensor/

Below is the setup for the dust sensor pin and global variable values from the base code:
~~~
int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;//sampe 30s ;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0; 
~~~

The dust sensor will be on pin 8.
The unsigned long variables are the variables in use during the measuring of the dust
The floats are what the values measured by the unsigned long variables.

Upload testing has not been done due to lack of setup of other files (led.ino specifically)
Zach has begun work on air quality sensor *DO NOT TOUCH AIR QUALITY SENSOR FILE AT ALL*

End of 17/11/25

------------------------------------------------------------------------------------------------------------------------------------------------
26/11/25
 - Tested dust sensor functionality

 Dust sensor outputted values that were reasonable, this means the dust sensor we have is functional

- Changed dust sensor measuring dust to binary detection of dust

Used Copilot to change dust sensor from measuring concentrations of dust in values, now the sensor measures if there is dust or no dust

End of 26/11/25