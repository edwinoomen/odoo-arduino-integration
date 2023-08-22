// Component includes
#include <Switch.h>
#include <RGBLED.h>
#include <SerialCom.h>

// Microswitch pin number
#define SWITCH_PIN 2

// RGB LED pins
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
// RGB LED brightness
#define LED_MAX_BRIGHTNESS 128

// Message values
#define SWITCH_PRESSED 1

Switch my_switch(SWITCH_PIN);
RGBLED my_led(RED_PIN, GREEN_PIN, BLUE_PIN);
SerialCom serial_com;

void setup() {
  serial_com.init(115200);
}

void loop() {
  if (my_switch.isClosed()) {
    my_led.on(0,LED_MAX_BRIGHTNESS,0);
    sendSwitchPressed();
    delay(125);
    my_led.off();
  }
}

void sendSwitchPressed() {
  serial_com.startMessage();
  serial_com.send(SWITCH_PRESSED);
  serial_com.endMessage();
}
