#include "Motor.h"

Motor::Motor() : blocked(false) {}

bool Motor::isBlocked() {
  return this->blocked;
}

void Motor::setBlocked(bool block) {
  this->blocked = block;
}

void Motor::writeWithAnalog(AnalogInput& input, int direction) {
  if (!(this->isBlocked())) {
    this->doWriteWithAnalog(input, direction);
  }
}

void Motor::writeWithPosition(int position) {
  if (!(this->isBlocked())) {
    this->doWriteWithPosition(position);
  }
}

void Motor::writeWithRelativePosition(int position, int direction) {
  if (!(this->isBlocked())) {
    this->doWriteWithRelativePosition(position, direction);
  }
}
