#include "Action.h"

Action::Action() : Subscriber() {}

void Action::update() {
  if (this->isNotified()) {
    this->act();
    this->resetNotifications();
  }
}
