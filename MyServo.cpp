#include "MyServo.h"

#include <Arduino.h>

MyServo::MyServo(int pin): pin(pin), servo() : Motor() {}

void MyServo::setUp() {
	this->servo.attach(this->pin);
}

void MyServo::updateFromAnalog(AnalogInput& input) {
  int rawVal = input.read(-100, 100);
  int finalVal = rawVal / 10;
  this->servo.write(this->servo.read() + finalVal);
}
