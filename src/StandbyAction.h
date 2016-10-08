#ifndef StandbyAction_h
#define StandbyAction_h

#include "GoToAction.h"

class StandbyAction : public GoToAction {

  int standbyPin;
  long cyclesCount;

protected:
	virtual void act();

public:
  StandbyAction(int standbyPin, int* positions, int positionsQuantity);
  void setup();
};

#endif
