#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups, Subscriber* subscriber)
		: pin(pin), value(HIGH), coolDownInterrups(coolDownInterrups), countedInterrups(coolDownInterrups), subscriber(subscriber) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

void DigitalInput::update() {
	if (this->countedInterrups >= this->coolDownInterrups) {
    this->value = digitalRead(this->pin);
		this->value = LOW;
		Serial.print("Pin ");Serial.print(this->pin);Serial.print(": ");Serial.print(this->value);Serial.print("\n");
    this->countedInterrups = 0;
		if (this->subscriber != 0) {
			this->subscriber->notify();
		}
  } else {
    this->countedInterrups++;
  }
}

bool DigitalInput::isPressed() {
	Serial.print(this->value);Serial.print("\n");
  return this->value == LOW;
}
