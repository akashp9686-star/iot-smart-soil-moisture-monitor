# Requirements Traceability Matrix

| ID | Requirement | Implementation / evidence | Verification status |
|---|---|---|---|
| R1 | ESP32 firmware target | `platformio.ini` uses `esp32dev` and Arduino | Firmware build passed |
| R2 | Read six PZEM parameters | `src/main.cpp` reads voltage, current, power, energy, frequency and PF | Compiled; physical serial test not performed |
| R3 | Use configurable UART pins | `include/config.example.h`, UART2 GPIO16/17 defaults | Compiled |
| R4 | Reject invalid readings | Finite and broad range checks in `readMeter` | Compiled; physical sensor fault test not performed |
| R5 | Optional MQTT telemetry | `MQTT_ENABLED` switch and JSON publish function | Compiled with MQTT disabled; live broker not tested |
| R6 | Protect credentials | Local ignored `include/config.h` pattern | Repository inspection |
| R7 | Document electrical hazards | `docs/safety.md` | Documentation review |
| R8 | Reproducible automated build | `.github/workflows/ci.yml` | Passed on GitHub Actions |
| R9 | Validate example dataset | `tests/test_sample_readings.py` | 2 tests passed |
| R10 | Record honest physical results | `docs/results-template.md` | Template included; no physical results claimed |

A compile pass confirms that the configured source builds for the selected PlatformIO target. It does not establish physical compatibility, measurement accuracy, mains safety or MQTT operation.
