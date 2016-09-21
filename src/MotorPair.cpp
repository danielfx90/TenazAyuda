#include "MotorPair.h"

MotorPair::MotorPair(Motor& motorA, Motor& motorB): motorA(motorA), motorB(motorB) {}

void MotorPair::setup() {
	this->motorA.setup();
	this->motorB.setup();
}

void MotorPair::updateFromJoystick(Joystick& joystick) {
  this->motorA.updateFromAnalog(joystick.getXAxisInput());
	this->motorB.updateFromAnalog(joystick.getYAxisInput());
}
