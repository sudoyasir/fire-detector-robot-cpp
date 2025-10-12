/*------ Arduino Fire Fighting Robot ver 2.2 (No GSM) ----*/

// --- Pin Definitions ---
#define Left 4
#define Right 5
#define Forward 6
#define GAS_SENSOR 7
#define LM1 8
#define LM2 9
#define RM1 10
#define RM2 11
#define fireSensor A1
#define buzzer A0

boolean fire = false;

void setup() {
  Serial.begin(115200);

  // Sensor & Actuator Setup
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(fireSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  Serial.println("🔥 Fire Fighting Robot v2.2 Initialized (No GSM)");
}

// --- Main Loop ---
void loop() {
  checkFireBuzzer(); // Check for fire and control buzzer
  robotMovement();   // Handle movement and extinguishing logic
}

// --- Fire Detection & Buzzer ---
void checkFireBuzzer() {
  int fireStatus = digitalRead(fireSensor);
  if (fireStatus == LOW) {  // Flame detected (depends on sensor)
    digitalWrite(buzzer, HIGH);
    Serial.println("🔥 Fire Detected by Sensor!");
  } else {
    digitalWrite(buzzer, LOW);
  }
  delay(100); // Small stability delay
}

// --- Robot Movement and Actions ---
void robotMovement() {
  if (digitalRead(Left) == 1 && digitalRead(Right) == 1 && digitalRead(Forward) == 1) {
    moveForward();
  } 
  else if (digitalRead(Forward) == 0) {
    stopMotors();
    fire = true;
  } 
  else if (digitalRead(Left) == 0) {
    turnLeft();
  } 
  else if (digitalRead(Right) == 0) {
    turnRight();
  }

  delay(300);

  // Check Gas (only print, no GSM)
  if (digitalRead(GAS_SENSOR) == 0) {
    Serial.println("⚠️ Gas Detected!");
  }

  // Fire detected - just log it, no extinguishing
  if (fire == true) {
    Serial.println("🔥 Fire Detected - Robot Stopped!");
    fire = false; // Reset fire flag to continue movement
  }
}

// --- Motor Control Functions ---
void moveForward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  Serial.println("🚗 Moving Forward");
}

void stopMotors() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  Serial.println("🛑 Stopped");
}

void turnLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  Serial.println("↩️ Turning Left");
}

void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  Serial.println("↪️ Turning Right");
}
