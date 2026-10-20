# Project 03 — Ultrasonic Obstacle-Avoiding Robot

**Publish to:** Hackster → Instructables → Arduino Project Hub  
**Deep-link:** https://getroboticskit.com/guides/obstacle-avoiding-robot  
**Difficulty:** Beginner · **Tags:** HC-SR04, Arduino/ESP32, autonomous rover

## One-line pitch
A rover that measures distance with an HC-SR04, stops before walls, and turns — with explicit notes for 3.3V boards (level shifting).

## BOM

| Qty | Part | Shop |
|-----|------|------|
| 1 | Arduino Uno **or** ESP32 | https://getroboticskit.com/shop?q=arduino+uno / `esp32` |
| 1 | HC-SR04 ultrasonic | https://getroboticskit.com/shop?q=HC-SR04 |
| 1 | L298N + 2WD chassis | https://getroboticskit.com/shop?q=L298N |
| 1 | SG90 + bracket (optional scan) | https://getroboticskit.com/shop?q=SG90 |
| 1 | Level shifter if using ESP32 (HC-SR04 Echo is 5V) | https://getroboticskit.com/shop?q=level+shifter |

**Guide:** https://getroboticskit.com/guides/obstacle-avoiding-robot

## Critical safety note (editors love this)
HC-SR04 **Echo is 5V**. On ESP32/ESP8266, use a voltage divider or level shifter on Echo. Trig can usually be driven from 3.3V.

## Starter logic
1. Ping distance every 100–200 ms.  
2. If distance < 20 cm → stop → reverse 300 ms → turn 400 ms → resume.  
3. Optional: servo sweep left/right and pick the clearer path.

## Soft CTA
> Level-shift-aware kit path: https://getroboticskit.com/guides/obstacle-avoiding-robot

## Related catalog
Ultrasonic Glasses For the Blind kit (assistive variant): https://getroboticskit.com/shop?q=ultrasonic+glasses
