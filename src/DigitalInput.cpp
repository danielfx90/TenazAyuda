#include "DigitalInput.h"

DigitalInput::DigitalInput(int pin, long coolDownInterrups, int setupMode, int activeValue)
		: pin(pin), coolDownInterrups(coolDownInterrups), countedInterrups(0), isCounting(false),
			setupMode(setupMode), activeValue(activeValue), value(1 - activeValue), subscriber(0) {}

void DigitalInput::setup() {
	pinMode(this->pin, this->setupMode);
}

int DigitalInput::getPin() {
	return this->pin;
}

void DigitalInput::update() {
	if (this->isCounting) { // si está contando, ignoro todo
		this->countedInterrups++;
		this->isCounting = (this->countedInterrups < this->coolDownInterrups);
	} else {
		this->value = digitalRead(this->pin);
		if (this->value == this->activeValue) { // si está activado, reseteo el contador
			this->countedInterrups = 0;
			this->isCounting = true;

			if (this->subscriber != 0) { // le aviso a los subscriptores que se presionó el botón
				this->subscriber->notify(this->pin);
			}
		}
	}
}

bool DigitalInput::isPressed() {
  return this->value == this->activeValue;
}

bool DigitalInput::subscribe(Subscriber *subscriber) {
	if (this->subscriber != 0) {
		return false;
	}
	this->subscriber = subscriber;
	return true;
}
