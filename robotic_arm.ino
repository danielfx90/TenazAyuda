#include <Servo.h>

bool DEBUG = true;

/* ***************************************************************************************
 *                                      PINES BOTONERA                                   *
 * ***************************************************************************************/
const int up_button = 2;
const int down_button = 4;
const int left_button = 5;
const int right_button = 3;
const int start_button = 6;
const int select_button = 7;
const int analog_button = 8;
const int x_axis = A0;
const int y_axis = A1;
const int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, analog_button};
const int buttons_quantity = 7;

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
Servo servos[] = { servo_base, servo_tronco, servo_trompa, servo_pinza };
const int servos_quantity = 4;
int current_pair_selection = 0;

/* ***************************************************************************************
 *                                         SETUP                                         *
 * ***************************************************************************************/
void init_buttons() {
  for (int i = 0; i < buttons_quantity; i++) {
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

void update_servo(int axis_id, Servo* servo) {
  int val = analogRead(axis_id);
  val = map(val, 0, 1023, -100, 100);
  int final_val = val / 10;
  servo->write(servo->read() + final_val);
}

void update_servos_pair() {
  int base_servo_index = current_pair_selection * 2;
  update_servo(x_axis, &servos[base_servo_index]);
  update_servo(y_axis, &servos[base_servo_index + 1]);
}

void read_servos_pair_selection() {
  int selection = digitalRead(boton_cambios);
  if (selection == LOW) {
    current_pair_selection = (current_pair_selection + 2) % servos_quantity;
    if (DEBUG) {
      Serial.print("Par de servos: "),Serial.print(current_pair_selection),Serial.print("\n");
    }
  }
}

void loop() {
  update_servos_pair();
  read_servos_pair_selection();
  delay(150);
}


