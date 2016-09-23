#ifndef DigitalInput_h
#define DigitalInput_h

class DigitalInput {

	int pin;
	int value;
	long coolDownInterrups;
  long countedInterrups;

public:
	DigitalInput(int pin, long coolDownInterrups);
  void setup();
	void update();
	bool isPressed();
};

#endif
