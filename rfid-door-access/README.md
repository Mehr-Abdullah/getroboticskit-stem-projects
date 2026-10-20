# Project 05 — RFID Door / Attendance System (Arduino)

**Publish to:** Hackster → Instructables → Arduino Project Hub  
**Deep-link:** https://getroboticskit.com/guides/rfid-door-access  
**Difficulty:** Intermediate · **Tags:** RFID, MFRC522, Arduino, security, FYP, attendance

## One-line pitch
Scan an RFID card, match against an allow-list, unlock a solenoid/relay, and log access — a classic intermediate FYP that looks “real world.”

## BOM

| Qty | Part | Shop |
|-----|------|------|
| 1 | Arduino Uno | https://getroboticskit.com/shop?q=arduino+uno |
| 1 | RC522 RFID reader + tags | https://getroboticskit.com/shop?q=RFID |
| 1 | 16×2 I2C LCD (optional) | https://getroboticskit.com/shop?q=LCD+I2C |
| 1 | Relay + electric lock / solenoid | Match voltage |
| 1 | Buzzer | feedback |
| — | Separate lock power supply | safety |

**Guide:** https://getroboticskit.com/guides/rfid-door-access

## Story beats
1. Wire RC522 SPI pins (document SS/RST).  
2. Dump UID of master card via Serial.  
3. Hard-code allow-list (then upgrade to EEPROM).  
4. On match: relay pulse 3–5 s; show “Access granted.”  
5. On fail: buzzer + “Denied.”

## Soft CTA
> Kit roles explained (reader, LCD, actuator): https://getroboticskit.com/guides/rfid-door-access

## Bonus related kit for Project Hub series
Dual-axis solar tracker: https://getroboticskit.com/shop?q=solar+tracker  
Sumo competition path: https://getroboticskit.com/guides/sumo-robot-competition
