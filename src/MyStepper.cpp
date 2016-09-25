#include "MyStepper.h"

MyStepper::MyStepper(int step, int direction, int maxSpeed, int acceleration, int stoppingMaxSpeed)
    : Motor(), Subscriber(), maxSpeed(maxSpeed), acceleration(acceleration), stoppingMaxSpeed(stoppingMaxSpeed), stepper(1, step, direction) {}

void MyStepper::addLimitSensors(DigitalInput* limitASoftStop, DigitalInput* limitAHardStop, DigitalInput* limitBSoftStop, DigitalInput* limitBHardStop) {
  this->limitASoftStop = limitASoftStop;
  this->limitAHardStop = limitAHardStop;
  this->limitBSoftStop = limitBSoftStop;
  this->limitBHardStop = limitBHardStop;
}

void MyStepper::setup() {
  this->stepper.setMaxSpeed(this->maxSpeed);
  this->stepper.setAcceleration(this->acceleration);
}

void MyStepper::doWriteWithAnalog(AnalogInput& input, int direction) {
  int rawVal = input.read(-512, 511);
  int val = abs(rawVal) > 100 ? rawVal : 0;
  if (val != 0) {
    int finalVal = this->stepper.currentPosition() + direction * val;
    this->stepper.moveTo(finalVal);
  }
}

void MyStepper::doWriteWithPosition(int position) {
	this->stepper.moveTo(position);
}

void MyStepper::checkLimit(DigitalInput* limitSoftStop, DigitalInput* limitHardStop) {
  if (limitSoftStop != 0 && this->isNotifiedBy(limitSoftStop->getPin()) && limitSoftStop->isPressed()) {
    this->stepper.setMaxSpeed(this->stoppingMaxSpeed);
  } else {
    this->stepper.setMaxSpeed(this->maxSpeed);
  }
  if (limitHardStop != 0 && this->isNotifiedBy(limitHardStop->getPin()) && limitHardStop->isPressed()) {
    this->stepper.stop();
  }
}

void MyStepper::checkLimits() {
  this->checkLimit(this->limitASoftStop, this->limitAHardStop);
  this->checkLimit(this->limitBSoftStop, this->limitBHardStop);
  this->resetNotifications();
}

void MyStepper::update() {
  this->checkLimits();
  this->stepper.run();
}
