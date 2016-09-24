#include "Subscriber.h"

Subscriber::Subscriber() : notified(false) {}

void Subscriber::resetNotification() {
	this->notified = false;
}

bool Subscriber::isNotified() {
  return this->notified;
}

void Subscriber::notify() {
	this->notified = true;
}
