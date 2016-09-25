#ifndef MyStepper_h
#define MyStepper_h

#include <AccelStepper.h>
#include "Motor.h"
#include "Subscriber.h"
#include "AnalogInput.h"
#include "DigitalInput.h"

class MyStepper : public Motor, public Subscriber {

	int maxSpeed;
	int acceleration;
	int stoppingMaxSpeed;
	AccelStepper stepper;

	DigitalInput* limitASoftStop;
	DigitalInput* limitAHardStop;

	DigitalInput* limitBSoftStop;
	DigitalInput* limitBHardStop;

	void checkLimit(DigitalInput* limitSoftStop, DigitalInput* limitHardStop);
	void checkLimits();

protected:
	virtual void doWriteWithAnalog(AnalogInput& input, int direction);
	virtual void doWriteWithPosition(int position);

public:
	MyStepper(int step, int direction, int maxSpeed, int acceleration, int stoppingMaxSpeed);
	void addLimitSensors(DigitalInput* limitASoftStop, DigitalInput* limitAHardStop, DigitalInput* limitBSoftStop, DigitalInput* limitBHardStop);
	virtual void setup();
	virtual void update();
};

#endif
