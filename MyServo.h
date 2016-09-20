#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : Motor {
	
	int pin;
	Servo servo;
	
public:
	MyServo(int pin);
	// void setUp();
	// void updateFromAnalog(AnalogInput& input);
};

#endif
