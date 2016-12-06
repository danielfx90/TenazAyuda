#ifndef MyServoPair_h
#define MyServoPair_h

#include "Motor.h"
#include "MyServo.h"
#include "AnalogInput.h"
#include "DigitalInput.h"

class MyServoPair : public Motor {

	MyServo servoA;
  MyServo servoB;
	DigitalInput* pressureSensor;

protected:
  virtual void doWriteWithAnalog(AnalogInput& input);
	virtual void doWriteWithPosition(int position);
	virtual void doWriteWithRelativePosition(int position);

public:
	MyServoPair(int pinA, int minRotationA, int maxRotationA,
						  int pinB, int minRotationB, int maxRotationB,
						  float initialPosition, int movementInterval, int direction = 1);
	virtual void setup();
	virtual void update();
	void addPressureSensor(DigitalInput* sensor);
	virtual int getPosition();
	virtual bool hasHitLimit();
};

#endif
