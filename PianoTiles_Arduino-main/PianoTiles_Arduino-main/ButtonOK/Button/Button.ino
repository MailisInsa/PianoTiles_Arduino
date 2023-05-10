#include "TouchSensor.h"
const int ledPin = LED_BUILTIN;
TouchSensor touch;

void setup() {
  pinMode(ledPin, OUTPUT);
  touch.setup();
}

void loop() {
  if ( touch.Touched()) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

