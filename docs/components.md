# Component Inventory

| Component | Role | Selection notes |
|---|---|---|
| ESP32 DevKit / ESP32-WROOM-32 class board | Main controller and Wi-Fi | Confirm exact board and UART pin mapping |
| PZEM-004T v3 module with TTL interface | Voltage/current/power/energy/frequency/power-factor metering | Confirm exact revision, terminal layout and interface requirements |
| Suitable enclosure and protective components | Electrical protection | Must be selected and installed by a qualified person |
| Low-voltage USB supply | ESP32 power during firmware setup | Do not derive low-voltage supply from exposed mains |
| MQTT broker (optional) | Telemetry receiver | Can be local or managed; credentials belong in local config |
| Jumper wires for low-voltage UART only | ESP32-to-meter logic interface | Use correct logic-level/interface requirements for exact module |

This list is a design inventory, not evidence that any component has been purchased, assembled or tested.
