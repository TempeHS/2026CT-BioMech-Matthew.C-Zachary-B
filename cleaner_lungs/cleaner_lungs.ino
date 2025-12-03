void setup() {
  serial_monitor();
  air_quality_setup();
  dust_setup();
  speaker_setup();
  led_setup();
}

void loop() {
  if (air_quality_check() == false || isDustDetected() == true) { // air quality will return true if air is clean, ust will return false if air is clean
    speaker();
    led_alert();
  } else {}
}

void serial_monitor() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured For 9600");
  Serial.println("----------------------------------");
}