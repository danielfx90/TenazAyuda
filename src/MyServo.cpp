#include "MyServo.h"

MyServo::MyServo(int pin): pin(pin), servo() {}

void MyServo::setup() {
	this->servo.attach(this->pin);
}

void MyServo::updateFromAnalog(AnalogInput& input) {
  int rawVal = input.read(-100, 100);
  int finalVal = rawVal / 10;
  this->servo.write(this->servo.read() + finalVal);
}
