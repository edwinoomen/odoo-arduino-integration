// Component includes
#include <Switch.h>
#include <RGBLED.h>
#include <SerialCom.h>

// Print debug messages to serial
#define DEBUG

// RGB LED variables
#define LED_RED_PIN 3
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 11
#define LED_MAX_BRIGHTNESS 255

// Microswitch pin
#define SWITCH_PIN 2

// RGB LED pins
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

Switch my_switch(SWITCH_PIN);
RGBLED my_led(RED_PIN, GREEN_PIN, BLUE_PIN);
SerialCom serial_com();

int _iterations;

union bytes2int {
  byte bytes[sizeof(int)];
  int integer;
};

void setup() {
  Serial.begin(9600);
  _iterations = 0;

  logSerial("Hello world!");
}

void loop() {

  if (my_switch.isClosed()) {
    logSerial("Its closed");
    my_led.on(0,128,0);
    delay(125);
    my_led.off();
  }
}

void logSerial(String message) {
#ifdef DEBUG
  Serial.println(message);
#endif
}

void sendSwichPressed() {
#ifndef DEBUG
  serial_com.startMessage();
  serial_com.send(SWITCH_PRESSED);
  serial_com.endMessage();
#endif
}
