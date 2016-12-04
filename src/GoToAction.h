#ifndef GoToAction_h
#define GoToAction_h

#include "Action.h"

class GoToAction : public Action {

protected:
	int* positions;
	int positionsQuantity;
	
	virtual void act();

public:
  GoToAction(int* positions, int positionsQuantity);
};

#endif
