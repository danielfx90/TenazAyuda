#include "MyStepper.h"

MyStepper::MyStepper(int step, int direction, int maxSpeed, int acceleration, int stoppingMaxSpeed)
    : Motor(), Subscriber(), maxSpeed(maxSpeed), acceleration(acceleration), stoppingMaxSpeed(stoppingMaxSpeed), stepper(1, step, direction) {}

void MyStepper::addLimitSensors(DigitalInput* limitSoftStop, DigitalInput* limitAHardStop, DigitalInput* limitBHardStop) {
  this->limitSoftStop = limitSoftStop;
  this->limitAHardStop = limitAHardStop;
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
    int finalVal = direction * val;
    this->stepper.move(finalVal);
  } else {
    this->stepper.stop();
  }
}

void MyStepper::doWriteWithPosition(int position) {
  this->stepper.moveTo(position);
}

bool MyStepper::limitIsActive(DigitalInput* limit) {
  return (limit != 0 && this->isNotifiedBy(limit->getPin()) && limit->isPressed());
}

void MyStepper::updateStepper() {
  if (this->limitIsActive(this->limitSoftStop)) {
    this->stepper.setMaxSpeed(this->stoppingMaxSpeed);
  } else {
    this->stepper.setMaxSpeed(this->maxSpeed);
  }

  if (this->limitIsActive(this->limitAHardStop) || this->limitIsActive(this->limitBHardStop)) {
    this->stepper.stop();
  } else {
    this->stepper.run();
  }
}

void MyStepper::update() {
  this->updateStepper();
  this->resetNotifications();
}
