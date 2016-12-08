#include "Action.h"

Action::Action() : container(0), acting(false) {}

void Action::setContainer(MotorsContainer* container) {
  this->container = container;
}

bool Action::update(bool resetNotifications) {
  if (resetNotifications) {
    this->resetNotifications();
  }
  if (this->isNotified() || this->acting) {
    if (this->container != 0) {
      this->act();
    }
    this->resetNotifications();
    return true;
  }
  return false;
}
