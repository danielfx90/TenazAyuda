#ifndef MotorsContainer_h
#define MotorsContainer_h

#include "Motor.h"
#include "Joystick.h"
#include "Subscriber.h"

class MotorsContainer : public Subscriber {

	Motor** motors;
	int quantity;
	int currentPairSelection;

public:
	MotorsContainer(Motor** motors, int quantity);
	void setup();
	bool isBlocked();
	void setBlocked(bool block);
	void writeWithJoystick(Joystick& joystick);
	void writeWithPositions(int* positions, int positionsQuantity);
	void update();
};

#endif
