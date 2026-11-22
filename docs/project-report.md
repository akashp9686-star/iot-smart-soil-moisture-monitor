# Project Report: Smart Home Energy Meter

## 1. Introduction
The project presents a connected energy-monitoring design built around an ESP32 controller and a PZEM-004T v3 energy-metering module. The meter provides electrical measurements to the controller through a serial interface. The ESP32 validates the values, reports them locally, and can optionally publish telemetry to an MQTT broker.

## 2. Problem Statement
Household users may benefit from visibility into electrical parameters and accumulated energy consumption. A compact connected monitor can make these readings available to a local display, serial console or network dashboard. This repository documents a software design for that purpose; it does not claim a certified meter or a completed mains installation.

## 3. Objectives
- Acquire voltage, current, active power, accumulated energy, frequency and power factor from the PZEM module.
- Use ESP32 hardware UART for the low-voltage serial interface.
- Reject missing, non-finite or broadly implausible readings.
- Provide optional MQTT JSON telemetry.
- Keep secrets out of source control.
- Provide repeatable firmware compilation and sample-data checks.

## 4. Proposed System
The PZEM module performs the electrical measurement. Its TTL serial interface connects to ESP32 UART2 using configurable pins. Firmware periodically requests measurements, checks the returned values and prints valid readings. If MQTT is enabled, the ESP32 connects to Wi-Fi and publishes a JSON message to the configured topic.

## 5. Hardware and Software
**Proposed hardware:** ESP32 DevKit / ESP32-WROOM-32 class board and a compatible PZEM-004T v3 module with its specified interface accessories.

**Software:** Arduino framework, PlatformIO, PZEM-004T-v30 library and PubSubClient MQTT library.

The exact board and meter revision must be confirmed against their official documentation before any physical wiring.

## 6. Firmware Operation
1. Initialize Serial Monitor and UART2.
2. If enabled, connect to Wi-Fi and configure the MQTT broker.
3. At the configured interval, read the six meter parameters.
4. Reject invalid or out-of-range samples.
5. Print valid readings to Serial Monitor.
6. If MQTT is enabled and connected, publish a JSON payload.

## 7. Verification Performed
The hosted GitHub Actions workflow successfully compiled the ESP32 firmware and ran two Python unit tests for the example CSV schema and broad numeric ranges. These are software/repository checks only.

## 8. Verification Not Performed
No physical ESP32/PZEM setup, mains installation, calibration, reference-instrument comparison, live Wi-Fi connection or MQTT broker delivery test was performed. The CSV data is illustrative and must not be presented as measured output.

## 9. Safety and Limitations
Mains voltage can cause fatal shock or fire. Mains-side installation must be designed and completed by a qualified electrician using the exact module documentation, suitable protection and a rated enclosure. The firmware is not a protective device or billing-grade certified meter. See [safety.md](safety.md) and [limitations.md](limitations.md).

## 10. Conclusion
The repository provides a reproducible ESP32 firmware build, optional MQTT telemetry structure, technical documentation and transparent verification records. It is suitable for source-code and design review. Hardware performance and electrical safety remain unverified until appropriate physical testing is carried out by qualified personnel.
