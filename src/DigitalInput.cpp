#include "DigitalInput.h"

#include <Arduino.h>

DigitalInput::DigitalInput(int pin, long coolDownInterrups)
		: pin(pin), value(HIGH), coolDownInterrups(coolDownInterrups), countedInterrups(0), isCounting(false), subscriber(0) {}

void DigitalInput::setup() {
	pinMode(this->pin, INPUT_PULLUP);
}

int DigitalInput::getPin() {
	return this->pin;
}

void DigitalInput::update() {
/*	if (this->countedInterrups % 100 == 0 && this->countedInterrups > 0 && this->countedInterrups != 2000) {
		Serial.print("Count:");Serial.print(this->countedInterrups);Serial.print("\n");
	}
*/
	if (this->isCounting) { // si está contando, ignoro todo
		this->countedInterrups++;
		this->isCounting = (this->countedInterrups < this->coolDownInterrups);
	} else {
		this->value = digitalRead(this->pin);
		if (this->value == LOW) { // si está en pull-down, reseteo el contador
			this->countedInterrups = 0;
			this->isCounting = true;

			//Serial.print("PRESSING JOYSTICK!!\n");


			if (this->subscriber != 0) { // le aviso a los subscriptores que se presionó el botón
				this->subscriber->notify(this->pin);
			}
		}
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
