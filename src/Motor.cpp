#include "Motor.h"

Motor::Motor(int direction) : blocked(false), direction(direction) {}

bool Motor::isBlocked() {
  return this->blocked;
}

void Motor::setBlocked(bool block) {
  this->blocked = block;
}

void Motor::writeWithAnalog(AnalogInput& input) {
  if (!(this->isBlocked())) {
    this->doWriteWithAnalog(input);
  }
}

void Motor::writeWithPosition(int position) {
  if (!(this->isBlocked())) {
    this->doWriteWithPosition(position);
  }
}

void Motor::writeWithRelativePosition(int position) {
  if (!(this->isBlocked())) {
    this->doWriteWithRelativePosition(position);
  }
}
