const int DUST_SENSOR_PIN = 8;
const int LED_PIN = 5;
const int SPEAKER_PIN = 6;

// Threshold for single pulse duration (microseconds)
const unsigned long PULSE_THRESHOLD = 100;  // Adjust based on testing

void dust_setup() {
  Serial.begin(9600);
  
  pinMode(DUST_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  
  Serial.println("=== Real-Time Dust Detection ===");
  Serial.print("Pulse threshold: ");
  Serial.print(PULSE_THRESHOLD);
  Serial.println(" μs");
  Serial.println();
}

void dust() {
  // Measure single LOW pulse duration
  unsigned long pulseDuration = pulseIn(DUST_SENSOR_PIN, LOW);
  
  // Instant detection based on pulse length
  bool dustDetected = (pulseDuration > PULSE_THRESHOLD);
  
  if (dustDetected) {
    // Dust particle detected
    digitalWrite(LED_PIN, HIGH);
    tone(SPEAKER_PIN, 1500, 500);
    
    Serial.print("⚠️  Particle detected | Pulse: ");
    Serial.print(pulseDuration);
    Serial.println(" μs");
    
    delay(50);  // Brief alert
    digitalWrite(LED_PIN, LOW);
    
  } else {
    // No significant particle
    digitalWrite(LED_PIN, LOW);
    noTone(SPEAKER_PIN);
  }
  
  delay(10);  // Continuous monitoring
}