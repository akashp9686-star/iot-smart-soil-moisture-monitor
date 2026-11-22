# Evaluator Guide — Glowlogics Project 06

1. Read the current scope and verification statement in [README.md](../README.md).
2. Review the project report in [project-report.md](project-report.md).
3. Inspect Arduino Uno firmware in [src/main.cpp](../src/main.cpp).
4. Check PlatformIO target and dependency in [platformio.ini](../platformio.ini).
5. Review the hardware inventory, pin map, architecture and safety boundaries in [components.md](components.md), [wiring.md](wiring.md), [architecture.md](architecture.md) and [safety.md](safety.md).
6. Review the ThingSpeak data model and measurement limitations in [data-format.md](data-format.md) and [limitations.md](limitations.md).
7. Review technical research and requirements traceability.
8. Check the latest GitHub Actions result at https://github.com/akashp9686-star/smart-home-energy-meter/actions.

## Verification boundary
The repository targets the handbook's Arduino Uno + ACS712-20A + ESP-01 + 16x2 I2C LCD + ThingSpeak design. A successful hosted compile or sample-data test is software-only evidence. Physical current calibration, LCD, ESP-01 Wi-Fi, live ThingSpeak delivery and mains-side installation are not claimed as completed. Mains-side work must be done by a qualified electrician.
