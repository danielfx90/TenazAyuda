#ifndef DigitalInput_h
#define DigitalInput_h

class DigitalInput {

	int pin;

public:
	DigitalInput(int pin);
  void setup();
	bool isPressed();
};

#endif
