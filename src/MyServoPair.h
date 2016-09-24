#ifndef MyServoPair_h
#define MyServoPair_h

#include "Motor.h"
#include "MyServo.h"
#include "AnalogInput.h"

class MyServoPair : public Motor {

	MyServo servoA;
  MyServo servoB;

protected:
  virtual void doWriteWithAnalog(AnalogInput& input, int direction);
	virtual void doWriteWithPosition(int position);

public:
	MyServoPair(int pinA, int minRotationA, int maxRotationA, int pinB, int minRotationB, int maxRotationB);
	virtual void setup();
	virtual void update();
};

#endif
