# Optional MQTT Setup

1. Copy `include/config.example.h` to `include/config.h`.
2. Enter Wi-Fi SSID and password.
3. Set `MQTT_ENABLED` to `1`.
4. Enter broker host, port, username and password as applicable.
5. Set a unique `DEVICE_ID` and topic.
6. Build and upload only to a safely assembled low-voltage controller/meter setup.
7. Subscribe to the configured topic using an MQTT client and confirm the received JSON structure.

The repository's example config leaves MQTT disabled. Credentials must never be committed. The sample payload in the README is illustrative. The firmware example uses ordinary MQTT TCP; do not expose an unauthenticated broker to the public internet. For deployments, select a broker and transport-security approach appropriate to the network and device capabilities.
