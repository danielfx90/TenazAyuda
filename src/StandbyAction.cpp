#include "StandbyAction.h"

#include "Configuration.h"

StandbyAction::StandbyAction(int standbyPin) : Action(), standbyPin(standbyPin), cyclesCount(0), container(0) {}

void StandbyAction::setup() {
  pinMode(this->standbyPin, OUTPUT);
}

void StandbyAction::setContainer(MotorsContainer* container) {
  this->container = container;
}

void StandbyAction::act() {
  if (this->container != 0) {
    if (cyclesCount == 0) {
      int positions[] = {0, 0, 0, 0, 0};
      this->container->writeWithPositions(positions, 5);
    }
    cyclesCount++;
    if (cyclesCount == STANDBY_CYCLES) {
      digitalWrite(this->standbyPin, STANDBY_SIGNAL);
    }
  }
}
