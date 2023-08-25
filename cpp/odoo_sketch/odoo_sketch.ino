// Component includes
#include <Switch.h>
#include <RGBLED.h>

// Microswitch pin number
#define SWITCH_PIN 2

// RGB LED pins
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
// RGB LED brightness
#define LED_MAX_BRIGHTNESS 64

// Message values
#define BAUD_RATE 115200
#define SWITCH_PRESSED "SWITCH_PRESSED"
#define ODOO "ODOO\n"

Switch my_switch(SWITCH_PIN);
RGBLED my_led(RED_PIN, GREEN_PIN, BLUE_PIN);

void setup() {
  Serial.begin(BAUD_RATE);
  my_led.on(LED_MAX_BRIGHTNESS, 0, 0);
  bool connected = false;

  // Wait for connection with ODOO adapter
  while (!connected) {
    while (!Serial.available()) {}

    if (Serial.available() > 0) {
      String data = Serial.readString();
      
      if (data == ODOO) {
        connected = true;
      }
    }
  }
  my_led.on(0, LED_MAX_BRIGHTNESS, 0);
}

void loop() {
  if (my_switch.isClosed()) {
    my_led.on(LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS, LED_MAX_BRIGHTNESS * 2);
    Serial.println(SWITCH_PRESSED);
    delay(125);
    my_led.on(0, LED_MAX_BRIGHTNESS, 0);
  }
}
