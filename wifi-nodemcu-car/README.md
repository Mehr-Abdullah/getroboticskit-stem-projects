# Project 01 — WiFi-Controlled Robot Car (NodeMCU / ESP8266)

**Publish to (order):** Hackster → Instructables → Arduino Project Hub  
**Deep-link:** https://getroboticskit.com/guides/obstacle-avoiding-robot (related) · Shop: https://getroboticskit.com/shop?q=wifi+car  
**Catalog kit angle:** WIFI Controlled Car NodeMCU (~$30.76)  
**Difficulty:** Intermediate · **Time:** 2–4 hours · **Tags:** NodeMCU, ESP8266, WiFi, robotics, motor driver, STEM

## One-line pitch
Build a 2WD/4WD robot car you drive from any phone browser over WiFi — no Bluetooth app required.

## Story outline (copy into platforms)

### Introduction
Most first robot cars use Bluetooth and a custom app. This build uses a NodeMCU (ESP8266) as an access point / soft-AP web server so any phone on the same WiFi can steer the car from a simple HTML page. Ideal for STEM labs and final-year demos.

### What you will learn
- Powering motors safely with an L298N (never from MCU pins)
- NodeMCU GPIO mapping for motor IN1–IN4 + ENA/ENB
- Serving a mobile control page from the ESP8266
- Separating logic (5V) and motor (6–12V) power

### Hardware BOM

| Qty | Part | Notes | Shop search |
|-----|------|-------|-------------|
| 1 | NodeMCU ESP8266 or WiFi car kit | Kit preferred for first build | `wifi car` / `nodemcu` |
| 1 | L298N dual H-bridge | Or kit-included driver | `L298N` |
| 2–4 | TT geared DC motors + wheels | Match chassis | `TT motor` |
| 1 | 2WD or 4WD acrylic chassis | | `robot chassis` |
| 1 | 18650×2 holder or 6–12V pack | Motors need separate supply | `battery holder` |
| 1 | SPDT switch | | `rocker switch` |
| — | Jumper wires, cable ties | | |

**Live catalog:** https://getroboticskit.com/shop?q=wifi+car  
**Problem guide (related rover path):** https://getroboticskit.com/guides/obstacle-avoiding-robot

### Wiring (publish as diagram + table)

| L298N | NodeMCU |
|-------|---------|
| IN1 | D1 (GPIO5) |
| IN2 | D2 (GPIO4) |
| IN3 | D5 (GPIO14) |
| IN4 | D6 (GPIO12) |
| ENA | D7 (GPIO13) PWM |
| ENB | D8 (GPIO15) PWM |
| 5V | Vin / regulated 5V (do not feed motor voltage into 3.3V pin) |
| GND | GND (common ground mandatory) |

Motor supply → L298N VMS (+). Remove 5V jumper if using >12V motor pack and supply logic 5V separately.

### Firmware sketch (starter)

```cpp
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* AP_SSID = "RobotCar";
const char* AP_PASS = "robot1234"; // change me

ESP8266WebServer server(80);

const int IN1 = D1, IN2 = D2, IN3 = D5, IN4 = D6;
const int ENA = D7, ENB = D8;

void stopAll() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  analogWrite(ENA, 0); analogWrite(ENB, 0);
}

void drive(int lDir, int rDir, int speed) {
  // lDir/rDir: 1 forward, -1 reverse, 0 stop
  digitalWrite(IN1, lDir > 0); digitalWrite(IN2, lDir < 0);
  digitalWrite(IN3, rDir > 0); digitalWrite(IN4, rDir < 0);
  analogWrite(ENA, speed); analogWrite(ENB, speed);
}

void handleRoot() {
  server.send(200, "text/html",
    "<meta name=viewport content='width=device-width,initial-scale=1'>"
    "<style>button{width:30%;height:64px;margin:6px;font-size:18px}</style>"
    "<h3>WiFi Robot Car</h3>"
    "<a href='/f'><button>FWD</button></a>"
    "<a href='/b'><button>BACK</button></a><br>"
    "<a href='/l'><button>LEFT</button></a>"
    "<a href='/r'><button>RIGHT</button></a><br>"
    "<a href='/s'><button>STOP</button></a>");
}

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  stopAll();
  WiFi.softAP(AP_SSID, AP_PASS);
  server.on("/", handleRoot);
  server.on("/f", [](){ drive(1,1,800); handleRoot(); });
  server.on("/b", [](){ drive(-1,-1,800); handleRoot(); });
  server.on("/l", [](){ drive(-1,1,700); handleRoot(); });
  server.on("/r", [](){ drive(1,-1,700); handleRoot(); });
  server.on("/s", [](){ stopAll(); handleRoot(); });
  server.begin();
}

void loop() { server.handleClient(); }
```

### Build steps (platforms love numbered steps)
1. Assemble chassis, mount motors and wheels.  
2. Wire L298N to motors; verify polarity with bench supply before MCU.  
3. Wire control pins NodeMCU ↔ L298N; join grounds.  
4. Flash sketch; connect phone to `RobotCar` AP.  
5. Open `http://192.168.4.1` and test FWD/BACK/LEFT/RIGHT/STOP.  
6. Tune PWM speeds; add optional HC-SR04 later (see obstacle guide).

### Photos needed before publish
- [ ] Full assembled car  
- [ ] Wiring close-up (L298N + NodeMCU)  
- [ ] Phone browser control screenshot  
- [ ] Parts flat-lay / BOM  

### Platform CTAs (one soft link each)
> Full BOM and kit options: https://getroboticskit.com/shop?q=wifi+car  
> Related rover guide: https://getroboticskit.com/guides/obstacle-avoiding-robot

### Publish checklist
- [ ] Hackster project live  
- [ ] Instructables live (+ enter contest if open)  
- [ ] Arduino Project Hub live  
- [ ] Log URLs in `tracker/week1-outreach.csv`
