#ifndef DigitalInput_h
#define DigitalInput_h

#include "Input.h"

class DigitalInput : public Input {

	int pin;
	int value;

protected:
  virtual void doUpdate();

public:
	DigitalInput(int pin, long coolDownInterrups);
  void setup();
	bool isPressed();
};

#endif
