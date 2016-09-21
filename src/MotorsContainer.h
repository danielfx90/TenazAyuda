#ifndef MotorsContainer_h
#define MotorsContainer_h

#include "Motor.h"
#include "Joystick.h"

class MotorsContainer {

	Motor** motors;
	int quantity;
	int currentPairSelection;

public:
	MotorsContainer(Motor** motors, int quantity);
	void setup();
	void updateFromJoystick(Joystick& joystick);
	void updateFromPositions(int* positions, int positionsQuantity);
};

#endif
