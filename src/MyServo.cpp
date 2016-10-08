#include "MyServo.h"

#include <Arduino.h>

MyServo::MyServo(int pin, float minRotation, float maxRotation)
	: Motor(), pin(pin), minRotation(minRotation), maxRotation(maxRotation), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
	this->servo.write(20);
}

void MyServo::writePositionWithinRange(float value) {
	if (value > this->maxRotation) {
		value = this->maxRotation;
	} else if (value < this->minRotation) {
		value = this->minRotation;
	}
	this->servo.write(value);
}

void MyServo::doWriteWithAnalog(AnalogInput& input, int direction) {
  float rawVal = input.read(-100.0, 100.0);
	float filteredVal = rawVal / 100.0;
  filteredVal = abs(filteredVal) > 0.1 ? filteredVal : 0.0;
	if (filteredVal != 0) {
		float currentPosition = this->servo.read();
		float finalVal = currentPosition + direction * filteredVal;
		this->writePositionWithinRange(finalVal);
	}
}

void MyServo::doWriteWithPosition(int position) {
	this->writePositionWithinRange(position);
}

void MyServo::update() {}
