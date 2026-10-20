# Project 04 — ESP32 Smart Plant Watering System

**Publish to:** Hackster → Instructables → Random Nerd Tutorials (PRIMARY PITCH)  
**Deep-link:** https://getroboticskit.com/guides/smart-plant-watering  
**Difficulty:** Beginner–Intermediate · **Tags:** ESP32, soil moisture, relay, IoT, irrigation

## One-line pitch
An ESP32 reads soil moisture, triggers a pump via relay when dry, and optionally serves a tiny status page — a practical home IoT + FYP project.

## Why this is the RNT guest project
Random Nerd Tutorials’ audience already builds ESP32 IoT. This is well-documented, sensor + actuator, beginner-safe if relay/pump wiring is clear, and maps to a live problem guide.

## BOM

| Qty | Part | Notes | Shop |
|-----|------|-------|------|
| 1 | ESP32 DevKit or ESP32-C3 | C3 Super Mini is fine | https://getroboticskit.com/shop?q=esp32 |
| 1 | Capacitive soil moisture sensor | Prefer capacitive over resistive | https://getroboticskit.com/shop?q=soil+moisture |
| 1 | 5V relay module | Optocoupled preferred | https://getroboticskit.com/shop?q=relay |
| 1 | Submersible pump + tubing | Match relay voltage | https://getroboticskit.com/shop?q=pump |
| 1 | Separate 5V supply for pump | Never power pump from ESP | |
| — | Jumpers, enclosure | | |

**Guide:** https://getroboticskit.com/guides/smart-plant-watering

## Wiring rules to emphasize
- ESP32 ADC pin ← soil sensor AO (check 3.3V-safe modules).  
- Relay IN ← GPIO (active LOW on many modules — document!).  
- Pump power path: supply → relay NO → pump → GND. ESP ground joined to relay only.  
- Calibrate dry/wet ADC thresholds in Serial before enabling pump.

## Starter sketch

```cpp
#define SOIL_PIN 34
#define RELAY_PIN 26
const int DRY_THRESHOLD = 2500; // calibrate!
const unsigned long WATER_MS = 3000;
const unsigned long INTERVAL = 60000;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // assume active LOW off
}

void loop() {
  int soil = analogRead(SOIL_PIN);
  Serial.printf("Soil ADC: %d\n", soil);
  if (soil > DRY_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);  // pump ON
    delay(WATER_MS);
    digitalWrite(RELAY_PIN, HIGH); // pump OFF
  }
  delay(INTERVAL);
}
```

## Soft CTA
> Full kit path + BOM: https://getroboticskit.com/guides/smart-plant-watering

## Photos needed
- [ ] Sensor in pot  
- [ ] Relay + pump wiring (safe layout)  
- [ ] Serial calibration screenshot  
- [ ] Before/after watering demo
