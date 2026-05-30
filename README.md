# QuadBot – WiFi Controlled Quadruped Robot

## Overview

QuadBot is a four-legged robotic platform powered by ESP32 and a PCA9685 servo controller. The robot generates its own WiFi network and hosts a web-based control interface that enables users to control the robot wirelessly using any smartphone, tablet, or computer.

The robot utilizes 12 servo motors distributed across four legs and supports multiple motion commands including Stand, Sit, Forward Movement, and Backward Movement.

This project demonstrates the integration of Embedded Systems, Robotics, Wireless Networking, and Real-Time Motion Control.

---

## Features

### Wireless Robot Control

* ESP32 creates a WiFi Access Point
* No internet connection required
* Direct browser-based control

### Real-Time Motion Control

Supported commands:

* Stand
* Sit
* Forward Walk
* Backward Walk
* Stop

### Web-Based Interface

* Mobile Friendly Dashboard
* One-Touch Controls
* Real-Time Command Execution
* No Mobile Application Required

### Multi-Servo Coordination

* 12 Servo Motors
* 4 Robotic Legs
* 3 Degrees of Freedom per Leg

---

## Hardware Components

| Component                 | Quantity    |
| ------------------------- | ----------- |
| ESP32 Development Board   | 1           |
| PCA9685 Servo Driver      | 1           |
| Servo Motors (SG90/MG90S) | 12          |
| Li-ion Battery Pack       | 1           |
| Chassis / 3D Printed Body | 1           |
| Jumper Wires              | As Required |

---

## System Architecture

User Device
↓
Web Browser
↓
ESP32 WiFi Access Point
↓
Embedded Web Server
↓
PCA9685 Servo Controller
↓
12 Servo Motors
↓
Quadruped Robot

---

## Servo Mapping

### Front Left Leg

Hip → Channel 0

Knee → Channel 1

Ankle → Channel 2

### Front Right Leg

Hip → Channel 3

Knee → Channel 4

Ankle → Channel 5

### Rear Left Leg

Hip → Channel 6

Knee → Channel 7

Ankle → Channel 8

### Rear Right Leg

Hip → Channel 9

Knee → Channel 10

Ankle → Channel 11

---

## ESP32 Connections

| ESP32 Pin | PCA9685 |
| --------- | ------- |
| GPIO21    | SDA     |
| GPIO22    | SCL     |
| 3.3V      | VCC     |
| GND       | GND     |

---

## WiFi Configuration

Access Point Name:

QuadBot

Password:

12345678

After powering the robot:

1. Connect to QuadBot WiFi.
2. Open browser.
3. Enter ESP32 IP address.
4. Control the robot wirelessly.

---

## Motion Functions

### Stand

Places all servos in neutral position.

Hip = 90°

Knee = 90°

Ankle = 90°

---

### Sit

Lowers the robot body by bending knee joints.

---

### Forward Walking

Implements a simple gait pattern by:

* Lifting diagonal legs
* Moving hip joints
* Returning to standing position

---

### Backward Walking

Implements reverse gait motion.

---

## Software Libraries

Required Arduino Libraries:

* WiFi.h
* Wire.h
* Adafruit PWM Servo Driver
* ESP32 Arduino Core

---

## Installation

### Step 1

Install ESP32 Board Package in Arduino IDE.

### Step 2

Install Required Libraries:

* Adafruit PWM Servo Driver

### Step 3

Upload Code to ESP32.

### Step 4

Power the robot.

### Step 5

Connect to QuadBot WiFi network.

### Step 6

Open browser and access the control dashboard.

---

## Applications

* Quadruped Robotics Research
* Autonomous Robotics
* Educational Robotics
* Wireless Robot Control
* Military Surveillance Prototypes
* Search and Rescue Robots
* AI Robotics Platforms

---

## Future Enhancements

* Joystick Control
* Mobile Application
* AI-Based Navigation
* Computer Vision Integration
* Obstacle Avoidance
* Voice Commands
* MQTT Cloud Control
* ROS Integration
* Autonomous Path Planning
* Inverse Kinematics Based Walking

---

## Project Highlights

✔ ESP32 Powered

✔ WiFi Controlled

✔ Browser-Based Dashboard

✔ 12 Servo Coordination

✔ Quadruped Locomotion

✔ Embedded Robotics

✔ Real-Time Motion Control

✔ Expandable Architecture

---

## Author

Hariharan Balakrishnan

B.E Electronics and Communication Engineering

Embedded Systems | Robotics | IoT | Edge AI | ESP32 | Zephyr RTOS
