#include "MyServoPair.h"

MyServoPair::MyServoPair(int pinA, int minRotationA, int maxRotationA,
												 int pinB, int minRotationB, int maxRotationB,
												 float initialPosition, int movementInterval, int direction)
	: Motor(direction),
		servoA(pinA, minRotationA, maxRotationA, initialPosition, movementInterval, direction),
		servoB(pinB, minRotationB, maxRotationB, 180 - initialPosition, movementInterval, -direction),
		pressureSensor(0) {}

void MyServoPair::setup() {
	this->servoA.setup();
  this->servoB.setup();
}

void MyServoPair::doWriteWithAnalog(AnalogInput& input) {
  this->servoA.writeWithAnalog(input);
  this->servoB.writeWithAnalog(input);
}

void MyServoPair::doWriteWithPosition(int position) {
  this->servoA.writeWithPosition(position);
  this->servoB.writeWithPosition(180 - position);
}

void MyServoPair::doWriteWithRelativePosition(int position) {
  this->servoA.writeWithRelativePosition(position);
  this->servoB.writeWithRelativePosition(position);
}

void MyServoPair::addPressureSensor(DigitalInput* sensor) {
	this->pressureSensor = sensor;
}

void MyServoPair::update() {
//	if (this->pressureSensor != 0 && this->pressureSensor->isPressed()) {
//		this->servoA.move(-1);
//		this->servoB.move(-1);
//	}

  this->servoA.update();
  this->servoB.update();
}

int MyServoPair::getPosition() {
	return this->servoA.getPosition();
}

bool MyServoPair::hasHitLimit() {
	return (this->servoA.hasHitLimit() || this->servoB.hasHitLimit());
}
