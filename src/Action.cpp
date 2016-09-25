#include "Action.h"

void Action::update() {
  if (this->isNotified()) {
    this->act();
    this->resetNotifications();
  }
}
