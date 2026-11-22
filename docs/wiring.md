# Interface and Wiring Notes

## Low-voltage UART concept

| ESP32 signal | PZEM TTL signal | Notes |
|---|---|---|
| GPIO16 / RX2 | TX | UART receive; confirm connector pinout |
| GPIO17 / TX2 | RX | UART transmit; confirm connector pinout |
| GND | GND | Common logic reference only where required by the exact interface design |

The code defaults to ESP32 UART2 with RX GPIO16 and TX GPIO17. These pins are configurable in `include/config.h`.

**Do not treat this table as a mains wiring diagram.** The PZEM-004T family has multiple versions and board variants. The AC terminal arrangement and electrical isolation differ by model. Use the exact manufacturer's documentation for the exact module and have mains-side installation completed by a qualified person. Never connect mains to ESP32 GPIO pins.
