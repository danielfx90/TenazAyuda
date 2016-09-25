#include "Configuration.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
#include "Joystick.h"
#include "Motor.h"
#include "MyServo.h"
#include "MyServoPair.h"
#include "MyStepper.h"
#include "MotorsContainer.h"

bool DEBUG = true;

/* *****************************************************************************
 *                                   MOTORS                                    *
 * *****************************************************************************/

MyStepper stepperBase(MOTOR_BASE_STEP, MOTOR_BASE_DIRECTION, MOTOR_BASE_MAX_SPEED, MOTOR_BASE_ACCELERATION);
MyStepper stepperRotador(MOTOR_ROTADOR_STEP, MOTOR_ROTADOR_DIRECTION, MOTOR_ROTADOR_MAX_SPEED, MOTOR_ROTADOR_ACCELERATION);

MyServo servoElevacionBrazo(SERVO_ELEVACION_BRAZO_PIN, SERVO_ELEVACION_BRAZO_MIN_ROTATION, SERVO_ELEVACION_BRAZO_MAX_ROTATION);
MyServo servoElevacionMano(SERVO_ELEVACION_MANO_PIN, SERVO_ELEVACION_MANO_MIN_ROTATION, SERVO_ELEVACION_MANO_MAX_ROTATION);

MyServoPair servosTenazas(SERVO_TENAZAS_A_PIN, SERVO_TENAZAS_A_MIN_ROTATION, SERVO_TENAZAS_A_MAX_ROTATION,
                          SERVO_TENAZAS_B_PIN, SERVO_TENAZAS_B_MIN_ROTATION, SERVO_TENAZAS_B_MAX_ROTATION);

//Motor* motors[] = { &stepperBase, &stepperRotador, &servoElevacionBrazo, &servoElevacionMano, &servosTenazas };
Motor* motors[] = { &servosTenazas };
MotorsContainer motorsContainer(motors, 1);

/* *****************************************************************************
 *                                   INPUTS                                    *
 * *****************************************************************************/

DigitalInput up(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput right(RIGHT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput down(DOWN_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput left(LEFT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput start(START_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput select(SELECT_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
Joystick joystick(X_AXIS, Y_AXIS, JOYSTICK_BUTTON, BUTTON_INTERRUPTS_COOLDOWN, &motorsContainer);

DigitalInput buttons[] = {up, right, down, left, start, select, joystick}; // joystick button only, not the potentiometer

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i].setup();
  }
  joystick.setup();
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
  if (cyclesCount % 5 == 0) {
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
}
