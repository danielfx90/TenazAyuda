#include "MyServo.h"

MyServo::MyServo(int pin, int minRotation, int maxRotation)
	: Motor(), pin(pin), minRotation(minRotation), maxRotation(maxRotation), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
}

void MyServo::doWriteWithAnalog(AnalogInput& input, int direction) {
  int rawVal = input.read(-100, 100);
  int filteredVal = direction * rawVal / 10;
	int currentPosition = this->servo.read();
	int finalVal = currentPosition + filteredVal;

	if (finalVal > this->maxRotation) {
		finalVal = this->maxRotation;
	} else if (finalVal < this->minRotation) {
		finalVal = this->minRotation;
	}
	this->servo.write(finalVal);
}

void MyServo::doWriteWithPosition(int position) {
	this->servo.write(position);
}

void MyServo::update() {}
