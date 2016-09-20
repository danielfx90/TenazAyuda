#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin): pin(pin) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

bool DigitalInput::isPressed() {
  int value = digitalRead(this->pin);
  return value == LOW;
}
