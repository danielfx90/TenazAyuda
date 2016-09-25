#include "Subscriber.h"

Subscriber::Subscriber() {
	this->notifiedPins = new Vector<int>();
}

void Subscriber::resetNotifications() {
	delete this->notifiedPins;
	this->notifiedPins = new Vector<int>();
}

bool Subscriber::isNotifiedBy(int pin) {
	bool exists = false;
	for (int i = 0; i < this->notifiedPins->size(); i++) {
		if ((*this->notifiedPins)[i] == pin) {
			exists = true;
		}
	}
	return exists;
}

void Subscriber::notify(int pin) {
	if (!(this->isNotifiedBy(pin))) {
		this->notifiedPins->push_back(pin);
	}
}
