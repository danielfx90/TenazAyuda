#ifndef MyStepper_h
#define MyStepper_h

#include <AccelStepper.h>
#include "Motor.h"
#include "AnalogInput.h"

class MyStepper : public Motor {

	int maxSpeed;
	int speed;
	AccelStepper stepper;

protected:
	virtual void doWriteWithAnalog(AnalogInput& input);
	virtual void doWriteWithPosition(int position);

public:
	MyStepper(int step, int direction, int maxSpeed, int speed);
	virtual void setup();
	virtual void update();
};

#endif
