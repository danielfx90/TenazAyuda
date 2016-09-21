#include "MyServo.h"

MyServo::MyServo(int pin): Motor(), pin(pin), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
}

void MyServo::doWriteWithAnalog(AnalogInput& input) {
  int rawVal = input.read(-100, 100);
  int finalVal = rawVal / 10;
  this->servo.write(this->servo.read() + finalVal);
}

void MyServo::doWriteWithPosition(int position) {
	this->servo.write(position);
}

void MyServo::update() {}
