#include "GoToAction.h"

#include <Arduino.h>

#define ACT_STEP 10

GoToAction::GoToAction(int* positions, int positionsQuantity)
  : positions(positions), positionsQuantity(positionsQuantity) {}

void GoToAction::act() {
  int motorsInPosition = 0;
  for (int i = 0; i < this->positionsQuantity; i++) {
    int currentPosition = this->container->getPosition(i);
    int diff = abs(this->positions[i] - currentPosition);
    int finalMovement = min(diff, ACT_STEP);
    if (finalMovement > 0 && !(this->container->motorHasHitLimit(i))) {
      int direction = this->positions[i] > currentPosition ? 1 : -1;
      this->container->writeWithRelativePosition(direction * finalMovement, i);
    } else {
      motorsInPosition++;
    }
  }
  this->acting = (motorsInPosition != this->positionsQuantity);
}
