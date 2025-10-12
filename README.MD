# 🔥 Fire Detection Robot v2.2

A simple Arduino-based **Fire Detection Robot** that can automatically detect fire and navigate autonomously while alerting through a buzzer.
This version **does not use GSM** and focuses purely on fire detection and navigation, making it easy for beginners to build with basic components.

---

## 📌 Features

* 🚗 Autonomous movement using IR sensors (Forward, Left, Right).
* 🔥 Fire detection using flame sensor.
* ⚠️ Gas detection with MQ-series gas sensor.
* 🔊 Buzzer alerts when fire is detected.
* 📟 Serial Monitor logging for debugging.

---

## 🛠️ Hardware Requirements

| Component                                 | Quantity                          | Notes                     |
| ----------------------------------------- | --------------------------------- | ------------------------- |
| Arduino UNO / Nano                        | 1                                 | Main controller           |
| L293D Motor Driver or Motor Driver Module | 1                                 | To control motors         |
| DC Motors + Wheels                        | 2–4                               | For movement              |
| Flame Sensor (IR flame detector)          | 1                                 | Detects fire              |
| Gas Sensor (MQ-2 / MQ-5 / MQ-7)           | 1                                 | Detects gas leakage       |
| IR Line/Obstacle Sensors                  | 3                                 | Forward, Left, Right      |
| Buzzer                                    | 1                                 | Fire alert                |
| Power Supply                              | 12V Battery (or 7.4V Li-ion Pack) | To power motors + Arduino |
| Chassis                                   | 1                                 | Any 2WD/4WD robot chassis |
| Jumper wires, breadboard, and connectors  | —                                 | For wiring                |

---

## 📡 Pin Configuration

| Pin  | Component         |
| ---- | ----------------- |
| `4`  | Left IR Sensor    |
| `5`  | Right IR Sensor   |
| `6`  | Forward IR Sensor |
| `7`  | Gas Sensor        |
| `8`  | Left Motor IN1    |
| `9`  | Left Motor IN2    |
| `10` | Right Motor IN1   |
| `11` | Right Motor IN2   |
| `A0` | Buzzer            |
| `A1` | Fire Sensor       |

---

## ⚙️ Working Principle

1. **Fire Detection**

   * The flame sensor detects fire.
   * When fire is detected, the buzzer starts ringing.

2. **Movement Control**

   * IR sensors help the robot avoid obstacles and move forward.
   * If an obstacle is in front, the robot stops and logs fire detection.
   * If left or right sensors detect a path, the robot turns accordingly.

3. **Fire Alert System**

   * When fire is detected ahead, the robot stops and alerts via buzzer.
   * Fire detection is logged to Serial Monitor.
   * Robot resumes normal operation after detection.

4. **Gas Detection**

   * If the gas sensor detects leakage, a warning is printed in Serial Monitor.

---

## 💻 Software Setup

1. Install [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect Arduino UNO/Nano via USB.
3. Copy the code (`FireFightingRobot.ino`) into Arduino IDE.
4. Select correct **Board** (Arduino UNO/Nano) and **Port**.
5. Upload the code.

---

## 🚀 Usage

1. Place robot on ground with free movement area.
2. Power ON the robot (motors + Arduino).
3. Open **Serial Monitor** (115200 baud) for debugging messages.
4. The robot will:

   * Move forward by default.
   * Stop and alert if fire is detected.
   * Sound buzzer on fire detection.
   * Print "Gas Detected!" if gas sensor triggers.

---

## 📷 Example Robot Assembly

* 🔲 Chassis with DC motors and motor driver.
* 🔥 Flame sensor in front.
* ⚠️ Gas sensor mounted on top/front.
*  Buzzer on chassis.
* 🔋 Battery securely mounted.