#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups, Subscriber& subscriber)
		: pin(pin), value(HIGH), coolDownInterrups(coolDownInterrups), subscriber(subscriber) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

void DigitalInput::update() {
	if (this->countedInterrups >= this->coolDownInterrups) {
    this->value = digitalRead(this->pin);
    this->countedInterrups = 0;
		this->subscriber.notify();
  } else {
    this->countedInterrups++;
  }
}

bool DigitalInput::isPressed() {
  return this->value == LOW;
}
