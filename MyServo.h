#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>
#include <Servo.h>

class MyServo {
	
	int pin;
	Servo servo;
	
public:
	MyServo(int pin);
	void updateFromAnalog(int analogPin);
};

#endif
