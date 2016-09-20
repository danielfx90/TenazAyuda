#ifndef Motor_h
#define Motor_h

#include "AnalogInput.h"

class Motor {
	
public:
	virtual void setUp() = 0;
	virtual void updateFromAnalog(AnalogInput& input) = 0;
};

#endif
