#ifndef Action_h
#define Action_h

#include "Subscriber.h"

class Action : public Subscriber {

protected:
	virtual void act() = 0;

public:
	void update();
};

#endif
