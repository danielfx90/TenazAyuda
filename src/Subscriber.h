#ifndef Subscriber_h
#define Subscriber_h

class Subscriber {

	bool notified;

protected:
	void resetNotification();

public:
	Subscriber();
	bool isNotified();
	void notify();
};

#endif
