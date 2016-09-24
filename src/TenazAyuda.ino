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

DigitalInput up(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput right(RIGHT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput down(DOWN_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput left(LEFT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput start(START_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput select(SELECT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
Joystick joystick(X_AXIS, Y_AXIS, JOYSTICK_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);

DigitalInput buttons[] = {up, right, down, left, start, select, joystick}; // joystick button only, not the potentiometer

/* *****************************************************************************
 *                                   MOTORS                                    *
 * *****************************************************************************/

MyStepper stepperBase(8, 9, 400, 150);
MyStepper stepperRotador(10,11, 800, 120);
Motor* motors[] = { &stepperBase, &stepperRotador };
MotorsContainer motorsContainer(motors, 2);

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i].setup();
  }
}

void setup() {
  init_buttons();
  motorsContainer.setup();
  Serial.begin(9600);
}

/* ***************************************************************************************
 *                                       PROGRAMA                                        *
 * ***************************************************************************************/

void updateInputs() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i].update();
  }
  joystick.update();
}

void loop() {
  
  motorsContainer.update();
}
