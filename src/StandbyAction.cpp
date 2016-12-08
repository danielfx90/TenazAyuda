#include "StandbyAction.h"

#include "Configuration.h"

StandbyAction::StandbyAction(int standbyHighPin, int standbyLowPin, int* positions, int positionsQuantity)
  : GoToAction(positions, positionsQuantity),
    standbyHighPin(standbyHighPin), standbyLowPin(standbyLowPin) {}

void StandbyAction::enablePins() {
  digitalWrite(this->standbyHighPin, LOW);
  digitalWrite(this->standbyLowPin, HIGH);
}

void StandbyAction::setup() {
  pinMode(this->standbyHighPin, OUTPUT);
  pinMode(this->standbyLowPin, OUTPUT);
  this->enablePins();
}

void StandbyAction::act() {
  if (this->container->isBlocked()) {
    this->enablePins();
    this->container->setBlocked(false);
    this->container->resetPairSelection();
  } else {
    //GoToAction::act();
    //if (!(this->acting)) {
      digitalWrite(this->standbyHighPin, HIGH);
      digitalWrite(this->standbyLowPin, LOW);
      this->container->setBlocked(true);
    //}
  }
}
