# Test Plan and Results — Project 03

## Hosted/software verification
GitHub Actions compiles the Arduino Uno firmware. Check the Actions tab for the latest commit's run. A successful compile does not validate sensor calibration or physical operation.

## Hardware test record
| Test | Status | Evidence to record when performed |
|---|---|---|
| Sensor raw ADC response in dry and wet conditions | Not performed | Raw readings, sensor model, soil condition |
| Percentage calibration | Not performed | Dry/wet endpoint values and calculation |
| Red LED below 30% | Not performed | Observed percentage and LED state |
| Green LED at/above 30% | Not performed | Observed percentage and LED state |
| ESP-01 AT response and Wi-Fi join | Not performed | Serial log, module firmware and baud rate |
| ThingSpeak Field 1 update | Not performed | Channel graph or timestamped entry |

## Safe test sequence
1. Assemble only the low-voltage circuit and verify common ground and ESP-01 supply.
2. Confirm the ESP-01 responds to AT at the configured baud rate.
3. Record sensor ADC values in air/dry medium and in the intended wet medium; calibrate endpoints.
4. Test LED behavior around the 30% threshold.
5. Confirm the ThingSpeak channel receives Field 1 moisture values.
6. Save serial logs and dated photographs as evidence.

Do not change any status to passed until the test has actually been performed and evidence recorded.
