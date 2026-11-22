# Project 06 — Testing and Verification
## Software verification
GitHub Actions now compiles the Arduino Uno PlatformIO environment. Check the Actions tab for the result associated with the latest commit. Compilation is not hardware validation.

## Hardware/integration test record
| Test | Status |
|---|---|
| ACS712 output and RMS readings | Not performed |
| Calibration against reference current meter | Not performed |
| LCD display operation | Not performed |
| ESP-01 AT command / Wi-Fi association | Not performed |
| ThingSpeak field upload | Not performed |
| Mains installation inspection | Not performed; qualified electrician required |

## Procedure when safely assembled
1. Verify low-voltage wiring and ESP-01 supply before powering.
2. Confirm ACS712 variant and calibrate its zero offset and sensitivity against an appropriate reference.
3. Verify LCD readings.
4. Verify ESP-01 AT response and Wi-Fi association.
5. Confirm ThingSpeak Field 1 and Field 2 receive actual values.
6. Record instrument, board/module revisions, date, conditions and raw observations.

Never fabricate results or claim physical testing without evidence. Mains-side work must be performed and inspected by a qualified electrician.
