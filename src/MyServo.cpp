#include "MyServo.h"

MyServo::MyServo(int pin): Motor(), pin(pin), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
}

void MyServo::doWriteWithAnalog(AnalogInput& input) {
  int rawVal = input.read(-100, 100);
  int filteredVal = rawVal / 10;
	int finalVal = this->servo.read() + filteredVal;
	if (finalVal > 0 && finalVal < 180) {
		this->servo.write(finalVal);
	}
}

void MyServo::doWriteWithPosition(int position) {
	this->servo.write(position);
}

void MyServo::update() {}
