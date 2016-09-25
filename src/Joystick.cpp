#include "Joystick.h"

Joystick::Joystick(int xAxisPin, int yAxisPin, int buttonPin, long buttonCoolDownInterrups, Subscriber* subscriber)
        : DigitalInput(buttonPin, buttonCoolDownInterrups, subscriber), xAxis(xAxisPin), yAxis(yAxisPin) {}

AnalogInput& Joystick::getXAxisInput() {
  return this->xAxis;
}

AnalogInput& Joystick::getYAxisInput() {
  return this->yAxis;
}

void Joystick::update() {
  this->xAxis.update();
  this->yAxis.update();
}
