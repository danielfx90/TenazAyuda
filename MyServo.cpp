#include "MyServo.h"

MyServo::MyServo(int pin): pin(pin), servo() {
	this->servo.attach(this->pin);
}

void MyServo::updateFromAnalog(int analogPin) {
  int analogVal = analogRead(analogPin);
  int rawVal = map(analogVal, 0, 1023, -100, 100);
  int finalVal = rawVal / 10;
  this->servo.write(this->servo.read() + finalVal);
}
