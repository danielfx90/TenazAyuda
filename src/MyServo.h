#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : public Motor {

	int pin;
	int minRotation;
	int maxRotation;
	Servo servo;

protected:
	virtual void doWriteWithAnalog(AnalogInput& input, int direction);
	virtual void doWriteWithPosition(int position);

public:
	MyServo(int pin, int minRotation, int maxRotation);
	virtual void setup();
	virtual void update();
};

#endif
