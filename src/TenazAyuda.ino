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

MyStepper stepperBase(MOTOR_BASE_STEP, MOTOR_BASE_DIRECTION, MOTOR_BASE_MAX_SPEED, MOTOR_BASE_ACCELERATION);
MyStepper stepperRotador(MOTOR_ROTADOR_STEP, MOTOR_ROTADOR_DIRECTION, MOTOR_ROTADOR_MAX_SPEED, MOTOR_ROTADOR_ACCELERATION);

MyServo servoElevacionBrazo(SERVO_ELEVACION_BRAZO_PIN);
MyServo servoElevacionMano(SERVO_ELEVACION_MANO_PIN);

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

volatile bool statedChanged = false;

void updateInputs() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i].update();
  }
  joystick.update();
}

void printStates() {
  Serial.print("UP: ");Serial.print(up.isPressed());Serial.print(" // ");
  Serial.print("RIGHT: ");Serial.print(right.isPressed());Serial.print(" // ");
  Serial.print("DOWN: ");Serial.print(down.isPressed());Serial.print(" // ");
  Serial.print("LEFT: ");Serial.print(left.isPressed());Serial.print(" // ");
  Serial.print("START: ");Serial.print(start.isPressed());Serial.print(" // ");
  Serial.print("SELECT: ");Serial.print(select.isPressed());Serial.print(" // ");
  Serial.print("xAxis: ");Serial.print(joystick.getXAxisInput().read(-100, 100));Serial.print(" // ");
  Serial.print("yAxis: ");Serial.print(joystick.getYAxisInput().read(-100, 100));Serial.print("\n");
}

int cyclesCount = 0;

void loop() {
  // temporal
  if (cyclesCount % 1000 == 0) {
    statedChanged = true;
    cyclesCount = 0;
  } else {
    cyclesCount++;
  }
  // -----------

  if (statedChanged) {
    updateInputs();
    motorsContainer.writeWithJoystick(joystick);
    statedChanged = false;
  }
  motorsContainer.update();

  if (DEBUG) {
    printStates();
  }
}
