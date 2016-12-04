#include "MyServoPair.h"

MyServoPair::MyServoPair(int pinA, int minRotationA, int maxRotationA,
												 int pinB, int minRotationB, int maxRotationB,
												 float initialPosition, int movementInterval)
	: Motor(),
		servoA(pinA, minRotationA, maxRotationA, initialPosition, movementInterval),
		servoB(pinB, minRotationB, maxRotationB, 180 - initialPosition, movementInterval),
		pressureSensor(0) {}

void MyServoPair::setup() {
	this->servoA.setup();
  this->servoB.setup();
}

void MyServoPair::doWriteWithAnalog(AnalogInput& input, int direction) {
  this->servoA.writeWithAnalog(input, direction);
  this->servoB.writeWithAnalog(input, -direction);
}

void MyServoPair::doWriteWithPosition(int position) {
  this->servoA.writeWithPosition(position);
  this->servoB.writeWithPosition(180 - position);
}

void MyServoPair::doWriteWithRelativePosition(int position, int direction) {
  this->servoA.writeWithRelativePosition(position * direction);
  this->servoB.writeWithRelativePosition(position * -direction);
}

void MyServoPair::addPressureSensor(DigitalInput* sensor) {
	this->pressureSensor = sensor;
}

void MyServoPair::update() {
//	if (this->pressureSensor != 0 && this->pressureSensor->isPressed()) {
//		this->servoA.move(-1, 1);
//		this->servoB.move(-1, -1);
//	}

  this->servoA.update();
  this->servoB.update();
}

int MyServoPair::getPosition() {
	return this->servoA.getPosition();
}
