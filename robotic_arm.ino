#include <Servo.h>

/* ***************************************************************************************
 *                                      PINES BOTONERA                                   *
 * ***************************************************************************************/
int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int analog_button = 8;
int x_axis = A0;
int y_axis = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, analog_button};
int buttons_quantity = 7;

/* ***************************************************************************************
 *                                     MAPEO A FUNCIONES                                 *
 * ***************************************************************************************/
const int boton_pinza = select_button;
const int boton_palito = down_button;
const int boton_cambios = analog_button;
const int boton_grabarHacer = left_button;
const int boton_preseteado = start_button;
const int boton_standby = right_button;
const int boton_giro[] = {x_axis, y_axis};

/* ***************************************************************************************
 *                                         MOTORES                                       *
 * ***************************************************************************************/
const int servo_base_pin = 3;
const int servo_tronco_pin = 6;
const int servo_trompa_pin = 5;
const int servo_pinza_pin = 11;

Servo servo_base;
Servo servo_tronco;
Servo servo_trompa;
Servo servo_pinza;

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i; i < buttons_quantity; i++) {
   pinMode(buttons[i], INPUT_PULLUP);
  }
}

void attach_servos() {
  servo_base.attach(servo_base_pin);
  servo_tronco.attach(servo_tronco_pin);
  servo_trompa.attach(servo_trompa_pin);
  servo_pinza.attach(servo_pinza_pin);
}

void setup() {
  init_buttons();
  attach_servos();
  Serial.begin(9600);
}

/* ***************************************************************************************
 *                                       PROGRAMA                                        *
 * ***************************************************************************************/

void printButton(char* buttonName, int buttonId) {
  Serial.print(buttonName),Serial.print(" = "),Serial.print(digitalRead(buttonId)),Serial.print("\t");
}

void printJoystick(int xAxisId, int yAxisId) {
  Serial.print("X = "),Serial.print(map(analogRead(xAxisId), 0, 1023, -1, 1));Serial.print("\t");
  Serial.print("Y = "),Serial.print(map(analogRead(yAxisId), 0, 1023, -1, 1));Serial.print("\n");
}

void updateServo(int axis_id, Servo* servo) {
  int val = analogRead(axis_id);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo->write(val);
}

void loop() {
  printButton("UP", up_button);
  printButton("DOWN", down_button);
  printButton("LEFT", left_button);
  printButton("RIGHT", right_button);
  printButton("START", start_button);
  printButton("SELECT", select_button);
  printButton("ANALOG", analog_button);
  printButton("X", start_button);
  printJoystick(x_axis, y_axis);
  updateServo(x_axis, &servo_base);
  updateServo(y_axis, &servo_tronco);
  
  delay(100);
}


