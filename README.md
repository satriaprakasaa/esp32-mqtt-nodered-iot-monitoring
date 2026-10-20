# 🌐 Real-Time IoT Environmental Monitoring System (ESP32 + MQTT + Node-RED)

![Tools](https://img.shields.io/badge/Hardware-ESP32%20%7C%20DHT22-green)
![Protocols](https://img.shields.io/badge/Protocol-MQTT%20%7C%20JSON-blue)
![Dashboard](https://img.shields.io/badge/Dashboard-Node--RED%20%7C%20Dark%20Theme-red)

## 📌 Overview
Proyek ini mengimplementasikan sistem pemantauan suhu dan kelembapan lingkungan secara real-time berbasis Internet of Things (IoT). Simulasi mikrokontroler ESP32 membaca data telemetri dari sensor DHT22, mengirimkan payload berformat JSON ke broker MQTT publik HiveMQ, dan menampilkan visualisasi data pada Dashboard Node-RED berdesain Dark Theme / Modern UI.

---

## 🛠️ Tech Stack & Tools
- **Hardware Simulation:** ESP32 & Sensor DHT22 (Wokwi Simulator)
- **Programming Language:** C++ (Arduino Framework) & JavaScript (Node-RED Function Node)
- **Communication Protocol:** MQTT (`broker.hivemq.com` Port 1883)
- **Data Format:** JSON Payload (`{"nama": "...", "suhu": float, "kelembapan": float}`)
- **Dashboard Platform:** Node-RED Dashboard 2.0 (Dark Theme UI)

---

## 📐 System Architecture & Data Flow

1. **Hardware Telemetry:** Sensor DHT22 membaca data lingkungan, lalu mikrokontroler ESP32 mengemas data tersebut menjadi payload JSON.
2. **MQTT Broker Transmission:** ESP32 mempublikasikan data secara real-time ke broker HiveMQ publik (`broker.hivemq.com`) melalui topik `sistel/iot/dht2`.
3. **Data Parsing & Visualization:** Node-RED memproses pesan JSON yang masuk dan mengumpankannya ke widget Gauge serta Chart pada Dashboard UI.

---

## 📷 Project Preview

<table>
  <tr>
    <td align="center"><b>ESP32 Circuit Simulation (Wokwi)</b></td>
    <td align="center"><b>Node-RED Dashboard UI (Dark Theme)</b></td>
  </tr>
  <tr>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/848de606-8082-42be-910f-df44ac8a50aa" width="100%" alt="Wokwi Simulation">
    </td>
    <td align="center">
      <img src="Screenshot%202026-10-16%20101815.png" width="100%" alt="Node-RED Dashboard">
    </td>
  </tr>
</table>
