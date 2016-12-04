#include "MyServo.h"

#include <Arduino.h>

MyServo::MyServo(int pin, float minRotation, float maxRotation, float initialPosition, int movementInterval)
	: Motor(), pin(pin), minRotation(minRotation), maxRotation(maxRotation),
	  initialPosition(100), movementInterval(100), countedCycles(0), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
	this->writePositionWithinRange(this->initialPosition);
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
	if (this->countedCycles >= this->movementInterval) {
		this->countedCycles = 0;
		float rawVal = input.read(-100.0, 100.0);
		float filteredVal = rawVal / 100.0;
		filteredVal = abs(filteredVal) > 0.1 ? filteredVal : 0.0;
		this->move(filteredVal, direction);
	} else {
		this->countedCycles++;
	}
}

void MyServo::doWriteWithPosition(int position) {
	this->writePositionWithinRange(position);
}

void MyServo::doWriteWithRelativePosition(int position, int direction) {
	this->move(position, direction);
}

void MyServo::update() {}

void MyServo::move(float relativePosition, int direction) {
	if (relativePosition != 0) {
		float currentPosition = this->servo.read();
		float finalVal = currentPosition + direction * relativePosition;
		this->writePositionWithinRange(finalVal);
	}
}

int MyServo::getPosition() {
	return this->servo.read();
}
