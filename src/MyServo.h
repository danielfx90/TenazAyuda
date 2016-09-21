#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : public Motor {

	int pin;
	Servo servo;

protected:
	virtual void doUpdateFromAnalog(AnalogInput& input);
	virtual void doUpdateFromPosition(int position);

public:
	MyServo(int pin);
	virtual void setup();
};

#endif
