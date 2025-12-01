const int DUST_SENSOR_PIN = 8;

// Detection Parameters
const unsigned long SAMPLE_TIME_MS = 1000;
const unsigned long DUST_THRESHOLD = 10000;       // Adjust for your environment

// Variables
unsigned long duration;
unsigned long starttime;
unsigned long lowpulseoccupancy = 0;

void dust_setup() {
  Serial.begin(9600);
  pinMode(DUST_SENSOR_PIN, INPUT);
  starttime = millis();
  
  Serial.println("=== Dust Detection Module ===");
  Serial.print("Threshold: ");
  Serial.println(DUST_THRESHOLD);
  Serial.println();
}

void dust() {
  // Check for dust presence
  if (isDustDetected()) {
    // DUST DETECTED - Call your main alert function
    Serial.println("⚠️  DUST DETECTED ");
    
    // TODO: Call your main alert function here
    // triggerMainAlert();
    
  } else {
    // NO DUST - All clear
    Serial.println(" No Dust ");
  }
}

/**
 * Check if dust is present
 * 
 * Returns:
 *   true  - Dust detected above threshold
 *   false - Air is clean
 * 
 * This function accumulates LOW pulse duration over SAMPLE_TIME_MS
 * and compares to DUST_THRESHOLD to determine if dust is present.
 */
bool isDustDetected() {
  // Accumulate pulse duration
  duration = pulseIn(DUST_SENSOR_PIN, LOW);
  lowpulseoccupancy += duration;

  // Check if sample period elapsed
  if ((millis() - starttime) >= SAMPLE_TIME_MS) {
    
    // Determine if threshold exceeded
    bool dustPresent = (lowpulseoccupancy > DUST_THRESHOLD);
    
    // Debug output
    Serial.print("LPO: ");
    Serial.print(lowpulseoccupancy);
    Serial.print(" | Threshold: ");
    Serial.print(DUST_THRESHOLD);
    Serial.print(" | Detected: ");
    Serial.println(dustPresent ? "YES" : "NO");
    
    // Reset for next sample period
    lowpulseoccupancy = 0;
    starttime = millis();
    
    return dustPresent;
  }
  
  // Still accumulating data, return last known state
  return false;  // Default to clean until full sample collected
}