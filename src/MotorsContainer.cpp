#include "MotorsContainer.h"

MotorsContainer::MotorsContainer(Motor** motors, int quantity)
	: Subscriber(), motors(motors), quantity(quantity), currentPairSelection(0) {}

void MotorsContainer::setup() {
	for(int i = 0; i < this->quantity; i++) {
		this->motors[i]->setup();
	}
}

void MotorsContainer::writeWithJoystick(Joystick& joystick) {
	if (this->isNotified()) {
		if (joystick.isPressed()) {
	    this->currentPairSelection = (this->currentPairSelection + 2) % this->quantity;
	  }
		this->resetNotification();
	}
  this->motors[this->currentPairSelection]->writeWithAnalog(joystick.getYAxisInput());
	if ((this->currentPairSelection + 1) < this->quantity) {
		this->motors[this->currentPairSelection + 1]->writeWithAnalog(joystick.getXAxisInput());
	}
}

void MotorsContainer::writeWithPositions(int* positions, int positionsQuantity) {
	for(int i = 0; i < this->quantity && i < positionsQuantity; i++) {
		this->motors[i]->writeWithPosition(positions[i]);
	}
}

void MotorsContainer::update() {
	for(int i = 0; i < this->quantity; i++) {
		this->motors[i]->update();
	}
}
