#ifndef MyServo_h
#define MyServo_h

#include <Servo.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyServo : public Motor {

	int pin;
	float minRotation;
	float maxRotation;
	float initialPosition;

	int movementInterval;
	int countedCycles;
	Servo servo;

	void writePositionWithinRange(float value);

protected:
	virtual void doWriteWithAnalog(AnalogInput& input);
	virtual void doWriteWithPosition(int position);
	virtual void doWriteWithRelativePosition(int position);

public:
	MyServo(int pin, float minRotation, float maxRotation, float initialPosition, int movementInterval, int direction = 1);
	virtual void setup();
	virtual void update();
	void move(float relativePosition);
	virtual int getPosition();
	virtual bool hasHitLimit();
};

#endif
