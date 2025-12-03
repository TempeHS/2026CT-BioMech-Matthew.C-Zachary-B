int ledPIN = 3;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
}

void led_alert () {
  digitalWrite(ledPIN, HIGH);
  delay(50);
}