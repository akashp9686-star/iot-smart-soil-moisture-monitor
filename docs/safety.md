# Electrical Safety — Project 06

**DANGER: AC mains voltage can cause fatal electric shock, burns and fire.**

- Do not connect, disconnect, probe or modify a live mains circuit.
- Never place mains wiring on a breadboard or expose live conductors.
- Do not connect mains to Arduino Uno, ESP-01 GPIO, UART or USB connections.
- Have the ACS712 mains-side current path, enclosure, fuse/protection, insulation, earthing and strain relief designed and installed by a qualified electrician.
- Verify the exact ACS712 module's current rating, terminal arrangement, isolation design and datasheet.
- Keep the low-voltage controller side physically protected from hazardous voltage.
- ESP-01 requires a regulated 3.3V supply and safe UART logic levels; use level conversion from Uno TX to ESP-01 RX.
- Confirm capacitor polarity and voltage rating before fitting the handbook-listed 10µF capacitor.
- Do not use this prototype as a billing meter or protective device.

Software plausibility checks do not provide electrical protection, calibration or certification.
