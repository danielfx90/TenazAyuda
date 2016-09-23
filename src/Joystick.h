#ifndef Joystick_h
#define Joystick_h

#include "DigitalInput.h"
#include "AnalogInput.h"

class Joystick : public DigitalInput {

	AnalogInput xAxis;
	AnalogInput yAxis;

public:
	Joystick(int xAxisPin, int yAxisPin, int buttonPin, long buttonCoolDownInterrups);
	AnalogInput& getXAxisInput();
	AnalogInput& getYAxisInput();
};

#endif
