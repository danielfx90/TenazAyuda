#ifndef BlockAction_h
#define BlockAction_h

#include "Action.h"
#include "MotorsContainer.h"

class BlockAction : public Action {

  MotorsContainer* container;

protected:
	virtual void act();

public:
  void setContainer(MotorsContainer* container);
};

#endif
