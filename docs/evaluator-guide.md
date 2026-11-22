# Evaluator Guide — Glowlogics Project 03

1. Compare the project statement and component inventory with the handbook's Project 03 entry.
2. Review the Uno firmware in [src/main.cpp](../src/main.cpp).
3. Review the exact pin mapping in [wiring.md](wiring.md): sensor A0, ESP-01 UART D10/D11, red LED D6, green LED D7.
4. Review ESP-01 AT command and ThingSpeak Field 1 implementation.
5. Review calibration assumptions and the 30% dry threshold.
6. Check the latest hosted Uno build in the repository's GitHub Actions tab.
7. Review [testing.md](testing.md) for the distinction between software build verification and physical hardware tests.

The firmware and repository target the handbook's Project 03 design. Physical sensor calibration, LED behavior, ESP-01 Wi-Fi and live ThingSpeak delivery remain unverified until tested on hardware.
