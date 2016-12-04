#include "Action.h"

Action::Action() : container(0), acting(false) {}

void Action::setContainer(MotorsContainer* container) {
  this->container = container;
}

void Action::update() {
  if (this->isNotified() || this->acting) {
    if (this->container != 0) {
      this->act();
    }
    this->resetNotifications();
  }
}
