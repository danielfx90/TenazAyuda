#include "Configuration.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
#include "Joystick.h"
#include "Motor.h"
#include "MyServo.h"
#include "MyStepper.h"
#include "MotorsContainer.h"

bool DEBUG = true;

/* ***************************************************************************************
 *                                      PINES BOTONERA                                   *
 * ***************************************************************************************/

const int buttons[] = {UP_BUTTON, DOWN_BUTTON, LEFT_BUTTON, RIGHT_BUTTON, START_BUTTON, SELECT_BUTTON, ANALOG_BUTTON};

/* ***************************************************************************************
 *                                         MOTORES                                       *
 * ***************************************************************************************/
const int servo_base_pin = 51;

Servo servo_base;

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   pinMode(buttons[i], INPUT_PULLUP);
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
