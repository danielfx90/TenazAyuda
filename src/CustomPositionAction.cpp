#include "CustomPositionAction.h"

#include "Configuration.h"

CustomPositionAction::CustomPositionAction(int savePositionPin, int* positions, int positionsQuantity)
  : GoToAction(positions, positionsQuantity), savePositionPin(savePositionPin) {}

void CustomPositionAction::act() {
  if (this->isNotifiedBy(this->savePositionPin)) {
    this->saveCurrentPosition();
  } else {
    GoToAction::act();
  }
}

void CustomPositionAction::saveCurrentPosition() {
  for (int i = 0; i < this->positionsQuantity; i++) {
    int pos = this->container->getPosition(i);
    this->positions[i] = pos;
  }
}
