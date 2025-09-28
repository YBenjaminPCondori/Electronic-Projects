<h1 align="center">🔧 Assembly Programming Design – PIC16F18877 Microcontroller</h1>

<p align="center">
  <em>This repository demonstrates advanced assembly language programming on the PIC16F18877 microcontroller, featuring I/O control systems including LEDs, 7-segment displays, and LCD interfaces.</em>
</p>

<p align="center">
  <strong>BEng Computer Systems Engineering | Brunel University London | EE2659 Module</strong>
</p>

<hr/>

## 📌 Project Summary

This system showcases **low-level embedded programming** using assembly language on the PIC16F18877 microcontroller to control various input/output components including switches, LEDs, 7-segment displays, and LCD modules.

- ✅ Built for **Matrix Multimedia PIC Micro Development Board (eBlock 2)**
- ✅ Developed using **MPLAB X IDE** with **XC8 assembler**
- ✅ Programmed via **mLoader** programming tool
- ✅ Demonstrates direct hardware manipulation and timing control

---

## 🎯 Objectives

- Implement **embedded systems design** using low-level assembly programming
- Master **direct port manipulation** and memory register usage
- Develop **I/O control systems** for multiple hardware components
- Create **timing-critical applications** with precise delay routines
- Interface with **display technologies** including 7-segment and LCD
- Validate and debug **real-world hardware implementations**

---

## 🗂️ Hardware Components

| Component | Type | Purpose |
|-----------|------|---------|
| PIC16F18877 | Microcontroller | Main processing unit |
| eBlock 2 | Development Board | Hardware platform |
| LEDs | Output Display | Visual feedback and patterns |
| 7-Segment | Numeric Display | Multi-digit number representation |
| LCD | Text Display | ASCII character output |
| Switches | Input Control | User interaction interface |

---

## 🛠️ Development Environment

- **Microcontroller**: PIC16F18877 (8-bit architecture)
- **IDE**: MPLAB X IDE with XC8 Assembly Compiler
- **Programmer**: mLoader programming tool
- **Language**: Assembly (.asm files)
- **Platform**: Matrix Multimedia eBlock 2 development board

---

## 🧠 System Architecture

<p align="center">
  <em>Low-level assembly programming for direct hardware control and I/O manipulation</em>
</p>

- **Programming Language**: Assembly (direct register manipulation)
- **Memory Architecture**: Harvard architecture with separate program/data memory
- **I/O Control**: Direct port configuration and bit manipulation
- **Timing Systems**: Loop-based delay functions with calculated clock cycles

---

## 📦 Project Files

| File | Language | Purpose |
|------|----------|---------|
| lab_task1.c | Assembly | Switch-to-LED control mapping |
| lab_task2.c | Assembly | Flashing LED patterns with timing |
| lab_task3.c | Assembly | Button-controlled directional animations |
| lab_task4.c | Assembly | Single 7-segment display encoding |
| lab_task5.c | Assembly | Multi-digit 7-segment multiplexing |
| lab_task6.c | Assembly | LCD initialization and text display |
| lab_task7.c | Assembly | Advanced pattern control |
| lab_task8.c | Assembly | Integrated system demonstration |


---

## 📊 Implementation Features

### ✅ Task 1: Switch-to-LED Control System
- Direct **PORTA-to-PORTB mapping** for real-time input/output control
- Basic **I/O configuration** and **memory banking** implementation
- Foundation for port manipulation techniques

### ✅ Task 2: Precision Timing Control
- **Loop-based delay functions** with calculated clock cycle timing
- Accurate **timing control** for flashing LED patterns
- Mathematical timing verification and optimization

### ✅ Task 3: Interactive Pattern Control
- **Button-controlled directional LED animations** with priority logic
- **Conditional branching** and **state management** in assembly
- Real-time user input processing and response

### ✅ Task 4: 7-Segment Display Encoding
- **Lookup table implementation** for digits 0–9 encoding
- **RETLW instruction usage** for efficient data retrieval
- Numerical-to-display format conversion

### ✅ Task 5: Multiplexed Display System
- **Four-digit 7-segment multiplexing** with sequential activation
- **Time-division multiplexing** for multi-digit display control
- Student ID display implementation

### ✅ Task 6: LCD Interface Programming
- Complete **LCD initialization sequences** and **command protocols**
- **ASCII character display** with two-line text output
- Advanced peripheral interfacing and control

---

## � Technical Specifications

| Specification | Details |
|---------------|---------|
| **Architecture** | 8-bit Harvard architecture |
| **Clock Speed** | Configurable internal oscillator |
| **Memory** | Separate program and data memory spaces |
| **I/O Ports** | Direct port manipulation (PORTA, PORTB, etc.) |
| **Programming** | Low-level assembly with direct register access |

---

## 📦 Requirements

**Hardware Requirements:**
```
- PIC16F18877 Microcontroller
- Matrix Multimedia eBlock 2 Development Board
- LEDs, 7-segment displays, LCD module
- Connection cables and breadboard components
```

**Software Requirements:**
```
- MPLAB X IDE (latest version)
- XC8 Compiler with Assembly support
- mLoader Programming Tool
```

� *Assembly programming requires direct hardware access and cannot be simulated effectively without the physical development board.*

---

## ▶️ Programming Instructions

1. **Setup Hardware**: Connect the Matrix eBlock 2 development board with all required components
2. **Open MPLAB X**: Load the project files (.asm) into MPLAB X IDE
3. **Compile**: Use XC8 assembler to compile the assembly source code
4. **Program**: Use mLoader to flash the compiled code to the PIC16F18877
5. **Test**: Verify functionality on the physical hardware setup

---

## 📄 Documentation

📥 **[Technical Report](./docs/EE2659_report.pdf)** - Complete project documentation including:
- 📐 System diagrams and design flowcharts
- 🧠 Register mapping and memory organization
- 🔍 Code analysis and implementation details
- 📸 Hardware testing results with photos
- ⏱️ Timing calculations and verification

---

## 🚀 Learning Outcomes

- Mastery of **low-level embedded programming** using assembly language
- Understanding of **microcontroller architecture** and direct hardware control
- Implementation of **real-time systems** with precise timing requirements
- Experience with **professional embedded development tools** and workflows

---

## 📚 Citation

```
Y. B. Perez Condori, "Assembly Programming Design – PIC16F18877 Microcontroller," 
EE2659 Microcontroller Principles, Brunel University London, 2025.
```

---

## � License

MIT License – Free to use, modify, and distribute for educational purposes.

---

## 🔐 Academic Integrity

This project represents original coursework submitted for EE2659. All code and analysis were developed independently following academic integrity guidelines.  
BEng Computer Systems Engineering  
Brunel University London  
📧 y.benjamin_pc@hotmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/ybenjaminpc/)
