#include "Joystick.h"

Joystick::Joystick(int xAxisPin, int yAxisPin, int buttonPin)
        : DigitalInput(buttonPin), xAxis(xAxisPin), yAxis(yAxisPin) {}

AnalogInput& Joystick::getXAxisInput() {
  return this->xAxis;
}

AnalogInput& Joystick::getYAxisInput() {
  return this->yAxis;
}
