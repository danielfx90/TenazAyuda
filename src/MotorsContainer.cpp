#include "MotorsContainer.h"

MotorsContainer::MotorsContainer(Motor** motors, int quantity)
	: Subscriber(), motors(motors), quantity(quantity), currentPairSelection(0) {}

void MotorsContainer::setup() {
	for(int i = 0; i < this->quantity; i++) {
		if (this->motors[i] != 0) {
			this->motors[i]->setup();
		}
	}
}

void MotorsContainer::writeWithJoystick(Joystick& joystick) {
	if (this->isNotifiedBy(joystick.getPin())) {
		if (joystick.isPressed()) {
	    this->currentPairSelection = (this->currentPairSelection + 2) % this->quantity;
			if ((this->currentPairSelection / 2) == 0) {
				this->currentPairSelection = 0; // if quantity is odd, currentPairSelection may be 1 after first cycle.
			}
	  }
		this->resetNotifications();
	}

	if (this->motors[this->currentPairSelection] != 0) {
		this->motors[this->currentPairSelection]->writeWithAnalog(joystick.getYAxisInput());
	}

	if (this->motors[this->currentPairSelection + 1] != 0 && (this->currentPairSelection + 1) < this->quantity) {
		this->motors[this->currentPairSelection + 1]->writeWithAnalog(joystick.getXAxisInput());
	}
}

void MotorsContainer::writeWithPositions(int* positions, int positionsQuantity) {
	for(int i = 0; i < this->quantity && i < positionsQuantity; i++) {
		if (this->motors[i] != 0 && positions[i] != 0) {
			this->motors[i]->writeWithPosition(positions[i]);
		}
	}
}

void MotorsContainer::update() {
	for(int i = 0; i < this->quantity; i++) {
		if (this->motors[i] != 0) {
			this->motors[i]->update();
		}
	}
}
