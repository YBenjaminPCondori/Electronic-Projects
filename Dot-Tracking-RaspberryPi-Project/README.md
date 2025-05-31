# Real-Time Video Tracking System with Raspberry Pi & Edge Processing

## 🎯 Project Overview

This project was completed as part of the EE3625/EE3640 modules at Brunel University London. It focuses on developing a **real-time video streaming and image processing pipeline** using Raspberry Pi devices and optional edge cloud resources.

The system detects the position of a red dot in a video feed and communicates movement directions across a networked system using Python-based socket communication.

---

## ⚙️ System Description

The architecture consists of:
- **Remote Raspberry Pi** with a webcam for video capture.
- **Local Raspberry Pi / PC / Edge Cloud Function** for:
  - Receiving the video stream
  - Performing image processing to detect red dot movement (Δx, Δy)
  - Sending position feedback back to the source

Communication and processing occur in real-time, enabling closed-loop direction feedback.

📊 The project was deployed in **three configurations**:
1. RPi ➝ RPi
2. RPi ➝ PC
3. RPi ➝ Edge Cloud (Linux-based)

---

## 🧠 Learning Objectives Demonstrated

- Networked video streaming with Python and OpenCV
- Real-time object tracking using color detection
- Socket-based communication protocols (UDP/TCP)
- Performance measurement using Wireshark
- Deployment to Multiaccess Edge Cloud environments

---

## 🧪 Tools & Technologies

- 🔴 OpenCV (Red Dot Detection)
- 🧠 Python (Socket Programming, Image Processing)
- 📡 UDP/TCP Network Streaming
- 🐍 Raspbian OS (Linux)
- 📈 Wireshark (Throughput, Delay, Jitter Analysis)

---

## 📁 Repo Structure

├── src/
│ ├── capture_and_stream.py # Video capture and stream sender (Remote RPi)
│ ├── receive_and_process.py # Video receiver and red dot tracker
│ ├── position_feedback_sender.py # Position sender
│ └── utils/ # Helper scripts and processing functions
├── docs/
│ └── final_report.pdf # Technical report with system architecture and analysis
├── videos/
│ ├── rpi_to_rpi_demo.mp4
│ ├── rpi_to_pc_demo.mp4
│ └── rpi_to_edge_demo.mp4
└── README.md


---

## 📊 Performance Results

- Packet throughput and jitter were captured using **Wireshark**
- Performance compared across all three configurations
- Results visualized in the report (see `/docs/final_report.pdf`)

---

## 🎥 Demonstration

Each system configuration is demonstrated in recorded video clips. These include:
- Video capture and transmission
- Red dot detection and position analysis
- Real-time feedback to the source device

---

## 📝 Report

📄 [View Full Report](./docs/final_report.pdf)

Contains:
- System diagrams and descriptions
- Flowcharts and sequence diagrams
- Wireshark analysis
- Critical evaluation of each configuration

---

## 🔐 Note on IP

This project was developed independently for academic purposes. No proprietary or NDA-bound information is included in this repository.

---

## 👤 Author

**Y. Benjamin Perez Condori**  
BEng Computer Systems Engineering  
Brunel University London  
📧 y.benjamin_pc@hotmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/ybenjaminpc/)

