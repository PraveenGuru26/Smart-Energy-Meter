# 🔌 Smart Energy Meter

A microcontroller-based smart energy monitoring system that reads electrical parameters using Modbus RTU, transmits data via GSM/GPRS, and supports cloud logging and SMS alerts.

---

## 📌 Features

- Real-time monitoring of:
  - ⚡ Voltage (Line-to-Line & Line-to-Neutral)
  - 🔌 Current (per phase and total)
  - 🔋 Power (Watt, VA), Frequency
  - ⚖️ Power Factor (per phase and average)
  - 📈 Energy Consumption (kWh, VAh)
- Communication with energy meter via RS-485 (Modbus RTU)
- Cloud-based data push using HTTP via SIM800/SIM900 module
- Remote configuration and data fetching
- SMS alerts via GSM module

---

## 📁 File Overview

| File             | Description                                                   |
|------------------|---------------------------------------------------------------|
| `Energy-meter.ino`   | Main Arduino sketch handling data collection and integration |
| `mb_getdata.h`       | Functions for Modbus communication using MAX485            |
| `push_data_int.h`    | GPRS communication, HTTP data push, SMS sending via SIM800 |
| `values.h`           | Global variables for voltage, current, power, energy, etc.  |

---

## 🔧 Hardware Requirements

- Arduino Mega 2560 (or compatible)
- Energy Meter with Modbus RTU (RS-485) support
- MAX485 TTL to RS-485 Module
- SIM800/SIM900 GSM/GPRS Module
- I2C 16x2 LCD (optional, for local display)
- 12V Power Adapter

---

## 🔌 Wiring Diagram

_Wiring connections:_
- **MAX485 Module**
  - RO → Arduino RX1 (Pin 19)
  - DI → Arduino TX1 (Pin 18)
  - DE & RE tied together → Pin 2
  - A/B → Energy meter RS-485 A/B

- **SIM800 Module**
  - TX → Arduino RX2 (Pin 17)
  - RX → Arduino TX2 (Pin 16)
  - Power → 12V regulated supply

- **LCD (I2C)**
  - SDA → Pin 20
  - SCL → Pin 21

- **Arduino Power**
  - VIN → 12V Adapter

> 📷 See wiring diagram image in repository.

---

## 📡 Server API (Example)

- **Fetch threshold data:**
- GET http://13.233.93.242/projects/energy/api/get-max.php?mid=101
- **Push readings to server:**
- GET http://13.233.93.242/projects/energy/api/log.php?mid=101&machine=$DATA
- 
> Replace URL parameters accordingly.

---

## 🚀 Getting Started

1. Clone the repository:
 ```bash
 git clone https://github.com/your-username/smart-energy-meter.git

