# Methodology — Project 03

1. Read the analog output of the soil sensor on Arduino Uno A0.
2. Convert the raw ADC reading into a 0–100% estimate using calibrated dry and wet endpoints. The handbook example uses 1023 and 300.
3. Compare the estimate with the 30% dry threshold.
4. Turn on the red LED at D6 below threshold; otherwise turn on the green LED at D7.
5. Send the moisture percentage to ThingSpeak Field 1 through ESP-01 AT commands.
6. Repeat at the handbook example interval of 20 seconds.

Calibration values must be measured for the actual sensor. The procedure describes intended operation, not completed physical testing.
