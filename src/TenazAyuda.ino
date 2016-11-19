#include "Configuration.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
#include "Joystick.h"
#include "Motor.h"
#include "MyServo.h"
#include "MyServoPair.h"
#include "MyStepper.h"
#include "MotorsContainer.h"
#include "StandbyAction.h"
#include "BlockAction.h"
#include "GoToAction.h"

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

DigitalInput* buttons[] = {&up, &right, &down, &left, &start, &select, &joystick}; // joystick button only, not the potentiometer

/* *****************************************************************************
 *                                   MOTORS                                    *
 * *****************************************************************************/

MyStepper stepperBase(MOTOR_BASE_STEP, MOTOR_BASE_DIRECTION, MOTOR_BASE_MAX_SPEED, MOTOR_BASE_ACCELERATION, MOTOR_BASE_STOPPING_MAX_SPEED);
MyStepper stepperRotador(MOTOR_ROTADOR_STEP, MOTOR_ROTADOR_DIRECTION, MOTOR_ROTADOR_MAX_SPEED, MOTOR_ROTADOR_ACCELERATION, MOTOR_ROTADOR_STOPPING_MAX_SPEED);

MyServo servoElevacionBrazo(SERVO_ELEVACION_BRAZO_PIN, SERVO_ELEVACION_BRAZO_MIN_ROTATION, SERVO_ELEVACION_BRAZO_MAX_ROTATION,
                            STANDBY_ELEVACION_BRAZO_POSITION, SERVO_ELEVACION_BRAZO_MOVEMENT_INTERVAL);

MyServo servoElevacionMano(SERVO_ELEVACION_MANO_PIN, SERVO_ELEVACION_MANO_MIN_ROTATION, SERVO_ELEVACION_MANO_MAX_ROTATION,
                           STANDBY_ELEVACION_MANO_POSITION, SERVO_ELEVACION_MANO_MOVEMENT_INTERVAL);

MyServoPair servosTenazas(SERVO_TENAZAS_A_PIN, SERVO_TENAZAS_A_MIN_ROTATION, SERVO_TENAZAS_A_MAX_ROTATION,
                          SERVO_TENAZAS_B_PIN, SERVO_TENAZAS_B_MIN_ROTATION, SERVO_TENAZAS_B_MAX_ROTATION,
                          STANDBY_TENAZAS_POSITION, SERVO_TENAZAS_MOVEMENT_INTERVAL);

Motor* motors[] = { &stepperBase, &stepperRotador, &servoElevacionBrazo, &servoElevacionMano, &servosTenazas };
MotorsContainer motorsContainer(motors, 5);

/* *****************************************************************************
 *                             LIMITES DE CARRERA                              *
 * *****************************************************************************/

DigitalInput limitASoftStopBase(MOTOR_BASE_LIMIT_A_SOFT_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitAHardStopBase(MOTOR_BASE_LIMIT_A_HARD_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBSoftStopBase(MOTOR_BASE_LIMIT_B_SOFT_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBHardStopBase(MOTOR_BASE_LIMIT_B_HARD_STOP, BUTTON_INTERRUPTS_COOLDOWN);

DigitalInput limitASoftStopRotador(MOTOR_ROTADOR_LIMIT_A_SOFT_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitAHardStopRotador(MOTOR_ROTADOR_LIMIT_A_HARD_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBSoftStopRotador(MOTOR_ROTADOR_LIMIT_B_SOFT_STOP, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBHardStopRotador(MOTOR_ROTADOR_LIMIT_B_HARD_STOP, BUTTON_INTERRUPTS_COOLDOWN);

/* *****************************************************************************
 *                                    ACTIONS                                  *
 * *****************************************************************************/

int standbyPositions[] = {STANDBY_BASE_POSITION, STANDBY_ROTADOR_POSITION,
                          STANDBY_ELEVACION_BRAZO_POSITION, STANDBY_ELEVACION_MANO_POSITION,
                          STANDBY_TENAZAS_POSITION };
StandbyAction standbyAction(STANDBY_PIN, standbyPositions, 5);

int homePositions[] = {HOME_BASE_POSITION, HOME_ROTADOR_POSITION,
                       HOME_ELEVACION_BRAZO_POSITION, HOME_ELEVACION_MANO_POSITION,
                       HOME_TENAZAS_POSITION };
GoToAction homeAction(homePositions, 5);
GoToAction customPositionAction(homePositions, 5);

BlockAction blockAction;

/* *****************************************************************************
 *                                     SETUP                                   *
 * *****************************************************************************/
void initButtons() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i]->setup();
  }
  joystick.setup();
}

void initSensors() {
  limitASoftStopBase.setup();
  limitAHardStopBase.setup();
  limitBSoftStopBase.setup();
  limitBHardStopBase.setup();

  limitASoftStopRotador.setup();
  limitAHardStopRotador.setup();
  limitBSoftStopRotador.setup();
  limitBHardStopRotador.setup();
}

void addLimitSensorsToMotor(MyStepper* stepper, DigitalInput* limitASoftStop, DigitalInput* limitAHardStop, DigitalInput* limitBSoftStop, DigitalInput* limitBHardStop) {
  stepper->addLimitSensors(limitASoftStop, limitAHardStop, limitBSoftStop, limitBHardStop);
  limitASoftStop->subscribe(stepper);
  limitAHardStop->subscribe(stepper);
  limitBSoftStop->subscribe(stepper);
  limitBHardStop->subscribe(stepper);
}

void addLimitSensors() {
  addLimitSensorsToMotor(&stepperBase, &limitASoftStopBase, &limitAHardStopBase, &limitBSoftStopBase, &limitBHardStopBase);
  addLimitSensorsToMotor(&stepperRotador, &limitASoftStopRotador, &limitAHardStopRotador, &limitBSoftStopRotador, &limitBHardStopRotador);
}

void initMotors() {
  motorsContainer.setup();
  //addLimitSensors();
  joystick.subscribe(&motorsContainer);
}

void initActions() {
  up.subscribe(&customPositionAction);
  customPositionAction.setContainer(&motorsContainer);

  right.subscribe(&standbyAction);
  standbyAction.setup();
  standbyAction.setContainer(&motorsContainer);

  down.subscribe(&homeAction);
  homeAction.setContainer(&motorsContainer);

  left.subscribe(&blockAction);
  blockAction.setContainer(&motorsContainer);
}

void setup() {
  initButtons();
  //initSensors();
  initMotors();
  //initActions();
  Serial.begin(9600);
}

/* *****************************************************************************
 *                                  PROGRAMA                                   *
 * *****************************************************************************/

volatile bool statedChanged = false;

void updateInputs() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i]->update();
  }
  joystick.update();
}

void updateActions() {
  blockAction.update();
  customPositionAction.update();
  homeAction.update();
  standbyAction.update();
}

void loop() {
  updateInputs();
  motorsContainer.writeWithJoystick(joystick);
  //updateActions();
  motorsContainer.update();
}
