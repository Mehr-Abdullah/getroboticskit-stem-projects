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
