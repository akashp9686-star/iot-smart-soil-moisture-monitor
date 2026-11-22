# Requirements Traceability — Project 03

| Handbook requirement | Repository implementation | Verification |
|---|---|---|
| Arduino Uno R3 | PlatformIO `uno` target | Hosted compile |
| Analog soil sensor | A0 input in `src/main.cpp` | Hardware test pending |
| ESP8266 ESP-01 via AT commands | SoftwareSerial D10/D11 and AT command routines | Hardware test pending |
| Logic-level conversion | Required in wiring guide for UART | Visual wiring inspection pending |
| Red LED + 220Ω | D6 output, dry below 30% | Hardware test pending |
| Green LED + 220Ω | D7 output, adequate moisture | Hardware test pending |
| ThingSpeak upload | Field 1 moisture percentage | Live integration test pending |
| 20-second example interval | `SAMPLE_INTERVAL_MS` | Source review / timing test pending |
