#ifndef MotorPair_h
#define MotorPair_h

#include "Motor.h"
#include "Joystick.h"

class MotorPair {

	Motor& motorA;
	Motor& motorB;

public:
	MotorPair(Motor& motorA, Motor& motorB);
	void setup();
	void updateFromJoystick(Joystick& joystick);
};

#endif
