#include "MyStepper.h"

MyStepper::MyStepper(int step, int direction, int maxSpeed, int acceleration)
    : Motor(), maxSpeed(maxSpeed), acceleration(acceleration), stepper(1, step, direction) {}

void MyStepper::setup() {
  this->stepper.setMaxSpeed(this->maxSpeed);
  this->stepper.setAcceleration(this->acceleration);
}

void MyStepper::doWriteWithAnalog(AnalogInput& input, int direction) {
  int rawVal = input.read(-100, 100);
  int finalVal = abs(rawVal) > 10 ? rawVal : 0;
  this->stepper.move(direction * finalVal);
}

void MyStepper::doWriteWithPosition(int position) {
	this->stepper.moveTo(position);
}

void MyStepper::update() {
  this->stepper.run();
}
