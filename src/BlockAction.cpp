#include "BlockAction.h"

void BlockAction::act() {
  this->container->setBlocked(!(this->container->isBlocked()));
}
