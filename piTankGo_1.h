/*
 * piTankGo_1.h
 *
 *  Created on: 11 de enero de 2019
 *      Author: FFM
 */

#ifndef _PITANKGO_1_H_
#define _PITANKGO_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "kbhit.h" // Para poder detectar teclas pulsadas sin bloqueo y leer las teclas pulsadas
#include "player.h"
#include "torreta.h"

// Posibles estados de las FSMs
enum fsm_state {
	WAIT_START,
	WAIT_KEY,
	WAIT_PUSH,
	WAIT_NEXT,
	WAIT_MOVE,
	WAIT_END,
	JOYSTICK_UP,
	JOYSTICK_DOWN,
	JOYSTICK_LEFT,
	JOYSTICK_RIGHT,
	TRIGGER_BUTTON
};

typedef struct {
	TipoTorreta torreta; // Objeto para el control de la torreta
	TipoPlayer player; // Reproductor de efectos
	char teclaPulsada;  // Variable que almacena la ultima tecla pulsada
	int debug; // Variable que habilita o deshabilita la impresion de mensajes por salida estandar
} TipoSistema;

//------------------------------------------------------
// FUNCIONES DE CONFIGURACION/INICIALIZACION
//------------------------------------------------------
int ConfiguraSistema (TipoSistema *p_sistema);
int InicializaSistema (TipoSistema *p_sistema);

//------------------------------------------------------
// FUNCIONES LIGADAS A THREADS ADICIONALES
//------------------------------------------------------
PI_THREAD(thread_explora_teclado_PC);

// Codigo teclado_Tl04.h

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "fsm.h"
#include "tmr.h"

#define GPIO_COL_1 0
#define GPIO_COL_2 1
#define GPIO_COL_3 2
#define GPIO_COL_4 3

#define GPIO_ROW_1 5
#define GPIO_ROW_2 6
#define GPIO_ROW_3 12
#define GPIO_ROW_4 13

#define CLK_MS 			5
#define	DEBOUNCE_TIME	200
#define COL_REFRESH_TIME 25

#define	FLAG_KEY			0

#define FLAG_KEY_PRESSED 0x01
#define FLAG_TMR_TIMEOUT 0x02

#define NUM_COLS 4
#define NUM_ROWS 4

enum columns_values {
	COL_1,
	COL_2,
	COL_3,
	COL_4,
};

enum rows_values {
	ROW_1,
	ROW_2,
	ROW_3,
	ROW_4
};

enum column_state {
	KEY_COL_1,
	KEY_COL_2,
	KEY_COL_3,
	KEY_COL_4
};

enum keypad_state {
	KEY_WAITING
};

typedef struct {
	int col;
	int row;
} TipoTecla;

typedef struct {
	int columna_actual;
	tmr_t* tmr_duracion_columna;
	TipoTecla teclaPulsada;
} TipoTeclado;

#endif /* _PITANKGO_1_H_ */
