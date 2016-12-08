#ifndef Subscriber_h
#define Subscriber_h

#include <Vector.h>

class Subscriber {

	Vector<int>* notifiedPins;

protected:
	void resetNotifications();

public:
	Subscriber();
	bool isNotified();
	bool isNotifiedBy(int pin);
	void notify(int pin);
};

#endif
