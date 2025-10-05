/*------ Arduino Fire Fighting Robot ver 2.2 (No GSM) ----*/

#include <Servo.h>

Servo myservo;

// --- Pin Definitions ---
#define Left 4
#define Right 5
#define Forward 6
#define GAS_SENSOR 7
#define LM1 8
#define LM2 9
#define RM1 10
#define RM2 11
#define pump 12
#define fireSensor A1
#define buzzer A0

boolean fire = false;
int pos = 0;

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
  pinMode(pump, OUTPUT);

  myservo.attach(13);
  myservo.write(90);

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
  myservo.write(90);

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

  // Fire handling
  while (fire == true) {
    put_off_fire();
    Serial.println("🔥 Fire Handling Activated!");
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

// --- Extinguishing Fire ---
void put_off_fire() {
  digitalWrite(pump, HIGH);
  delay(500);

  for (pos = 50; pos <= 110; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 110; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }

  digitalWrite(pump, LOW);
  myservo.write(90);
  fire = false;
  Serial.println("💧 Fire Extinguished!");
}
