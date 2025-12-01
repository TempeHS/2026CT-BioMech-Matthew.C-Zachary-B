void setup() {
  air_quality_setup();
  dust_setup();
  speaker_setup();
  led_setup();
}

void loop() {
  air_quality();
  dust();
  speaker();
  led();
  delay(100);
}

void serial_monitor() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured For 9600");
  Serial.println("----------------------------------");
}