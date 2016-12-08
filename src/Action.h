#ifndef Action_h
#define Action_h

#include "Subscriber.h"
#include "MotorsContainer.h"

class Action : public Subscriber {

protected:
	MotorsContainer* container;
	bool acting;

	virtual void act() = 0;

public:
	Action();
	void setContainer(MotorsContainer* container);
	bool update(bool resetNotifications = false);
};

#endif
