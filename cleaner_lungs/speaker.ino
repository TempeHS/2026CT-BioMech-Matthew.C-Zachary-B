const int SPEAKER_PIN = 6;

void speaker_setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Speaker Begin");
}

void speaker() {
  // Rapid high-pitched beeping - very attention-grabbing
  tone(SPEAKER_PIN, 3000);  // High frequency
  delay(100);               // Short beep
  noTone(SPEAKER_PIN);
  delay(50);               // Short pause
  tone(SPEAKER_PIN, 2750);  // High frequency
  delay(100);               // Short beep
  noTone(SPEAKER_PIN);
  delay(50);               // Short pause
  
  
  // This runs forever until Arduino is reset or powered off
}