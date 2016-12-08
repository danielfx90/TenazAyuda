#ifndef CustomPositionAction_h
#define CustomPositionAction_h

#include "GoToAction.h"

class CustomPositionAction : public GoToAction {

  int savePositionPin;
  int triggerPin;

  void saveCurrentPosition();
  
protected:
	virtual void act();

public:
  CustomPositionAction(int savePositionPin, int* positions, int positionsQuantity);
};

#endif
