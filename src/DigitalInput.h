#ifndef DigitalInput_h
#define DigitalInput_h

#include "Subscriber.h"
#include <Arduino.h>

class DigitalInput {

	int pin;
	long coolDownInterrups;
  long countedInterrups;
	bool isCounting;
	int setupMode;
	int activeValue;
	int value;

	Subscriber* subscriber;

public:
	DigitalInput(int pin, long coolDownInterrups, int setupMode = INPUT_PULLUP, int activeValue = LOW);
	int getPin();
  void setup();
	void update();
	bool isPressed();
	bool subscribe(Subscriber* subscriber);
};

#endif
