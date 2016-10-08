#ifndef GoToAction_h
#define GoToAction_h

#include "Action.h"

class GoToAction : public Action {

	int* positions;
  int positionsQuantity;

protected:
	virtual void act();

public:
  GoToAction(int* positions, int positionsQuantity);
};

#endif
