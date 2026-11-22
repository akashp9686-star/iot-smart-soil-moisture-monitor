# FAQ — Project 03

**Why is the percentage inaccurate?** Calibrate the raw dry and wet endpoints for your exact sensor and soil. The handbook's 1023/300 values are examples.

**Why does the ESP-01 restart or fail to join Wi-Fi?** Check the regulated 3.3V supply, common ground, UART level conversion, AT firmware baud rate and credentials.

**What does the red LED mean?** The example firmware turns it on below 30% estimated moisture.

**What does ThingSpeak receive?** Field 1 receives the moisture percentage.

**Does this operate an irrigation pump?** No. The handbook project monitors moisture and uploads data; pump actuation is outside this implementation.

**Has the physical circuit been tested?** Not yet. See `testing.md` for the honest verification record.
