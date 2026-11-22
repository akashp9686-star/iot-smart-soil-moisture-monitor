# Methodology

1. Review the ESP32 board documentation and the exact PZEM-004T v3 module documentation.
2. Confirm the meter module's voltage/current ratings, isolation design, terminals and TTL interface requirements.
3. Design a safe installation enclosure and protective arrangement with a qualified electrical professional.
4. Configure the ESP32 UART pins in the local configuration header.
5. Compile the firmware using PlatformIO.
6. If MQTT is required, configure Wi-Fi and broker credentials locally and enable MQTT.
7. On a safely installed system, compare readings with a suitable reference instrument and record the conditions.
8. Test MQTT connectivity, reconnect behaviour and payload parsing.
9. Record measured results, calibration limitations and genuine evidence.

Steps 1–6 can be reviewed at repository level. Steps involving a physical meter, mains wiring, reference instruments or a live broker require actual execution and must not be marked complete based on this document alone.
