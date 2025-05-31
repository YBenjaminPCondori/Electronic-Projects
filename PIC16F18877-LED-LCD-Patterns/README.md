# Assembly Programming Design – PIC16F18877 Microcontroller

## 🎯 Project Overview

This project was developed as part of the EE2659 Microcontroller Principles module at Brunel University. It demonstrates the use of **assembly language programming** on a PIC16F18877 microcontroller to control input/output components such as switches, LEDs, 7-segment displays, and an LCD.

The work was completed on the **Matrix Multimedia PIC Micro Development Board (eBlock 2)** using **MPLAB X IDE**, the **XC8 assembler**, and the **mLoader programmer**.

---

## 🧠 Learning Objectives Demonstrated

- Embedded systems design using low-level assembly programming
- Direct port manipulation and memory register usage
- Implementation of I/O systems including:
  - Switch and lamp control
  - LED light patterns
  - Delay routines and timing
  - 7-segment display encoding
  - LCD interfacing with ASCII control
- Debugging and verifying embedded code on real hardware

---

## 🛠 Tools & Technologies

- 🧠 PIC16F18877 Microcontroller
- 🛠 MPLAB X IDE + XC8 Assembly Compiler
- 🧩 mLoader programming tool
- 🖥 Assembly language (.s files)
- 🧾 Matrix eBlock 2 development board

---

## 📁 Repo Structure

├── src/
│ ├── exercise1_switch_to_led.asm
│ ├── exercise2_flash_leds.asm
│ ├── exercise3_button_patterns.asm
│ ├── exercise4_single_7seg.asm
│ ├── exercise5_multi_7seg.asm
│ ├── exercise6_lcd_display.asm
│ └── common_macros.inc
├── docs/
│ └── EE2659_report.pdf # Final technical report
└── README.md


---

## 🧪 Exercise Summary

### 🔹 Exercise 1: Switch-to-LED Control
- Mapped switches on PORTA to directly control LEDs on PORTB.
- Introduced basic I/O configuration and memory banking.

### 🔹 Exercise 2: Flashing LEDs with Timing Control
- Designed a loop-based delay function in assembly.
- Measured and calculated total clock cycles for accurate timing.

### 🔹 Exercise 3: Button-Controlled Light Patterns
- Implemented directional LED animations based on button presses.
- Added switch priority logic using conditional branches and delays.

### 🔹 Exercise 4: Single 7-Segment Display
- Created a lookup table to encode digits 0–9.
- Converted numerical input to 7-segment format using RETLW instructions.

### 🔹 Exercise 5: Four-Digit 7-Segment Display
- Displayed the last four digits of student ID using multiplexed display logic.
- Controlled PORTA pins to activate each digit sequentially.

### 🔹 Exercise 6: LCD Display Integration
- Wrote initialization, data, and command subroutines for LCD.
- Displayed first and last name on a two-line LCD using ASCII encoding.

---

## 📄 Report

📥 [View Full Report](./docs/EE2659_report.pdf)

The report includes:
- System diagrams, design flowcharts, and register mapping
- Code breakdowns and reasoning
- Test results with photos/screenshots from the hardware
- Calculated delay routines and I/O timing

---

## 🔐 IP Disclaimer

This project is original coursework submitted for EE2659. All code and analysis were developed independently. No proprietary hardware or firmware was copied.

---

## 👤 Author

**Y. Benjamin Perez Condori**  
BEng Computer Systems Engineering  
Brunel University London  
📧 y.benjamin_pc@hotmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/ybenjaminpc/)
