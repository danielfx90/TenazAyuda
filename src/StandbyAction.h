#ifndef StandbyAction_h
#define StandbyAction_h

#include "Action.h"
#include "MotorsContainer.h"

class StandbyAction : public Action {

  MotorsContainer* container;

protected:
	virtual void act();

public:
  void setContainer(MotorsContainer* container);
};

#endif
