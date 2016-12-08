#ifndef AnalogInput_h
#define AnalogInput_h

class AnalogInput {

	int pin;
	int value;

public:
	AnalogInput(int pin);
	void update();
	float read(float from, float to);
};

#endif
