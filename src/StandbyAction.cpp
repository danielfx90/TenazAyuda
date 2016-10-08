#include "StandbyAction.h"

#include "Configuration.h"

StandbyAction::StandbyAction(int standbyPin, int* positions, int positionsQuantity)
  : GoToAction(positions, positionsQuantity),
    standbyPin(standbyPin), cyclesCount(0) {}

void StandbyAction::setup() {
  pinMode(this->standbyPin, OUTPUT);
}

void StandbyAction::act() {
  if (cyclesCount == 0) {
    GoToAction::act();
  }
  cyclesCount++;
  if (cyclesCount == STANDBY_CYCLES) {
    digitalWrite(this->standbyPin, STANDBY_SIGNAL);
  }
}
