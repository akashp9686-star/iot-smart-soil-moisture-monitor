# Repository Review Checklist — Glowlogics Project 03

## Handbook alignment
- [x] Problem statement: monitor soil moisture and upload readings to ThingSpeak
- [x] Arduino Uno R3 and analog soil sensor on A0
- [x] ESP8266 ESP-01 controlled using UART AT commands on D10/D11
- [x] Logic-level conversion required for Uno/ESP-01 UART
- [x] Red LED on D6 and green LED on D7, each with 220Ω resistor
- [x] ThingSpeak Field 1 moisture percentage
- [x] Handbook example threshold (30%) and interval (20 seconds)

## Repository quality
- [x] Firmware and PlatformIO Uno target
- [x] Private credential template and ignore rule
- [x] README, abstract, report, architecture and component inventory
- [x] Wiring, methodology, research, calibration limitations and safety
- [x] Evaluator guide, requirements traceability and results template
- [x] Illustrative sample CSV and schema/range tests
- [x] GitHub Actions compile workflow

## Verification still required
- [ ] Latest hosted firmware build completes successfully
- [ ] Sensor dry/wet endpoints calibrated on the actual sensor
- [ ] Red/green LED threshold behavior physically verified
- [ ] ESP-01 AT firmware, baud rate, power and Wi-Fi verified
- [ ] Live ThingSpeak Field 1 update verified
- [ ] Add genuine dated photographs and measured results

Illustrative CSV is test data, not hardware evidence. Do not mark physical checks complete until performed.
