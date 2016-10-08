#include "GoToAction.h"

GoToAction::GoToAction(int* positions, int positionsQuantity)
  : positions(positions), positionsQuantity(positionsQuantity) {}

void GoToAction::act() {
  this->container->writeWithPositions(this->positions, this->positionsQuantity);
}
