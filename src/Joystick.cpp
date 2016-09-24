#include "Joystick.h"

Joystick::Joystick(int xAxisPin, int yAxisPin, int buttonPin, long buttonCoolDownInterrups)
        : DigitalInput(buttonPin, buttonCoolDownInterrups), xAxis(xAxisPin), yAxis(yAxisPin) {}

AnalogInput& Joystick::getXAxisInput() {
  return this->xAxis;
}

AnalogInput& Joystick::getYAxisInput() {
  return this->yAxis;
}
