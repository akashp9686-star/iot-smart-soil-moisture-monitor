# Methodology — Project 06

1. Confirm the Arduino Uno, ACS712-20A, ESP-01, LCD backpack and level converter part numbers.
2. Review the exact ACS712 module schematic, including the handbook-listed 10µF capacitor placement and polarity.
3. Prepare low-voltage signal wiring: ACS712 OUT to A1; LCD I2C to A4/A5; ESP-01 UART via D10/D11 with level conversion.
4. Provide a stable regulated 3.3V supply to ESP-01 and verify its AT firmware baud.
5. Compile with `pio run -e uno`.
6. Configure Wi-Fi and ThingSpeak credentials privately; confirm channel Field 1 and Field 2 mapping.
7. Have a qualified electrician design and inspect any mains-side installation before applying load current.
8. Calibrate ACS712 readings against a suitable reference instrument under safe controlled conditions.
9. Verify LCD, ESP-01 AT/Wi-Fi connection and ThingSpeak uploads; record genuine evidence.

Steps requiring physical hardware, instruments, mains work or a live cloud account are not complete until actually performed.