int ledPIN = 3;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
}

void led () {
  digitalWrite(ledPIN, HIGH);
}