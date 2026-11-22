# Design Decisions

## ESP32 DevKit target
The PlatformIO environment targets the common `esp32dev` board definition. A different ESP32 board may require a different board ID and pin review.

## UART2 for meter communication
A hardware UART is selected to keep serial communication independent of USB Serial Monitor output. RX and TX pins are configurable. Confirm the actual board pinout and module TTL interface before wiring.

## MQTT is optional
MQTT is disabled by default. This keeps the baseline firmware independent of Wi-Fi and broker credentials. Users can enable it in their ignored local config file.

## Secrets are local
The tracked example config contains placeholders only. The real `include/config.h` file is excluded by `.gitignore`.

## Conservative claims
Sample CSV values are illustrative. Automated tests validate file structure and broad ranges, not sensor accuracy. Physical tests are explicitly separated from CI checks.

## Mains safety is external to firmware
Firmware cannot make an unsafe mains installation safe. The repository does not provide a DIY mains wiring procedure; installation is assigned to a qualified electrician.
