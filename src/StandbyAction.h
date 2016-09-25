#ifndef StandbyAction_h
#define StandbyAction_h

#include "Action.h"
#include "MotorsContainer.h"

class StandbyAction : public Action {

  int standbyPin;
  long cyclesCount;
  MotorsContainer* container;

protected:
	virtual void act();

public:
  StandbyAction(int standbyPin);
  void setup();
  void setContainer(MotorsContainer* container);
};

#endif
