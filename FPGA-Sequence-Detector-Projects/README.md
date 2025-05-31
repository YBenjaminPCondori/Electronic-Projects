# Sequence Detector on FPGA – VHDL Project (EE3635)

## 🎯 Project Overview

This project was developed as part of the **Embedded Systems** module (EE3635) at Brunel University London. The task involved designing, simulating, and implementing a **sequence detector finite state machine (FSM)** using **VHDL** on the **NEXYS FPGA development board** via **Xilinx Vivado**.

The system was designed from scratch using RTL techniques and demonstrates both **sequential logic design** and **real-world considerations** like **debouncing** and **power consumption analysis**.

---

## 🧠 Learning Objectives Demonstrated

- Design and simulation of **state machines** in VHDL
- FSM modeling and **sequence recognition** implementation
- Use of **clock dividers** and signal visualization
- Understanding and mitigation of **switch bouncing**
- **Power estimation** and optimization using Vivado tools
- Real-time deployment and testing on FPGA hardware

---

## ⚙️ Tools & Technologies

- 🧠 **VHDL (RTL Design)**
- 🧰 **Xilinx Vivado Design Suite**
- 🔲 **NEXYS A7 FPGA Board**
- 📉 Vivado Power Estimator
- 🧪 Simulation (Vivado Waveform Viewer)

---

## 📁 Repo Structure

├── src/
│ ├── sequence_detector.vhd # Main FSM VHDL code
│ ├── clock_divider.vhd # Clock division module
│ ├── debouncer.vhd # Debounce filter
│ └── tb_sequence_detector.vhd # Testbench for simulation
├── simulation/
│ └── waveform_results.png # Sample simulation output
├── docs/
│ └── EE3635_report.pdf # Technical report with design, analysis, and results
└── README.md


---

## 🔧 System Components

- **FSM Design**: Recognizes a specific binary sequence (e.g. `1011`) and transitions through states based on input bit stream.
- **Debouncer Module**: Filters switch input to prevent false triggering due to mechanical bouncing.
- **Clock Divider**: Slows the system clock for visual verification on the board (e.g. LED outputs).
- **Output Indicators**: State transitions and detection events visualized via onboard LEDs.

---

## 📉 Power & Timing Analysis

Vivado’s integrated tools were used to:
- Estimate **static and dynamic power consumption**
- Analyze **timing constraints**
- Validate **resource utilization** (LUTs, FFs, IOBs)

---

## 🎓 Report & Results

📄 [View Full Report](./docs/EE3635_report.pdf)

Includes:
- State diagrams and FSM transition tables
- RTL schematics and waveform outputs
- Timing calculations and power estimation
- Debouncing methodology and design trade-offs

---

## 🚀 Demonstration

The design was synthesized and deployed on the NEXYS FPGA. The FSM successfully detected the intended input sequence and lit the output LED on detection. Switch inputs were debounced to ensure reliable transitions.

---

## 🔐 IP Disclaimer

This project was developed solely for academic purposes. All code and analysis are original. No proprietary materials were used or shared.

---

## 👤 Author

**Y. Benjamin Perez Condori**  
BEng Computer Systems Engineering  
Brunel University London  
📧 y.benjamin_pc@hotmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/ybenjaminpc/)

