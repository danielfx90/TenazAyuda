#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : public Motor {

	int pin;
	Servo servo;

public:
	MyServo(int pin);
	virtual void setup();
	virtual void updateFromAnalog(AnalogInput& input);
	virtual void updateFromPosition(int position);
};

#endif
