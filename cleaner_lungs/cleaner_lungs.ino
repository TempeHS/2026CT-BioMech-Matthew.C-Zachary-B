void setup() {
  serial_monitor();
  air_quality_setup();
  dust_setup();
  speaker_setup();
  led_setup();
}

void loop() {
  if (isDustDetected()) {
    Serial.println("Dust detected! Alerting...");
    speaker();         // sound alert
    led(true);   // turn LED on/flash
  } else {
    led(false);  // ensure LED off when clear
  }
  delay(100);
}

void serial_monitor() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured For 9600");
  Serial.println("----------------------------------");
}