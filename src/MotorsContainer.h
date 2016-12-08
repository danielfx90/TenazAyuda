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
	void resetPairSelection();
	void writeWithJoystick(Joystick& joystick);
	void writeWithPositions(int* positions, int positionsQuantity);
	void writeWithRelativePosition(int position, int motorIndex);
	int getPosition(int motorIndex);
	bool motorHasHitLimit(int motorIndex);
	void update();
};

#endif
