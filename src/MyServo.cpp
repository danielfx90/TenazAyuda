#include "MyServo.h"

#include <Arduino.h>

MyServo::MyServo(int pin, float minRotation, float maxRotation, float initialPosition, int movementInterval, int direction)
	: Motor(direction), pin(pin), minRotation(minRotation), maxRotation(maxRotation),
	  initialPosition(initialPosition), movementInterval(movementInterval), countedCycles(0), servo() {}

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

void MyServo::doWriteWithAnalog(AnalogInput& input) {
	if (this->countedCycles >= this->movementInterval) {
		this->countedCycles = 0;
		float rawVal = input.read(-100.0, 100.0);
		float filteredVal = rawVal / 100.0;
		filteredVal = abs(filteredVal) > 0.1 ? filteredVal : 0.0;
		this->move(filteredVal);
	} else {
		this->countedCycles++;
	}
}

void MyServo::doWriteWithPosition(int position) {
	this->writePositionWithinRange(position);
}

void MyServo::doWriteWithRelativePosition(int position) {
	this->move(position);
}

void MyServo::update() {}

void MyServo::move(float relativePosition) {
	if (relativePosition != 0) {
		float currentPosition = this->servo.read();
		float finalVal = currentPosition + this->direction * relativePosition;
		this->writePositionWithinRange(finalVal);
	}
}

int MyServo::getPosition() {
	return this->servo.read();
}

bool MyServo::hasHitLimit() {
	int pos = this->getPosition();
	return (pos == this->minRotation || pos == this->maxRotation);
}
