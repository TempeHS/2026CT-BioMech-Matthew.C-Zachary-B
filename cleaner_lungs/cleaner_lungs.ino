void setup() {
  air_quality_setup();
  dust_setup();
  led_setup();
}

void loop() {
  air_quality();
  dust();
  led();
  delay(100);
}