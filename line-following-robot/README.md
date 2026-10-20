# Project 02 — Arduino Line-Following Robot

**Publish to:** Hackster → Instructables → Arduino Project Hub  
**Deep-link:** https://getroboticskit.com/guides/line-following-robot  
**Difficulty:** Beginner · **Time:** 2–3 hours · **Tags:** Arduino, IR sensor, line follower, L298N, STEM, FYP

## One-line pitch
Build a classic black-line robot using an IR array (or 2–5 IR sensors), Arduino Uno, and L298N — the standard first autonomous robot for classrooms and FYPs.

## Story outline

### Introduction
Line followers teach closed-loop control: read reflectance sensors, decide left/right, drive motors. This tutorial uses catalog-backed parts so students can replicate the BOM without hunting random listings.

### What you will learn
- IR reflectance sensing (digital vs analog arrays)
- Differential drive with L298N
- Simple proportional steering logic
- Power hygiene (motor pack ≠ MCU USB forever)

### Hardware BOM

| Qty | Part | Notes | Shop |
|-----|------|-------|------|
| 1 | Arduino Uno (or compatible) | | https://getroboticskit.com/shop?q=arduino+uno |
| 1 | L298N motor driver | | https://getroboticskit.com/shop?q=L298N |
| 1 | 2WD chassis + TT motors + wheels | | https://getroboticskit.com/shop?q=robot+chassis |
| 1 | IR line array (5-ch preferred) or 2× TCRT5000 | Array = easier | https://getroboticskit.com/shop?q=line+follower |
| 1 | 6–9V battery pack for motors | | |
| — | Jumpers, switch, cable ties | | |

**Guide:** https://getroboticskit.com/guides/line-following-robot

### Logic (publish clearly)
- Sensors over black line → low/high depending on module (calibrate!).
- If left sensor sees white and right sees black → turn right (and vice versa).
- If both on black → go forward; both on white → stop or search.

### Starter code (2-sensor digital)

```cpp
const int L_SENS = 2, R_SENS = 3;
const int IN1 = 8, IN2 = 9, IN3 = 10, IN4 = 11;
const int ENA = 5, ENB = 6;

void setup() {
  pinMode(L_SENS, INPUT); pinMode(R_SENS, INPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
}

void motors(int l, int r, int spd) {
  digitalWrite(IN1, l > 0); digitalWrite(IN2, l < 0);
  digitalWrite(IN3, r > 0); digitalWrite(IN4, r < 0);
  analogWrite(ENA, spd); analogWrite(ENB, spd);
}

void loop() {
  int L = digitalRead(L_SENS);
  int R = digitalRead(R_SENS);
  // Adjust if your modules invert black/white
  if (L == LOW && R == LOW) motors(1, 1, 160);      // both on line
  else if (L == HIGH && R == LOW) motors(1, 0, 140); // steer right
  else if (L == LOW && R == HIGH) motors(0, 1, 140); // steer left
  else motors(0, 0, 0);                              // lost line
}
```

### Build steps
1. Assemble chassis and mount IR sensors 5–10 mm above track.  
2. Wire L298N + motors; common ground with Uno.  
3. Tape a black electrical-tape oval on white poster board.  
4. Calibrate sensor thresholds with Serial prints.  
5. Tune PWM until turns are smooth, not twitchy.

### Soft CTA
> Step-by-step BOM paths: https://getroboticskit.com/guides/line-following-robot

### Checklist
- [ ] Photos: track demo, sensor mount, wiring  
- [ ] Hackster / Instructables / Arduino Hub published  
- [ ] URLs logged in tracker
