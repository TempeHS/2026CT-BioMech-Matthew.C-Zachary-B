int ledPIN = 5;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
}

void led_alert () {
  digitalWrite(ledPIN, HIGH);
  delay(50);
  digitalWrite(ledPIN, LOW);
  delay(50);
  digitalWrite(ledPIN, HIGH);
  delay(50);
  digitalWrite(ledPIN, LOW);
}