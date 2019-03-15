/*
 * torreta.h
 *
 *  Created on: 21 de enero de 2019
 *      Author: FFM
 */

#ifndef _TORRETA_H_
#define _TORRETA_H_

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "piTankGoLib.h"

//#define	SERVO_PIN			13
#define	SERVO_PINX			18

// https://github.com/WiringPi/WiringPi/blob/master/wiringPi/softPwm.c
//  The PWM Frequency is derived from the "pulse time" below. Essentially,
//	the frequency is a function of the range and this pulse time.
//	The total period will be range * pulse time in µS, so a pulse time
//	of 100 and a range of 100 gives a period of 100 * 100 = 10,000 µS
//	which is a frequency of 100Hz.

// PWM SW: el SO provoca que cuanto más alta sea la frecuencia de la señal PWM de control menos estable resulta esta (i.e. cimbreo del servo)
// Interesa una frecuencia para la señal de control relativamente baja para minimizar el cimbreo
// El problema es que tampoco puede ser demasiado baja o de lo contrario el control del servo se resiente y su respuesta es peor
// (más lenta ante variaciones rápidas del ciclo de trabajo de la señal de control)
#define SERVO_PWM_RANGE		400 // 100 * 400 = 40,000 µS = 40 ms // 25 Hz

#define SERVO_INCREMENTO	1
#define SERVO_MINIMO		9
#define SERVO_MAXIMO		22

typedef struct {
	int inicio; // Valor correspondiente a la posicion inicial del servo
	int incremento; // Cuantía en que se incrementa el valor de la posicion con cada movimiento del servo
	int minimo; // Valor mínimo correspondiente a la posicion del servo
	int maximo; // Valor maximo correspondiente a la posicion del servo
} TipoServo;

typedef struct {
	int x; // Coordenada x correspondiente a la posicion del servo horizontal
	int y; // Coordenada y correspondiente a la posicion del servo vertical
} TipoPosicionTorreta;

typedef struct {
	TipoPosicionTorreta posicion;
	TipoServo servo_x;
	TipoServo servo_y;

	// A completar por el alumno (declaracion del temporizador para control duracion disparo)
	// ...
} TipoTorreta;

extern int flags_juego;

// Prototipos de procedimientos de inicializacion de los objetos especificos
void InicializaTorreta (TipoTorreta *p_torreta);

// Prototipos de funciones de entrada
int CompruebaComienzo (fsm_t* this);
int CompruebaJoystickUp (fsm_t* this);
int CompruebaJoystickDown (fsm_t* fsm_player);
int CompruebaJoystickLeft (fsm_t* this);
int CompruebaJoystickRight (fsm_t* this);
int CompruebaTimeoutDisparo (fsm_t* this);
int CompruebaImpacto (fsm_t* this);
int CompruebaTriggerButton (fsm_t* this);
int CompruebaFinalJuego (fsm_t* this);
int Devuelve1(fsm_t* this);

// Prototipos de funciones de salida
void ComienzaSistema (fsm_t* this);
void MueveTorretaArriba (fsm_t* this);
void MueveTorretaAbajo (fsm_t* this);
void MueveTorretaIzquierda (fsm_t* this);
void MueveTorretaDerecha (fsm_t* this);
void DisparoIR (fsm_t* this);
void FinalDisparoIR (fsm_t* this);
void ImpactoDetectado (fsm_t* this);
void FinalizaJuego (fsm_t* this);

// Prototipos de procedimientos de atencion a las interrupciones
//static void timer_duracion_disparo_isr (union sigval value);

#endif /* _TORRETA_H_ */
