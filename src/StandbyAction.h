#ifndef StandbyAction_h
#define StandbyAction_h

#include "Action.h"

class StandbyAction : public Action {

  int standbyPin;
  long cyclesCount;

protected:
	virtual void act();

public:
  StandbyAction(int standbyPin);
  void setup();
};

#endif
