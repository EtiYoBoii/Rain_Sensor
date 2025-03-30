#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN 21
#define TRANSISTOR_PIN 2
#define SENSOR_PIN 4

#define PRAG 3000

const char* ssid = "Your SSID";
const char* password = "Your Password";

WebServer server(80);

void handleRoot() {
  int sensorValue = analogRead(SENSOR_PIN);
  String sensorStatus = (sensorValue < PRAG) ? "On (It rains)" : "Off";

  if (sensorValue < PRAG) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(TRANSISTOR_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(TRANSISTOR_PIN, LOW);
  }

  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Rain Sensor</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<style>";
  html += "body { display: flex; flex-direction: column; justify-content: center; align-items: center; ";
  html += "height: 100vh; margin: 0; background-color: #f4f4f9; font-family: Arial, sans-serif; }";
  html += "h1 { color: #333; }";
  html += "p { color: #555; font-size: 1.2rem; }";
  html += "div { padding: 20px; background: #fff; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); border-radius: 10px; }";
  html += "</style>";
  html += "</head><body>";
  html += "<div>";
  html += "<h1>Status of rain sensor</h1>";
  html += "<p>Sensor is: <strong>" + sensorStatus + "</strong></p>";
  html += "<p>Read value: <strong>" + String(sensorValue) + "</strong></p>";
  html += "</div>";
  html += "<script>";
  html += "setInterval(() => { location.reload(); }, 100);"; // Actualizare automată la fiecare 5 secunde
  html += "</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRANSISTOR_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("WEB Server On!");
}

void loop() {
  server.handleClient();
}
