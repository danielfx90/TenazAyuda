#include "Configuration.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
#include "Joystick.h"
#include "Motor.h"
#include "MyServo.h"
#include "MyStepper.h"
#include "MotorsContainer.h"

bool DEBUG = true;

/* *****************************************************************************
 *                                   INPUTS                                    *
 * *****************************************************************************/

DigitalInput up(UP_BUTTON);
DigitalInput right(RIGHT_BUTTON);
DigitalInput down(DOWN_BUTTON);
DigitalInput left(LEFT_BUTTON);
DigitalInput start(START_BUTTON);
DigitalInput select(SELECT_BUTTON);
Joystick joystick(X_AXIS, Y_AXIS, JOYSTICK_BUTTON);

DigitalInput buttons[] = {up, right, down, left, start, select, joystick}; // joystick button only, not the potentiometer

/* *****************************************************************************
 *                                   MOTORS                                    *
 * *****************************************************************************/
const int servo_base_pin = 51;

Servo servo_base;

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i].setup();
  }
}

void attach_servos() {
  servo_base.attach(servo_base_pin);
}

void setup() {
  init_buttons();
  attach_servos();
  Serial.begin(9600);
}

/* ***************************************************************************************
 *                                       PROGRAMA                                        *
 * ***************************************************************************************/

void update_servo(int axis_id, Servo* servo) {
  int val = analogRead(axis_id);
  val = map(val, 0, 1023, -100, 100);
  int final_val = val / 10;
  servo->write(servo->read() + final_val);
}

void update_servos_pair() {
  update_servo(X_AXIS, &servo_base);
}

void loop() {
  update_servos_pair();
  delay(150);
}
