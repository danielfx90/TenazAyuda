#ifndef Motor_h
#define Motor_h

#include "AnalogInput.h"

class Motor {

	bool blocked;

protected:
	virtual void doWriteWithAnalog(AnalogInput& input) = 0;
	virtual void doWriteWithPosition(int position) = 0;

public:
	Motor();
	virtual void setup() = 0;

	bool isBlocked();
	void setBlocked(bool block);
	void writeWithAnalog(AnalogInput& input);
	void writeWithPosition(int position);
	virtual void update() = 0;
};

#endif
