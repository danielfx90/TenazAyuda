#ifndef Configuration_h
#define Configuration_h

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

 #define BUTTON_INTERRUPTS_COOLDOWN 100

/* ***************************************************************************************
 *                                     MAPEO A FUNCIONES                                 *
 * ***************************************************************************************/
#define boton_grabarHacer LEFT_BUTTON
#define boton_preseteado START_BUTTON
#define boton_standby RIGHT_BUTTON

/* ***************************************************************************************
 *                                          MOTORES                                      *
 * ***************************************************************************************/
#define MOTOR_BASE_STEP 51
#define MOTOR_BASE_DIRECTION 53
#define MOTOR_BASE_MAX_SPEED 150
#define MOTOR_BASE_ACCELERATION 250
#define MOTOR_BASE_STOPPING_MAX_SPEED 70
#define MOTOR_BASE_LIMIT_A_SOFT_STOP 27 // TO DO
#define MOTOR_BASE_LIMIT_A_HARD_STOP 29 // TO DO
#define MOTOR_BASE_LIMIT_B_SOFT_STOP 31 // TO DO
#define MOTOR_BASE_LIMIT_B_HARD_STOP 33 // TO DO

#define MOTOR_ROTADOR_STEP 47
#define MOTOR_ROTADOR_DIRECTION 49
#define MOTOR_ROTADOR_MAX_SPEED 60
#define MOTOR_ROTADOR_ACCELERATION 150
#define MOTOR_ROTADOR_STOPPING_MAX_SPEED 70
#define MOTOR_ROTADOR_LIMIT_A_SOFT_STOP 39
#define MOTOR_ROTADOR_LIMIT_A_HARD_STOP 41
#define MOTOR_ROTADOR_LIMIT_B_SOFT_STOP 43
#define MOTOR_ROTADOR_LIMIT_B_HARD_STOP 45

#define SERVO_ELEVACION_BRAZO_PIN 45
#define SERVO_ELEVACION_BRAZO_MIN_ROTATION 20
#define SERVO_ELEVACION_BRAZO_MAX_ROTATION 170

#define SERVO_ELEVACION_MANO_PIN 49
#define SERVO_ELEVACION_MANO_MIN_ROTATION 20
#define SERVO_ELEVACION_MANO_MAX_ROTATION 170

#define SERVO_TENAZAS_A_PIN 51
#define SERVO_TENAZAS_A_MIN_ROTATION 20
#define SERVO_TENAZAS_A_MAX_ROTATION 170

#define SERVO_TENAZAS_B_PIN 53
#define SERVO_TENAZAS_B_MIN_ROTATION 20
#define SERVO_TENAZAS_B_MAX_ROTATION 170

#endif
