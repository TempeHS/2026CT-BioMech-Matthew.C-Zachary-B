void setup() {

  dust_setup();

}

void loop() {

  dust();

  delay(100);
}

void serial_monitor() {
  Serial.begin(9600);
  Serial.println("Serial Monitor Configured For 9600");
  Serial.println("----------------------------------");
}