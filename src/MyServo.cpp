#include "MyServo.h"

#include <Arduino.h>

MyServo::MyServo(int pin, float minRotation, float maxRotation)
	: Motor(), pin(pin), minRotation(minRotation), maxRotation(maxRotation),
	  movementInterval(100), countedCycles(0), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
	this->servo.write(100);
}

void MyServo::writePositionWithinRange(float value) {
	if (value > this->maxRotation) {
		value = this->maxRotation;
	} else if (value < this->minRotation) {
		value = this->minRotation;
	}
	//Serial.print("Servo ");Serial.print(this->pin);Serial.print(": ");Serial.print(value);Serial.print("\n");
	this->servo.write(value);
}

void MyServo::doWriteWithAnalog(AnalogInput& input, int direction) {
	if (this->countedCycles >= this->movementInterval) {
		this->countedCycles = 0;

		float rawVal = input.read(-100.0, 100.0);
		float filteredVal = rawVal / 100.0;
	  filteredVal = abs(filteredVal) > 0.1 ? filteredVal : 0.0;
		if (filteredVal != 0) {
			//Serial.print("Servo ");Serial.print(this->pin);Serial.print(": ");Serial.print(filteredVal);Serial.print("\n");

			float currentPosition = this->servo.read();
			float finalVal = currentPosition + direction * filteredVal;
			this->writePositionWithinRange(finalVal);
		}
	} else {
		this->countedCycles++;
	}
}

void MyServo::doWriteWithPosition(int position) {
	this->writePositionWithinRange(position);
}

void MyServo::update() {}
