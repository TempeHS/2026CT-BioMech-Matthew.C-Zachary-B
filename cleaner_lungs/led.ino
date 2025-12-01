int ledPIN = 7;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
}

void led () {
  if (air_quality_cleanair == false || dust_cleanair == false) {
    digitalWrite(ledPIN, True)
  }

}