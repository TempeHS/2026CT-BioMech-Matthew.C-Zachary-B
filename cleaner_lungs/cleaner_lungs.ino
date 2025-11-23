void setup() {
  serial_monitor();
  air_quality_setup();
  dust_setup();
}

void loop() {
  air_quality();
  dust();
  delay(100);
}

void serial_monitor() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured For 9600");
  Serial.println("----------------------------------");
}