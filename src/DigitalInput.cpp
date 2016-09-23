#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups): Input(coolDownInterrups), pin(pin), value(HIGH) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

void DigitalInput::doUpdate() {
	this->value = digitalRead(this->pin);
}

bool DigitalInput::isPressed() {
  return this->value == LOW;
}
