#ifndef DigitalInput_h
#define DigitalInput_h

#include "Subscriber.h"

class DigitalInput {

	int pin;
	int value;
	long coolDownInterrups;
  long countedInterrups;

	Subscriber& subscriber;

public:
	DigitalInput(int pin, long coolDownInterrups, Subscriber& subscriber);
  void setup();
	void update();
	bool isPressed();
};

#endif
