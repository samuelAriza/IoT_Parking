// Include necessary libraries for controlling the servo and connecting to Ubidots
#include <ESP32Servo.h>
#include <UbiConstants.h>
#include <UbiTypes.h>
#include <UbidotsEsp32Mqtt.h>

// Define GPIO pins
int sensor_luz = 35;
int luz = 32;
int movimiento = 33;
int infra = 25;

// Create a Servo object
Servo myServo;

// WiFi and Ubidots credentials
const char *WIFI_SSID = "###";
const char *WIFI_PASSWORD = "###";
const char *UBIDOTS_TOKEN = "###";

// Initialize Ubidots object
Ubidots ubidots(UBIDOTS_TOKEN);

// Callback function to handle incoming messages from Ubidots
void handleMessage(char *topic, byte *payload, unsigned int length) {
  char ledValue = (char)payload[0];
  if (ledValue == '1') {
    Serial.println("Activating servo");
    myServo.write(90);    // Move the servo to 90 degrees
    delay(5000);          // Wait for 5 seconds
    myServo.write(0);     // Move the servo back to 0 degrees
    delay(5000);          // Wait for 5 seconds
    Serial.println("Servo action completed");
  }
}

// GPIO pin to which the servo is connected
const int servoPin = 18;

void setup() {
  // Initialize GPIO pin modes
  pinMode(sensor_luz, INPUT);
  pinMode(luz, OUTPUT);
  pinMode(movimiento, INPUT);
  pinMode(infra, INPUT);

  // Attach the servo to the specified pin
  myServo.attach(servoPin);
  myServo.write(90); // Initial position

  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println();
  Serial.println("Device initialization...");

  // Connect to WiFi
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASSWORD);

  // Set up Ubidots callbacks and connect
  ubidots.setCallback(handleMessage);
  ubidots.setup();
  ubidots.reconnect();
  ubidots.subscribeLastValue("samargo_", "led");
}

void loop() {
  // Reconnect to Ubidots if disconnected
  if (!ubidots.connected()) {
    ubidots.reconnect();
    ubidots.subscribeLastValue("samargo_", "led");
  }
  ubidots.loop();

  // Debugging output
  Serial.println("Loop running...");
  Serial.println(digitalRead(infra));

  // Control light based on sensor_luz input
  if (digitalRead(sensor_luz)) {
    digitalWrite(luz, HIGH); // Turn on light
  } else {
    digitalWrite(luz, LOW); // Turn off light
  }

  // Additional control based on infra input
  if (digitalRead(infra) == LOW) {
    digitalWrite(luz, HIGH); // Turn on light
    delay(2000); // Keep the light on for 2 seconds
  }
}

