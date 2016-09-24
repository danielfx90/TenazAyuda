#include "AnalogInput.h"

#include <Arduino.h>

AnalogInput::AnalogInput(int pin): pin(pin), value(0) {}

void AnalogInput::update() {
  this->value = analogRead(this->pin);
}

int AnalogInput::read(int from, int to) {
  return map(this->value, 0, 1023, from, to);
}
