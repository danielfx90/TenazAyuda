#include "Motor.h"

Motor::Motor() : blocked(false) {}

void Motor::updateFromAnalog(AnalogInput& input) {
  if (!(this->isBlocked())) {
    this->doUpdateFromAnalog(input);
  }
}

void Motor::updateFromPosition(int position) {
  if (!(this->isBlocked())) {
    this->doUpdateFromPosition(position);
  }
}

bool Motor::isBlocked() {
  return this->blocked;
}

void Motor::setBlocked(bool block) {
  this->blocked = block;
}
