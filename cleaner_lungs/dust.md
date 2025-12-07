##
# Dust Sensor

- Dust Sensor detects dust concentration in the air

- It will be used to detect small concentrations of dust, aiming to allow for avoidance of all dust in the air.
The sensor is also capable of detecting cigarette dust

------------------------------------------------------------------------------------------------------------------------------------------------
#### 17/11/25

- Copied base code from Seeed Studio Wiki for Grove dust sensor 
  - Link: https://wiki.seeedstudio.com/Grove-Dust_Sensor/

- The dust sensor will be on pin 8.

- Upload testing has not been done due to lack of setup of other files (led.ino specifically).
Zach has begun work on air quality sensor 

*DO NOT TOUCH AIR QUALITY SENSOR OR LED FILE AT ALL*

#### End of 17/11/25

------------------------------------------------------------------------------------------------------------------------------------------------
#### 26/11/25

 - Tested dust sensor functionality

    - Dust sensor outputted values that were reasonable, this means the dust sensor we have is functional

- Changed dust sensor measuring dust to binary detection of dust

  - Used Copilot to change dust sensor from measuring concentrations of dust in values, now the sensor measures if there is dust or no dust.
The serial monitor shows if the sensors detects dust

#### End of 26/11/25

------------------------------------------------------------------------------------------------------------------------------------------------
#### 1/12/25

- Lowered alert threshold from 30 000 -> 10 000
  - This allows for only mostly clean air to not alert the sensor

- Testing binary detection system 
  - Binary detection system is able to detect dust with a threshold of 10000 (microns?)

- Serial monitor output issue
  - Serial monitor outputs 2 "No Dust" when detecting no dust
    - Fixed by making SAMPLE_TIME_MS from:

### Before Fix:
~~~
const unsigned long SAMPLE_TIME_MS = 1000;
~~~

### After Fix:
~~~
const unsigned long SAMPLE_TIME_MS = 500;
~~~
  - Lowering the sample time seems to have given the serial monitor less time which made the extra line of "No Dust" not appear
#### End of 1/12/25

------------------------------------------------------------------------------------------------------------------------------------------------
#### 2/12/25

- Implementing code into main file (cleaner_lungs.ino)
  - Testing dust sensor binary detection to activate speaker and led alert

- The code used to implement dust sensor into main file:
~~~
  if (isDustDetected()) {
    Serial.println("Dust detected! Alerting...");
    speaker();         // sound alert
    led(true);   // turn LED on/flash
  } else {
    led(false);  // ensure LED off when clear
  }
  delay(100);
~~~

- Code will be changed due to error with led

#### End of 2/12/25

------------------------------------------------------------------------------------------------------------------------------------------------

#### 3/12/25

 - New code to implement dust sensor + air quality sensor:

 ~~~
 void loop() {
  if (air_quality_check() == false || isDustDetected() == true) { // air quality will return true if air is clean, ust will return false if air is clean
    speaker();
    led_alert();
  } else {}
}
~~~

 - Serial monitor is stuck on Air Quality SY�

#### End of 3/12/25

------------------------------------------------------------------------------------------------------------------------------------------

####  8/12/25

  - Issue with the serial monitor (Air quality sensor) resolved

  - 3/4 sensors work
      - Only led is not working

  - After dust setup was fixed, dust + speaker set up and loop appeared in the serial monitor

  - Dust sensor loop text appears but air quality sensor loop text doesn't

#### End of 8/12/25

-------------------------------------------------------------------------------------------------------------------------------------