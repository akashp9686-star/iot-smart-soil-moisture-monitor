# Technical Research Notes

## ESP32 and UART
The ESP32 Arduino framework exposes hardware UART interfaces through `HardwareSerial`. This project uses UART2 with configurable RX/TX GPIO assignments. Exact pin availability depends on the ESP32 board/module variant.

References:
- Espressif ESP-IDF UART documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/uart.html
- Arduino-ESP32 documentation: https://docs.espressif.com/projects/arduino-esp32/en/latest/

## PZEM-004T v3.0 module and library
The selected `mandulaj/PZEM-004T-v30` library is specifically for the updated PZEM-004T v3.0 family. Its documentation lists ESP32 hardware serial as supported and demonstrates the ESP32 constructor using hardware Serial2 with RX/TX pin arguments. The library exposes methods for voltage, current, active power, accumulated energy, frequency and power factor.

Important compatibility note: the v3.0 library documentation states that this module's protocol is not compatible with the older PZEM004T library. Confirm that the physical module is actually a compatible v3.0 unit before selecting the library or relying on its API.

The library's README describes 10A and 100A model variants and warns that wiring, power and serial-interface details matter. Module sellers may use confusing model/version labels; verify the label, datasheet, terminal layout and interface level of the exact unit.

References:
- PZEM-004T v3.0 library and ESP32 HardwareSerial example: https://github.com/mandulaj/PZEM-004T-v30
- PZEM library links and documentation index: https://github.com/mandulaj/PZEM-004T-v30/blob/master/LINKS.md
- PZEM-004T v3.0 user manual (confirm exact model variant): https://arduino.ua/files/PZEM-004T-V3_0-Datasheet-User-Manual.pdf

## MQTT telemetry
MQTT is a lightweight publish/subscribe messaging protocol. The example firmware publishes a JSON telemetry payload to one configured topic using PubSubClient. Broker authentication, transport security, topic access controls and network reliability must be considered before deployment. The CI workflow compiles both the MQTT-disabled and MQTT-enabled code paths; it does not connect to a live broker.

References:
- MQTT protocol: https://mqtt.org/
- PubSubClient library: https://github.com/knolleary/pubsubclient

## PlatformIO build
PlatformIO selects the `esp32dev` board environment, Espressif32 platform and Arduino framework. GitHub Actions copies the safe example configuration to an ignored local config file before compilation.

Reference:
- PlatformIO ESP32 DevKit board documentation: https://docs.platformio.org/en/latest/boards/espressif32/esp32dev.html

## Energy quantities
The meter library reports accumulated energy in kWh, while active power is reported in watts. Energy is an accumulated quantity and should not be inferred from one instantaneous power sample. For independent validation, compare accumulated readings over a known time interval with a suitable reference meter under controlled conditions.

## Research limitations
These references support the selected software interface and general design. They do not establish that a particular purchased module is genuine, correctly wired, calibrated, electrically safe or compatible with every ESP32 board. Verify the exact hardware before physical use.
