#ifndef AnalogInput_h
#define AnalogInput_h

class AnalogInput {
	
	int pin;
	
public:
	AnalogInput(int pin);
	int read(int from, int to);
};

#endif

