#ifndef Action_h
#define Action_h

#include "Subscriber.h"
#include "MotorsContainer.h"

class Action : public Subscriber {

protected:
	MotorsContainer* container;

	virtual void act() = 0;

public:
	Action();
	void setContainer(MotorsContainer* container);
	void update();
};

#endif
