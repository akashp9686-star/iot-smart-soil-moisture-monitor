# ThingSpeak Data Format — Project 03

| Field | Meaning | Unit |
|---|---|---|
| Field 1 | Estimated soil moisture | Percent (0–100) |

The firmware writes Field 1 using the channel Write API Key. Configure the channel with a matching field label such as `Soil Moisture (%)`. Do not publish the Write API Key. The channel ID is selected in ThingSpeak's channel configuration; the update endpoint uses the private Write API Key.
