#ifndef Motor_h
#define Motor_h

#include "AnalogInput.h"

class Motor {
	
	bool blocked;

protected:
	virtual void doUpdateFromAnalog(AnalogInput& input) = 0;
	virtual void doUpdateFromPosition(int position) = 0;

public:
	Motor();
	virtual void setup() = 0;

	void updateFromAnalog(AnalogInput& input);
	void updateFromPosition(int position);
	bool isBlocked();
	void setBlocked(bool block);
};

#endif
