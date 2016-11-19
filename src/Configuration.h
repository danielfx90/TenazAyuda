#ifndef Configuration_h
#define Configuration_h

#include <Arduino.h>

/* ***************************************************************************************
 *                                      PINES BOTONERA                                   *
 * ***************************************************************************************/
#define UP_BUTTON 2
#define DOWN_BUTTON 4
#define LEFT_BUTTON 5
#define RIGHT_BUTTON 3
#define START_BUTTON 6
#define SELECT_BUTTON 7
#define JOYSTICK_BUTTON 8
#define X_AXIS A0
#define Y_AXIS A1
#define BUTTONS_QUANTITY 7

/* ***************************************************************************************
 *                                    CONSTANTES BOTONES                                 *
 * ***************************************************************************************/

 #define BUTTON_INTERRUPTS_COOLDOWN 500

 /* ***************************************************************************************
  *                                         ACTIONS                                       *
  * ***************************************************************************************/

#define STANDBY_PIN 21
#define STANDBY_SIGNAL LOW
#define STANDBY_CYCLES 50000
#define STANDBY_BASE_POSITION 100
#define STANDBY_ROTADOR_POSITION 100
#define STANDBY_ELEVACION_BRAZO_POSITION 100
#define STANDBY_ELEVACION_MANO_POSITION 100
#define STANDBY_TENAZAS_POSITION 100

#define HOME_BASE_POSITION 100
#define HOME_ROTADOR_POSITION 100
#define HOME_ELEVACION_BRAZO_POSITION 100
#define HOME_ELEVACION_MANO_POSITION 100
#define HOME_TENAZAS_POSITION 100

/* ***************************************************************************************
 *                                          MOTORES                                      *
 * ***************************************************************************************/
#define MOTOR_BASE_STEP 51
#define MOTOR_BASE_DIRECTION 53
#define MOTOR_BASE_MAX_SPEED 360
#define MOTOR_BASE_ACCELERATION 900
#define MOTOR_BASE_STOPPING_MAX_SPEED 70
#define MOTOR_BASE_LIMIT_A_SOFT_STOP 37
#define MOTOR_BASE_LIMIT_A_HARD_STOP 35
#define MOTOR_BASE_LIMIT_B_SOFT_STOP 33
#define MOTOR_BASE_LIMIT_B_HARD_STOP 31

#define MOTOR_ROTADOR_STEP 47
#define MOTOR_ROTADOR_DIRECTION 49
#define MOTOR_ROTADOR_MAX_SPEED 360
#define MOTOR_ROTADOR_ACCELERATION 900
#define MOTOR_ROTADOR_STOPPING_MAX_SPEED 70
#define MOTOR_ROTADOR_LIMIT_A_SOFT_STOP 29
#define MOTOR_ROTADOR_LIMIT_A_HARD_STOP 27
#define MOTOR_ROTADOR_LIMIT_B_SOFT_STOP 25
#define MOTOR_ROTADOR_LIMIT_B_HARD_STOP 23

#define SERVO_ELEVACION_BRAZO_PIN 39
#define SERVO_ELEVACION_BRAZO_MIN_ROTATION 20
#define SERVO_ELEVACION_BRAZO_MAX_ROTATION 170
#define SERVO_ELEVACION_BRAZO_MOVEMENT_INTERVAL 100

#define SERVO_ELEVACION_MANO_PIN 43
#define SERVO_ELEVACION_MANO_MIN_ROTATION 20
#define SERVO_ELEVACION_MANO_MAX_ROTATION 170
#define SERVO_ELEVACION_MANO_MOVEMENT_INTERVAL 100

#define SERVO_TENAZAS_A_PIN 45
#define SERVO_TENAZAS_A_MIN_ROTATION 20
#define SERVO_TENAZAS_A_MAX_ROTATION 170

#define SERVO_TENAZAS_B_PIN 41
#define SERVO_TENAZAS_B_MIN_ROTATION 20
#define SERVO_TENAZAS_B_MAX_ROTATION 170

#define SERVO_TENAZAS_MOVEMENT_INTERVAL 100

#endif
