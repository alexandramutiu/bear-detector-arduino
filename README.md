# Bear Detector Arduino Project

> *"Because your garbage deserves protection too."*

## What is this?

An Arduino-powered security system that detects when a bear (or any large intruder) gets too close to your trash bins — and scares it away with lights and noise.

No bears were harmed in the making of this project. 🐻💨

---

## How it works

```
Bear approaches bin
        ↓
HC-SR04 detects it within 150cm
        ↓
Red LED flashes 🔴
White LED floods the area 💡
Buzzer goes crazy 🔊
        ↓
Bear panics and runs away
        ↓
Alarm turns off automatically
        ↓
Your garbage is safe 🗑️✅
```

---

## Components

| Component | Purpose |
|---|---|
| Arduino Uno | The brain  |
| HC-SR04 | Detects the bear  |
| Red LED + 220Ω | Flashing alarm  |
| White LED + 220Ω | Flood light  |
| Active Buzzer | Makes noise  |

---

## Wiring

| Component | Pin | Arduino |
|---|---|---|
| HC-SR04 | VCC | 5V |
| HC-SR04 | TRIG | D2 |
| HC-SR04 | ECHO | D3 |
| HC-SR04 | GND | GND |
| Red LED | Anode + | D7 |
| Red LED | Cathode − | GND |
| White LED | Anode + | D8 |
| White LED | Cathode − | GND |
| Buzzer | + | D9 |
| Buzzer | − | GND |

<img width="1406" height="746" alt="Image" src="https://github.com/user-attachments/assets/970ad8a8-85ab-481b-adee-bef49465d55e" />

---


## Getting started

1. Wire everything up according to the table above
2. Open `bear_detector.ino` in Arduino IDE
3. Upload to your Arduino Uno
4. Point the sensor at your bin
5. Wait for a bear 🐻

---

## Built with

- 💙 Arduino
- 📡 Ultrasonic waves
- 🔴 The power of blinking lights
- ☕ Coffee

---

*Built as a school project. Bears, please stay away from the bins.*
