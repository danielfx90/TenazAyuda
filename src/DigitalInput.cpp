#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups): pin(pin), value(HIGH), coolDownInterrups(coolDownInterrups) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

void DigitalInput::update() {
	if (this->countedInterrups >= this->coolDownInterrups) {
    this->value = digitalRead(this->pin);
    this->countedInterrups = 0;
  } else {
    this->countedInterrups++;
  }
}

bool DigitalInput::isPressed() {
  return this->value == LOW;
}
