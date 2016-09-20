#include "AnalogInput.h"

#include <Arduino.h>

AnalogInput::AnalogInput(int pin): pin(pin) {
}

int AnalogInput::read(int from, int to) {
  int rawVal = analogRead(this->pin);
  return map(rawVal, 0, 1023, from, to);
}
