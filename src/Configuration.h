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

 #define BUTTON_INTERRUPTS_COOLDOWN 5

/* ***************************************************************************************
 *                                     MAPEO A FUNCIONES                                 *
 * ***************************************************************************************/
#define boton_pinza SELECT_BUTTON
#define boton_palito DOWN_BUTTON
#define boton_cambios ANALOG_BUTTON
#define boton_grabarHacer LEFT_BUTTON
#define boton_preseteado START_BUTTON
#define boton_standby RIGHT_BUTTON

/* ***************************************************************************************
 *                                    LIMITES DE CARRERA                                 *
 * ***************************************************************************************/


/* ***************************************************************************************
 *                                          MOTORES                                      *
 * ***************************************************************************************/
#define MOTOR_BASE_STEP 31
#define MOTOR_BASE_DIRECTION 33
#define MOTOR_BASE_MAX_SPEED 400
#define MOTOR_BASE_ACCELERATION 150

#define MOTOR_ROTADOR_STEP 35
#define MOTOR_ROTADOR_DIRECTION 37
#define MOTOR_ROTADOR_MAX_SPEED 400
#define MOTOR_ROTADOR_ACCELERATION 150

#define SERVO_ELEVACION_BRAZO_PIN 39
#define SERVO_ELEVACION_MANO_PIN 41

#endif
