<h1 align="center">🤖 Line Following Robot</h1>

<p align="center">
  <em>A robotic system that autonomously follows a black line path using IR sensors, motor drivers, and an embedded microcontroller.</em>
</p>

<p align="center">
  <strong>BEng Computer Systems Engineering | Brunel University London</strong>
</p>

<hr/>

## 📌 Project Summary

This project demonstrates a **line-following mobile robot** that uses **infrared (IR) sensors** to detect contrast between a black line and a white surface.  
The microcontroller processes sensor inputs and adjusts the **DC motor speeds** via a motor driver (H-Bridge) to follow the path smoothly.  

- ✅ Autonomous path tracking using **IR reflectance sensors**  
- ✅ **PID (Proportional–Integral–Derivative) control** for smoother turns  
- ✅ Modular design for expansion into obstacle avoidance or maze solving  

---

## 🎯 Objectives

<p align="center">
  <img src="../line_following_robot_diagram.png" alt="System Overview" width="600"/>
</p>

- Implement a reliable line-tracking algorithm  
- Maintain stability in straight paths and sharp turns  
- Demonstrate embedded control using **C/Embedded C**  
- Build a scalable robotic platform for future AI/IoT integration  

---

## 🛠️ Hardware Components

| Component | Purpose |
|-----------|---------|
| **Microcontroller (e.g., Arduino Uno / PIC16F)** | Processes sensor inputs and controls motors |
| **IR Sensor Array (3–5 sensors)** | Detects black line vs. white background |
| **L293D / L298N Motor Driver** | Controls motor direction and speed |
| **DC Motors with Wheels** | Provides movement |
| **Chassis** | Mechanical structure |
| **Battery Pack (7.4V–12V)** | Power supply |

---

## 🗂️ Software & Algorithm

- **Language**: Embedded C (Arduino IDE / MPLAB)  
- **Control Algorithm**:  
  - Thresholding IR sensor values  
  - Motor adjustment using proportional or PID logic  

```c
if (leftSensor == 1 && rightSensor == 0) {
    turnLeft();
}
else if (leftSensor == 0 && rightSensor == 1) {
    turnRight();
}
else {
    moveForward();
}

