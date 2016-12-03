#include "MyStepper.h"

MyStepper::MyStepper(int step, int direction, int maxSpeed, int acceleration, int stoppingMaxSpeed)
    : Motor(), Subscriber(), maxSpeed(maxSpeed), acceleration(acceleration), stoppingMaxSpeed(stoppingMaxSpeed),
    stepper(1, step, direction), goingToLimitA(true) {}

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
    this->goingToLimitA = rawVal < 0;
    this->stepper.move(finalVal);
  } else {
    this->stepper.stop();
  }
}

void MyStepper::doWriteWithPosition(int position) {
  this->stepper.moveTo(position);
}

bool MyStepper::limitIsActive(DigitalInput* limit) {
  return (limit != 0 && limit->isPressed());
}

bool MyStepper::mustActivateHardLimit(DigitalInput* limit, bool mustGoToA) {
  return (this->limitIsActive(limit) && this->goingToLimitA == mustGoToA);
}

void MyStepper::updateStepper() {
  if (this->limitIsActive(this->limitSoftStop)) {
    this->stepper.setMaxSpeed(this->stoppingMaxSpeed);
  } else {
    this->stepper.setMaxSpeed(this->maxSpeed);
  }

  if (this->mustActivateHardLimit(this->limitAHardStop, true)
  || this->mustActivateHardLimit(this->limitBHardStop, false)) {
    this->stepper.stop();
    this->stepper.moveTo(this->stepper.currentPosition());
    if (this->maxSpeed == 360) {
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    }
  } else {
    this->stepper.run();
    if (this->maxSpeed == 360) {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    }
  }
}

void MyStepper::update() {
  this->updateStepper();
  this->resetNotifications();
}
