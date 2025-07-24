
# Verilog HDL Design Tasks — Digital Systems Design 

This project was completed as part of the EE2660 Digital Systems Design module at Brunel University London. It demonstrates the use of Verilog HDL to design, implement, and verify synchronous sequential systems using multiple levels of abstraction.

## 🧠 Assignment Overview

The coursework involved:
- Using Verilog HDL to implement **FSM-based pulse generators**.
- Designing and integrating modules at **gate** and **functional** abstraction levels.
- Creating a **Brunel ID number generator**, **binary to BCD encoder**, and a **parity generator**.
- Verifying functionality via **simulation outputs** and **code-level testing**.

### 🎯 Learning Outcomes Demonstrated

- Top-down digital design methodology
- Hierarchical module abstraction
- Use of Verilog HDL in functional and gate-level formats
- Design partitioning and systems integration
- Use of CAD tools (Quartus Web Edition)

## 🔩 Project Structure

├── src/ # Verilog source files
│ ├── fsm_pulse_generator.v
│ ├── id_number_generator.v
│ ├── binary_to_bcd.v
│ ├── parity_generator.v
│ └── system_top.v
├── simulation/ # Simulation results and testbenches
├── docs/
│ └── final_report.pdf # Formal assignment report (as submitted)
└── README.md


## 📄 Report

The full technical write-up includes:
- Lab reflections
- FSM design and verification
- Gate/functional level partitioned system integration
- Design decisions and testing methodology

📥 [View Report](./docs/final_report.pdf)

## 🧪 Tools & Technologies

- 🛠 Verilog HDL (functional & gate-level)
- 💻 Quartus Web Edition 9.1/11
- 🧾 Intel Horizon Virtual Desktop (optional access)
- 📊 Simulation via internal waveform verification

## 📌 Notes

- All implementations follow the constraints outlined in Assignment 2, including X1/X2/X3 values based on the student ID.
- No automatic synthesis tools or `assign` statements were used where prohibited.
- Each module was designed, tested, and then integrated into the final gate-level wrapper.

---

### 🚀 How to Use

To simulate or test these modules:
1. Open Quartus Web Edition.
2. Create a new project and import files from `src/`.
3. Assign the top-level module as `system_top.v`.
4. Compile and simulate using included testbenches (if available in `/simulation/`).

---

### 📬 Contact

**Y. Benjamin Perez Condori**  
Computer Systems Engineering – Brunel University London  
📧 y.benjamin_pc@hotmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/ybenjaminpc/)
