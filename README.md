# ESP32 Servo and Sensor Control with Ubidots Integration

This project demonstrates how to control a servo motor and monitor various sensors using an ESP32 microcontroller. The system is integrated with Ubidots for IoT connectivity, allowing remote control and monitoring.

## Features

- **Servo Motor Control**: Move the servo motor to predefined positions based on commands from Ubidots.
- **Light Sensor Monitoring**: Turn on an LED based on light sensor readings.
- **Motion Detection**: Control the LED based on motion detection.
- **Infrared Sensor Monitoring**: Additional control based on infrared sensor readings.

## Components

- **ESP32**: The main microcontroller.
- **Servo Motor**: Controlled via PWM signal from the ESP32.
- **Light Sensor**: Monitors ambient light levels.
- **Motion Sensor**: Detects motion in the environment.
- **Infrared Sensor**: Provides additional control logic.
- **LED**: Indicates the state based on sensor readings.

## Requirements

- **Hardware**:
  - ESP32 board
  - Servo motor
  - Light sensor
  - Motion sensor
  - Infrared sensor
  - LED
  - Jumper wires and breadboard

- **Software**:
  - Arduino IDE
  - ESP32Servo library
  - Ubidots library for ESP32

## Wiring Diagram

![Wiring Diagram](path_to_wiring_diagram_image)

## Setup

### Hardware Setup

1. **Connect the Servo Motor**:
   - **Signal Pin**: Connect to GPIO 18 of the ESP32.
   - **Power Pin**: Connect to the 5V pin of the ESP32.
   - **Ground Pin**: Connect to the GND pin of the ESP32.

2. **Connect the Light Sensor**:
   - **Output Pin**: Connect to GPIO 35 of the ESP32.
   - **Power Pin**: Connect to the 3.3V pin of the ESP32.
   - **Ground Pin**: Connect to the GND pin of the ESP32.

3. **Connect the Motion Sensor**:
   - **Output Pin**: Connect to GPIO 33 of the ESP32.
   - **Power Pin**: Connect to the 3.3V pin of the ESP32.
   - **Ground Pin**: Connect to the GND pin of the ESP32.

4. **Connect the Infrared Sensor**:
   - **Output Pin**: Connect to GPIO 25 of the ESP32.
   - **Power Pin**: Connect to the 3.3V pin of the ESP32.
   - **Ground Pin**: Connect to the GND pin of the ESP32.

5. **Connect the LED**:
   - **Anode (Long Leg)**: Connect to GPIO 32 of the ESP32 through a current-limiting resistor.
   - **Cathode (Short Leg)**: Connect to the GND pin of the ESP32.

### Software Setup

1. **Install the Arduino IDE**: Download and install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).

2. **Install the ESP32 Board**: Follow the instructions to install the ESP32 board in the Arduino IDE from the [ESP32 setup guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

3. **Install Required Libraries**: 
   - **ESP32Servo**: Install from the Arduino Library Manager.
   - **UbidotsEsp32Mqtt**: Install from the Arduino Library Manager.

4. **Clone this Repository**: Clone or download this repository to your local machine.

5. **Configure WiFi and Ubidots**:
   - Update the `WIFI_SSID`, `WIFI_PASSWORD`, and `UBIDOTS_TOKEN` with your credentials in the code.

### Uploading the Code

1. Open the Arduino IDE.
2. Load the `.ino` file from the cloned repository.
3. Select the correct board and port from the `Tools` menu.
4. Click the upload button to flash the code to your ESP32.

## Code Explanation

The code initializes the necessary components and connects the ESP32 to WiFi and Ubidots. It sets up various sensors and controls a servo motor based on commands received from Ubidots.

### Main Sections

1. **Library Inclusions and GPIO Definitions**: Includes necessary libraries and defines GPIO pins.
2. **WiFi and Ubidots Credentials**: Sets up the WiFi and Ubidots credentials.
3. **Callback Function**: Handles incoming messages from Ubidots to control the servo.
4. **Setup Function**: Initializes GPIO pins, connects to WiFi, and sets up Ubidots.
5. **Loop Function**: Maintains the connection to Ubidots, reads sensor values, and controls the LED.

## Usage

1. **Remote Control**: Use the Ubidots dashboard to send commands to the ESP32 and control the servo motor.
2. **Sensor Monitoring**: Monitor the light, motion, and infrared sensors in real-time on the Ubidots dashboard.

## Troubleshooting

- **Connection Issues**: Ensure the WiFi credentials are correct and the ESP32 is within range.
- **Servo Not Moving**: Check the servo connections and ensure the GPIO pin is correctly defined.
- **Sensor Readings Incorrect**: Verify the sensor connections and ensure they are properly powered.

## Contributing

Feel free to submit issues or pull requests for any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

--
