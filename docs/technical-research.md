# Technical Research Notes

## ESP32 and UART
The ESP32 Arduino framework exposes hardware UART interfaces through `HardwareSerial`. The firmware uses UART2 and configurable RX/TX GPIO assignments. Exact pin availability depends on the ESP32 module/board variant.

References:
- Espressif ESP-IDF UART documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/uart.html
- Arduino-ESP32 documentation: https://docs.espressif.com/projects/arduino-esp32/en/latest/

## PZEM-004T interface
The firmware uses the `PZEM-004T-v30` Arduino library API to retrieve voltage, current, power, energy, frequency and power factor. Confirm the precise meter revision and module documentation before relying on a library or wiring assumption.

Reference:
- PZEM-004T v3 library: https://github.com/mandulaj/PZEM-004T-v30

## MQTT telemetry
MQTT is a lightweight publish/subscribe messaging protocol. The example firmware publishes a JSON telemetry payload to one configured topic using PubSubClient. Broker authentication, transport security, topic access controls and network reliability must be considered before deployment.

References:
- OASIS MQTT standard: https://mqtt.org/
- PubSubClient library: https://github.com/knolleary/pubsubclient

## PlatformIO build
PlatformIO selects the `esp32dev` board environment, Espressif32 platform and Arduino framework. GitHub Actions copies the safe example configuration to an ignored local config file before compilation.

Reference:
- PlatformIO ESP32 DevKit board documentation: https://docs.platformio.org/en/latest/boards/espressif32/esp32dev.html

## Energy quantities
The meter library reports accumulated energy in kWh, while power is reported in watts. Energy is an accumulated quantity and should not be inferred from one instantaneous power sample. For independent validation, compare accumulated readings over a known time interval with a suitable reference meter under controlled conditions.
