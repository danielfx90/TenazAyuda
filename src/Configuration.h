#ifndef Configuration_h
#define Configuration_h

#include <Arduino.h>

/* ***************************************************************************************
 *                                          PINES                                        *
 * ***************************************************************************************/

// Botonera
#define UP_BUTTON 2
#define DOWN_BUTTON 4
#define LEFT_BUTTON 5
#define RIGHT_BUTTON 3
#define START_BUTTON 6
#define SELECT_BUTTON 7
#define JOYSTICK_BUTTON 8
#define X_AXIS A0
#define Y_AXIS A1

// Acciones
#define STANDBY_HIGH_PIN 21
#define STANDBY_LOW_PIN 23

// Sensores
#define MOTOR_BASE_LIMIT_SOFT_STOP 29
#define MOTOR_BASE_LIMIT_A_HARD_STOP 43
#define MOTOR_BASE_LIMIT_B_HARD_STOP 41
#define MOTOR_ROTADOR_LIMIT_SOFT_STOP 33
#define MOTOR_ROTADOR_LIMIT_A_HARD_STOP 45
#define MOTOR_ROTADOR_LIMIT_B_HARD_STOP 31

#define PRESSURE_SENSOR_PIN 25

// Motores
#define MOTOR_BASE_STEP 47
#define MOTOR_BASE_DIRECTION 53
#define MOTOR_ROTADOR_STEP 49
#define MOTOR_ROTADOR_DIRECTION 27
#define SERVO_ELEVACION_BRAZO_PIN 35
#define SERVO_ELEVACION_MANO_PIN 51
#define SERVO_TENAZAS_A_PIN 37
#define SERVO_TENAZAS_B_PIN 39

/* ***************************************************************************************
 *                                    CONSTANTES BOTONES                                 *
 * ***************************************************************************************/

#define BUTTONS_QUANTITY 7
#define BUTTON_INTERRUPTS_COOLDOWN 500

/* ***************************************************************************************
 *                                         ACTIONS                                       *
 * ***************************************************************************************/

#define STANDBY_CYCLES 50000
#define STANDBY_BASE_POSITION -300
#define STANDBY_ROTADOR_POSITION -300
#define STANDBY_ELEVACION_BRAZO_POSITION 15
#define STANDBY_ELEVACION_MANO_POSITION 150
#define STANDBY_TENAZAS_POSITION 70

#define HOME_BASE_POSITION 100
#define HOME_ROTADOR_POSITION 100
#define HOME_ELEVACION_BRAZO_POSITION 15
#define HOME_ELEVACION_MANO_POSITION 150
#define HOME_TENAZAS_POSITION 70

/* ***************************************************************************************
 *                                          SENSORES                                     *
 * ***************************************************************************************/

#define SENSORS_QUANTITY 6

/* ***************************************************************************************
 *                                          MOTORES                                      *
 * ***************************************************************************************/

#define MOTOR_BASE_MAX_SPEED 360
#define MOTOR_BASE_ACCELERATION 900
#define MOTOR_BASE_STOPPING_MAX_SPEED 70
#define MOTOR_BASE_JOYSTICK_DIRECTION -1

#define MOTOR_ROTADOR_MAX_SPEED 700
#define MOTOR_ROTADOR_ACCELERATION 900
#define MOTOR_ROTADOR_STOPPING_MAX_SPEED 60
#define MOTOR_ROTADOR_JOYSTICK_DIRECTION 1

#define SERVO_ELEVACION_BRAZO_MIN_ROTATION 10
#define SERVO_ELEVACION_BRAZO_MAX_ROTATION 90
#define SERVO_ELEVACION_BRAZO_MOVEMENT_INTERVAL 100
#define SERVO_ELEVACION_BRAZO_JOYSTICK_DIRECTION 1

#define SERVO_ELEVACION_MANO_MIN_ROTATION 20
#define SERVO_ELEVACION_MANO_MAX_ROTATION 170
#define SERVO_ELEVACION_MANO_MOVEMENT_INTERVAL 100
#define SERVO_ELEVACION_MANO_JOYSTICK_DIRECTION 1

#define SERVO_TENAZAS_A_MIN_ROTATION 20
#define SERVO_TENAZAS_A_MAX_ROTATION 170

#define SERVO_TENAZAS_B_MIN_ROTATION 20
#define SERVO_TENAZAS_B_MAX_ROTATION 170

#define SERVO_TENAZAS_MOVEMENT_INTERVAL 100
#define SERVO_TENAZAS_JOYSTICK_DIRECTION -1

#endif
