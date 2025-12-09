int ledPIN = 5;


void led_setup () {
  pinMode(ledPIN, OUTPUT);
  Serial.println("LED Is Setup");
}

void led_alert () {
  digitalWrite(ledPIN, HIGH);
  delay(500);
  digitalWrite(ledPIN, LOW);
  delay(500);
}