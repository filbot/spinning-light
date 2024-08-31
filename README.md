# GPIO Control of the Adafruit Rotating LED Warning Light

This project uses an ESP8266 microcontroller to create a simple web server that can control a GPIO pin. The server provides a web interface to trigger an output pin for a specified duration, making it suitable for applications such as remote control of devices or simple automation tasks.

## Features

- **WiFi Connectivity**: Connects to a specified WiFi network using credentials.
- **Web Server**: Hosts a web server using `ESPAsyncWebServer` to handle HTTP requests.
- **GPIO Control**: Provides an endpoint to trigger a GPIO pin, turning it on for a specified duration.
- **Automatic Reconnection**: Attempts to reconnect to the WiFi network if the connection is lost.

## Getting Started

### Prerequisites

- **ESP8266 Board**: Ensure you have an ESP8266 development board, such as a NodeMCU or Wemos D1 Mini.
- **Arduino IDE**: Install the latest version of the [Arduino IDE](https://www.arduino.cc/en/software).
- **ESP8266 Board Package**: Install the ESP8266 board package in the Arduino IDE.
  - Go to **File > Preferences**.
  - Add the following URL to "Additional Board Manager URLs": `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
  - Go to **Tools > Board > Boards Manager** and install the **ESP8266** package.
- **ESPAsyncWebServer Library**: Install the `ESPAsyncWebServer` library in the Arduino IDE.
  - Go to **Sketch > Include Library > Manage Libraries** and search for **ESPAsyncWebServer** by Me-No-Dev.
  - Install the **ESPAsyncTCP** library as well, which is a dependency for **ESPAsyncWebServer**.

### Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/spinning-light.git
   cd spinning-light
   ```

2. **Open the Project**:
   - Open the `.ino` file in the Arduino IDE.

3. **Configure WiFi Credentials**:
   - Create a file named `WiFiCredentials.h` in the project directory.
   - Add your WiFi credentials to the file:
     ```cpp
     const char* ssid = "YOUR_SSID";
     const char* password = "YOUR_PASSWORD";
     ```

4. **Upload the Sketch**:
   - Connect your ESP8266 board to your computer via USB.
   - In the Arduino IDE, select your ESP8266 board from **Tools > Board** and the correct port from **Tools > Port**.
   - Click **Upload** to compile and upload the sketch to your ESP8266.

### Usage

- **Accessing the Web Server**: 
  - Once the ESP8266 is connected to WiFi, open the Serial Monitor in the Arduino IDE to find the IP address assigned to the ESP8266.
  - Open a web browser and navigate to `http://<ESP8266_IP_ADDRESS>/trigger` to activate the GPIO pin.

- **GPIO Control**:
  - The `/trigger` endpoint turns on the GPIO pin (defined in the sketch) for a default duration (e.g., 10 seconds).

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your improvements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [ESP8266 Community](https://github.com/esp8266/Arduino) for the ESP8266 core for Arduino.
- [Me-No-Dev](https://github.com/me-no-dev/ESPAsyncWebServer) for the ESPAsyncWebServer library.
