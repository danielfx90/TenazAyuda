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
	void writeWithJoystick(Joystick& joystick);
	void writeWithPositions(int* positions, int positionsQuantity);
	void update();
};

#endif
