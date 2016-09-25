#include "BlockAction.h"

void BlockAction::setContainer(MotorsContainer* container) {
  this->container = container;
}

void BlockAction::act() {
  if (this->container != 0) {
    this->container->setBlocked(!(this->container->isBlocked()));
  }
}
