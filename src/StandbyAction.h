#ifndef StandbyAction_h
#define StandbyAction_h

#include "GoToAction.h"

class StandbyAction : public GoToAction {

  int standbyHighPin;
  int standbyLowPin;

protected:
	virtual void act();

public:
  StandbyAction(int standbyHighPin, int standbyLowPin, int* positions, int positionsQuantity);
  void setup();
};

#endif
