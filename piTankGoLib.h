
#ifndef _PITANKGOLIB_H_
#define _PITANKGOLIB_H_

#include <stdio.h>

#include "fsm.h"
#include "tmr.h"

//#define CLK_MS 10

// ATENCION: Valores a modificar por el alumno
// INTERVALO DE GUARDA ANTI-REBOTES
//#define	DEBOUNCE_TIME	0
// DURACION DISPARO IR
#define SHOOTING_PERIOD 0

// CLAVES PARA MUTEX
// Claves únicas de cada flag
// Permiten la exclusión mutua entre las hebras del programa
// Estas son, la hebra principal que se ejecuta en el main de piTankGo y las hebras craedas por la fsm
// Garantizan la consistencia de los estados
#define	SYSTEM_FLAGS_KEY	1
#define	PLAYER_FLAGS_KEY	2
#define	STD_IO_BUFFER_KEY	3

// Distribucion de pines GPIO empleada para el teclado
// ATENCION: Valores a modificar por el alumno
#define	TECLADO_ROW_1	0
#define	TECLADO_ROW_2	0
#define	TECLADO_ROW_3	0
#define	TECLADO_ROW_4	0

#define	TECLADO_COL_1	0
#define	TECLADO_COL_2	0
#define	TECLADO_COL_3	0
#define	TECLADO_COL_4	0

//#define JOY_PIN_UP	0
//#define JOY_PIN_DOWN	0
//#define JOY_PIN_LEFT	0
//#define JOY_PIN_RIGHT	0
//#define JOY_PIN_CENTER 0

// Distribucion de pines GPIO empleada para el enlace IR
// ATENCION: Valores a modificar por el alumno
#define	IR_TX_PIN		0
#define	IR_RX_PIN		0

// Distribucion de pines GPIO empleada para la reproducción de efectos
// ATENCION: Valores a modificar por el alumno
#define PLAYER_PWM_PIN 	0

// Distribucion de pines GPIO empleada para el control de los servos
// ATENCION: Valores a modificar por el alumno
#define	SERVO_VERTICAL_PIN		0
#define	SERVO_HORIZONTAL_PIN	0

// FLAGS FSM CONTROL DE JUEGO Y TORRETA
// ATENCION: Valores a modificar por el alumno
#define FLAG_SYSTEM_START 		0x01
#define FLAG_JOYSTICK_UP 		0x02
#define FLAG_JOYSTICK_DOWN 		0x04
#define FLAG_JOYSTICK_LEFT		0x08
#define FLAG_JOYSTICK_RIGHT		0x10
#define FLAG_TRIGGER_BUTTON		0x20
#define FLAG_SHOOT_TIMEOUT		0x40
#define FLAG_TARGET_DONE		0x80
#define FLAG_SYSTEM_END			0x100

// FLAGS FSM REPRODUCCION DE EFECTOS DE SONIDO
// ATENCION: Valores a modificar por el alumno
#define FLAG_START_DISPARO 		0x01
#define FLAG_START_IMPACTO 		0x02
#define FLAG_PLAYER_STOP 		0x04
#define FLAG_PLAYER_END			0x08
#define FLAG_NOTA_TIMEOUT		0x10

enum interruption_sources {
	TARGET_ISR,
	TECLADO_FILA_1,
	TECLADO_FILA_2,
	TECLADO_FILA_3,
	TECLADO_FILA_4,
	//JOYSTICK_UP_ISR,
	//JOYSTICK_DOWN_ISR,
	//JOYSTICK_LEFT_ISR,
	//JOYSTICK_RIGHT_ISR,
	//JOYSTICK_CENTER_ISR
};

extern int flags_system;
extern int flags_player;

extern int frecuenciaDespacito[];
extern int tiempoDespacito[];
extern int frecuenciaGOT[];
extern int tiempoGOT[];
extern int frecuenciaTetris[];
extern int tiempoTetris[];
extern int frecuenciaStarwars[];
extern int tiempoStarwars[];

extern int frecuenciasDisparo[];
extern int tiemposDisparo[];
extern int frecuenciasImpacto[];
extern int tiemposImpacto[];

#endif /* _PITANKGOLIB_H_ */
