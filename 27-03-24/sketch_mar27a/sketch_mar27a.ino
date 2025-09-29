#include <ESP8266WiFi.h>

const int ACS712_PIN = A0;  // Analog pin connected to ACS712 sensor

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

void setup() {
  Serial.begin(115200);
  delay(100);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print ESP8266 IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Read analog value from ACS712 sensor
  int sensorValue = analogRead(ACS712_PIN);

  // Convert analog value to current (in milliamps)
  float current_mA = (sensorValue - 512.0) / 102.3;

  // Calculate power assuming load voltage of 5V
  float power_W = (current_mA / 1000.0) * 5.0;

  // Print power
  Serial.print("Power: ");
  Serial.print(power_W);
  Serial.println(" Watts");

  delay(1000);  // Wait for a second
}
