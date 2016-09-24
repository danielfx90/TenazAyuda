#include "MyStepper.h"

MyStepper::MyStepper(int step, int direction, int maxSpeed, int acceleration)
    : Motor(), maxSpeed(maxSpeed), acceleration(acceleration), stepper(1, step, direction) {}

void MyStepper::setup() {
  this->stepper.setMaxSpeed(this->maxSpeed);
  this->stepper.setAcceleration(this->acceleration);
}

void MyStepper::doWriteWithAnalog(AnalogInput& input, int direction) {
  int rawVal = input.read(-512, 511);
  int val = abs(rawVal) > 100 ? rawVal : 0;
  int finalVal = this->stepper.currentPosition() + direction * val;
  this->stepper.moveTo(finalVal);
}

void MyStepper::doWriteWithPosition(int position) {
	this->stepper.moveTo(position);
}

void MyStepper::update() {
  this->stepper.run();
}
