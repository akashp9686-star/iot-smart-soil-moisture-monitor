# Smart Home Energy Meter (ESP32 + PZEM-004T)

Repository package for an ESP32-based energy-monitoring node using a PZEM-004T v3 module. Firmware reads voltage, current, active power, accumulated energy, frequency and power factor, with optional MQTT telemetry.

> **Status:** This is a repository-first software and documentation package. No physical meter, mains circuit, calibration, or live MQTT broker was tested during preparation. A passing software build is not a physical or electrical-safety test.

## Objectives
- Read PZEM measurements over ESP32 UART2.
- Reject unavailable or implausible readings.
- Optionally publish JSON telemetry over MQTT.
- Keep Wi-Fi and broker credentials out of version control.
- Document architecture, research, safety, limitations and verification.

## Selected platform

| Layer | Selection |
|---|---|
| Controller | ESP32 DevKit / ESP32-WROOM-32 class |
| Meter | PZEM-004T v3 TTL interface |
| Firmware | Arduino framework with PlatformIO |
| UART | UART2, default RX GPIO16 / TX GPIO17 |
| Telemetry | Optional MQTT (disabled by default) |

Confirm the exact ESP32 board and PZEM module revision before wiring.

## Build
1. Copy `include/config.example.h` to `include/config.h`.
2. Keep MQTT disabled for compile-only use, or enter private broker credentials and enable it.
3. Run `pio run`.

Do not commit `include/config.h`; it is ignored by Git.

## Safety
AC mains can cause fatal shock or fire. This repository is not a mains wiring guide. Mains-side installation must be designed and completed by a qualified electrician using the exact module documentation, suitable protection and a rated enclosure. Never connect mains voltage to ESP32 GPIO pins. See [docs/safety.md](docs/safety.md).

## Verification
GitHub Actions compiles the firmware and runs Python checks on clearly labelled illustrative sample data. Physical meter readings, calibration, mains installation and MQTT delivery are not claimed. See [docs/testing.md](docs/testing.md) and [docs/limitations.md](docs/limitations.md).
