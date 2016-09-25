#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups)
		: pin(pin), value(HIGH), coolDownInterrups(coolDownInterrups), countedInterrups(coolDownInterrups), subscriber(0) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

void DigitalInput::update() {
	if (this->countedInterrups >= this->coolDownInterrups) {
    this->value = digitalRead(this->pin);
    this->countedInterrups = 0;
		if (this->subscriber != 0) {
			this->subscriber->notify(this->pin);
		}
  } else {
    this->countedInterrups++;
  }
}

bool DigitalInput::isPressed() {
  return this->value == LOW;
}

bool DigitalInput::subscribe(Subscriber *subscriber) {
	if (this->subscriber != 0) {
		return false;
	}
	this->subscriber = subscriber;
	return true;
}
