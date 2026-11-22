# Requirements Traceability — Handbook Project 06

| ID | Handbook requirement | Repository evidence | Status |
|---|---|---|---|
| R1 | Arduino Uno controller | `platformio.ini`, `src/main.cpp` | Implemented in source |
| R2 | ACS712-20A current sensor | Analog input A1; RMS estimate | Implemented; calibration pending |
| R3 | ESP8266 ESP-01 | SoftwareSerial D10/D11 and AT commands | Implemented; module test pending |
| R4 | Logic-level conversion | Wiring guide: Uno TX to ESP-01 RX | Documented; inspect hardware |
| R5 | 16x2 I2C LCD | SDA A4 / SCL A5 | Implemented; display test pending |
| R6 | 10µF capacitor | Component inventory and wiring note | Exact placement to confirm from module schematic |
| R7 | ThingSpeak upload | Field 1 current A; Field 2 estimated apparent VA | Implemented; live upload pending |
| R8 | Safety documentation | `docs/safety.md` | Documented |
| R9 | Reproducible Uno build | GitHub Actions workflow | Check latest run |
| R10 | Honest validation record | `docs/testing.md` | Physical tests marked pending |

Compilation does not establish physical compatibility, calibration, mains safety or cloud operation.