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

MyServo servoElevacionBrazo(SERVO_ELEVACION_BRAZO_PIN, SERVO_ELEVACION_BRAZO_MIN_ROTATION, SERVO_ELEVACION_BRAZO_MAX_ROTATION);
MyServo servoElevacionMano(SERVO_ELEVACION_MANO_PIN, SERVO_ELEVACION_MANO_MIN_ROTATION, SERVO_ELEVACION_MANO_MAX_ROTATION);

MyServoPair servosTenazas(SERVO_TENAZAS_A_PIN, SERVO_TENAZAS_A_MIN_ROTATION, SERVO_TENAZAS_A_MAX_ROTATION,
                          SERVO_TENAZAS_B_PIN, SERVO_TENAZAS_B_MIN_ROTATION, SERVO_TENAZAS_B_MAX_ROTATION);

Motor* motors[] = { &stepperBase, &stepperRotador, &servoElevacionBrazo, &servoElevacionMano, &servosTenazas };
MotorsContainer motorsContainer(motors, 5);

/* ***************************************************************************************
 *                                    LIMITES DE CARRERA                                 *
 * ***************************************************************************************/

DigitalInput limitASoftStopBase(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitAHardStopBase(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBSoftStopBase(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBHardStopBase(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);

DigitalInput limitASoftStopRotador(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitAHardStopRotador(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBSoftStopRotador(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);
DigitalInput limitBHardStopRotador(UP_BUTTON, BUTTON_INTERRUPTS_COOLDOWN);

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
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

void addSubscribers() {
  joystick.subscribe(&motorsContainer);
}

void setup() {
  initButtons();
  initSensors();
  motorsContainer.setup();
  addLimitSensors();
  addSubscribers();
  Serial.begin(9600);
}

/* ***************************************************************************************
 *                                       PROGRAMA                                        *
 * ***************************************************************************************/

volatile bool statedChanged = false;

void updateInputs() {
  for (int i = 0; i < BUTTONS_QUANTITY; i++) {
   buttons[i]->update();
  }
  joystick.update();
}

int cyclesCount = 0;

void loop() {
  // temporal
  if (cyclesCount % 100 == 0) {
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
