#ifndef DigitalInput_h
#define DigitalInput_h

#include "Subscriber.h"

class DigitalInput {

	int pin;
	int value;
	long coolDownInterrups;
  long countedInterrups;

	Subscriber* subscriber;

public:
	DigitalInput(int pin, long coolDownInterrups);
	int getPin();
  void setup();
	void update();
	bool isPressed();
	bool subscribe(Subscriber* subscriber);
};

#endif
