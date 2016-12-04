#include "StandbyAction.h"

#include "Configuration.h"

StandbyAction::StandbyAction(int standbyHighPin, int standbyLowPin, int* positions, int positionsQuantity)
  : GoToAction(positions, positionsQuantity),
    standbyHighPin(standbyHighPin), standbyLowPin(standbyLowPin) {}

void StandbyAction::setup() {
  pinMode(this->standbyHighPin, OUTPUT);
  pinMode(this->standbyLowPin, OUTPUT);
}

void StandbyAction::act() {
  GoToAction::act();
  if (!(this->acting)) {
    digitalWrite(this->standbyHighPin, HIGH);
    digitalWrite(this->standbyLowPin, LOW);
  }
}
