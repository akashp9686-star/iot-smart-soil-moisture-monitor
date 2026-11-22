# Limitations and Known Risks

- This repository has not been tested with a physical ESP32 or PZEM-004T module.
- The exact PZEM module revision and terminal arrangement must be confirmed.
- The example UART pins are defaults and may need adjustment for a specific ESP32 board.
- Broad firmware plausibility bounds are not calibration limits.
- The code does not implement a certified billing-grade measurement system.
- MQTT is optional and disabled by default.
- The example MQTT transport is not TLS-secured; deployment requires a security review.
- Wi-Fi/MQTT outages may interrupt telemetry; no durable offline queue is implemented.
- The sample CSV contains illustrative values, not measured data.
- This project is not a protective relay, circuit breaker, or safety device.
- Physical accuracy, electrical isolation, enclosure safety and regulatory compliance are not established by a successful software build.
