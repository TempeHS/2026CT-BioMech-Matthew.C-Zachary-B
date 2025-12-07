int ledPIN = 5;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
  Serial.println("LED Is Setup");
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