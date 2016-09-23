#include "Input.h"

Input::Input(long coolDownInterrups): coolDownInterrups(coolDownInterrups), countedInterrups(0) {}

void Input::update() {
	if (countedInterrups >= coolDownInterrups) {
    doUpdate();
    countedInterrups = 0;
  } else {
    countedInterrups++;
  }
}
