#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca(0x40);

// ===== WiFi Credentials =====
const char* ssid = "QuadBot";
const char* password = "12345678";

WiFiServer server(80);

// ===== Servo Limits =====
#define SERVO_MIN 120
#define SERVO_MAX 600

// ===== Leg Mapping =====
// {Hip, Knee, Ankle}
int leg[4][3] = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {9, 10, 11}
};

// ===== Motion State =====
String command = "stop";

// ===== Servo Functions =====
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void setServo(int ch, int angle) {
  pca.setPWM(ch, 0, angleToPulse(angle));
}

// ===== Poses =====
void stand() {
  for (int i = 0; i < 4; i++) {
    setServo(leg[i][0], 90);
    setServo(leg[i][1], 90);
    setServo(leg[i][2], 90);
  }
}

void sit() {
  for (int i = 0; i < 4; i++) {
    setServo(leg[i][0], 90);
    setServo(leg[i][1], 130);
    setServo(leg[i][2], 90);
  }
}

// ===== Movements =====
void forwardStep() {
  setServo(leg[0][1], 60);
  setServo(leg[3][1], 60);
  delay(300);

  setServo(leg[0][0], 70);
  setServo(leg[3][0], 110);
  delay(300);

  stand();
}

void backwardStep() {
  setServo(leg[1][1], 60);
  setServo(leg[2][1], 60);
  delay(300);

  setServo(leg[1][0], 110);
  setServo(leg[2][0], 70);
  delay(300);

  stand();
}

// ===== HTML Page =====
String webPage() {
  return R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>QuadBot Control</title>
  <style>
    body { font-family: Arial; text-align:center; background:#111; color:white; }
    button {
      width: 140px;
      height: 50px;
      font-size: 18px;
      margin: 10px;
      border-radius: 10px;
      border: none;
    }
    .sit { background:#ff9800; }
    .stand { background:#4caf50; }
    .fwd { background:#2196f3; }
    .back { background:#9c27b0; }
    .stop { background:#f44336; }
  </style>
</head>
<body>
  <h1>🦾 QuadBot Control</h1>
  <button class="sit" onclick="fetch('/sit')">Sit</button><br>
  <button class="stand" onclick="fetch('/stand')">Stand</button><br>
  <button class="fwd" onclick="fetch('/forward')">Forward</button><br>
  <button class="back" onclick="fetch('/backward')">Backward</button><br>
  <button class="stop" onclick="fetch('/stop')">Stop</button>
</body>
</html>
)rawliteral";
}

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);
  pca.begin();
  pca.setPWMFreq(50);

  stand();

  // WiFi Access Point
  WiFi.softAP(ssid, password);
  Serial.println("WiFi Started");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/sit") != -1) command = "sit";
  else if (request.indexOf("/stand") != -1) command = "stand";
  else if (request.indexOf("/forward") != -1) command = "forward";
  else if (request.indexOf("/backward") != -1) command = "backward";
  else if (request.indexOf("/stop") != -1) command = "stop";

  // Send HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println(webPage());
  client.stop();

  // Execute command
  if (command == "sit") sit();
  else if (command == "stand") stand();
  else if (command == "forward") forwardStep();
  else if (command == "backward") backwardStep();
}
