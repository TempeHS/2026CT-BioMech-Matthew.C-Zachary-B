##
# Speaker

- Speaker will alert if something is detected in the air 

- It will use sound to alert the user of hazards in the air.

---------------------------------------------------------------
#### 26/11/25

- The speaker will be on pin 6.

- Tested speaker for functionality

  - Speaker made a small sound, the speaker works

  - Speaker also is able to work in different tones

#### End of 26/11/25

---------------------------------------------------------------
#### 1/12/25

- Addition of code from Copilot
Speaker should make a continous beeping sound with delay in between beeps.

- Tested functionality of code
  - Code works, speaker makes a continous beeping sound until removed from Arduino

#### End of 1/12/25

---------------------------------------------------------------
#### 2/12/25

- Code is being implemented in main file (cleaner_lungs.ino)
  - Testing speaker activation with air quality sensor and dust sensor detection

#### End of 2/12/25

---------------------------------------------------------------

#### 3/12/25

- New code to implement speaker into main file
 
 ~~~
 void loop() {
  if (air_quality_check() == false || isDustDetected() == true) { // air quality will return true if air is clean, ust will return false if air is clean
    speaker();
    led_alert();
  } else {}
}

 - Serial monitor stuck on air quality setup
 ~~~

#### End of 3/12/25

---------------------------------------------------------

#### 8/12/25

- Speaker setup works

- Speaker works with dust sensor and air quality sensor
    - Sensor beeped when air quality was bad or dust was detected

#### End of 8/12/25

------------------------------------------------------------