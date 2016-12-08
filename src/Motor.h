#ifndef Motor_h
#define Motor_h

#include "AnalogInput.h"

class Motor {

	bool blocked;

protected:
	int direction;
	
	virtual void doWriteWithAnalog(AnalogInput& input) = 0;
	virtual void doWriteWithPosition(int position) = 0;
	virtual void doWriteWithRelativePosition(int position) = 0;

public:
	Motor(int direction = 1);
	virtual void setup() = 0;

	bool isBlocked();
	virtual void setBlocked(bool block);
	void writeWithAnalog(AnalogInput& input);
	void writeWithPosition(int position);
	void writeWithRelativePosition(int position);
	virtual int getPosition() = 0;
	virtual bool hasHitLimit() = 0;
	virtual void update() = 0;
};

#endif
