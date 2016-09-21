#include "MotorsContainer.h"

MotorsContainer::MotorsContainer(Motor** motors, int quantity)
	: motors(motors), quantity(quantity), currentPairSelection(0) {}

void MotorsContainer::setup() {
	for(int i = 0; i < this->quantity; i++) {
		this->motors[i]->setup();
	}
}

void MotorsContainer::updateFromJoystick(Joystick& joystick) {
	if (joystick.isPressed()) {
    this->currentPairSelection = (this->currentPairSelection + 2) % this->quantity;
  }
  this->motors[this->currentPairSelection]->updateFromAnalog(joystick.getXAxisInput());
	if ((this->currentPairSelection + 1) < this->quantity) {
		this->motors[this->currentPairSelection + 1]->updateFromAnalog(joystick.getYAxisInput());
	}
}

void MotorsContainer::updateFromPositions(int* positions, int positionsQuantity) {
	for(int i = 0; i < this->quantity && i < positionsQuantity; i++) {
		this->motors[i]->updateFromPosition(positions[i]);
	}
}
