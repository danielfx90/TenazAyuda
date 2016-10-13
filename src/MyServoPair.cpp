#include "MyServoPair.h"

MyServoPair::MyServoPair(int pinA, int minRotationA, int maxRotationA,
												 int pinB, int minRotationB, int maxRotationB,
												 float initialPosition, int movementInterval)
	: Motor(),
		servoA(pinA, minRotationA, maxRotationA, initialPosition, movementInterval),
		servoB(pinB, minRotationB, maxRotationB, 180 - initialPosition, movementInterval) {}

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

void MyServoPair::update() {
  this->servoA.update();
  this->servoB.update();
}
