
#include "torreta.h"

//------------------------------------------------------
// PROCEDIMIENTOS DE INICIALIZACION DE LOS OBJETOS ESPECIFICOS
//------------------------------------------------------

void InicializaTorreta (TipoTorreta *p_torreta) {
	// A completar por el alumno...
	// ...
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaComienzo (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickUp (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickDown (fsm_t* fsm_player){
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickLeft (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickRight (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTimeoutDisparo (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaImpacto (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTriggerButton (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaFinalJuego (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

void ComienzaSistema (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void MueveTorretaArriba (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void MueveTorretaAbajo (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void MueveTorretaIzquierda (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void MueveTorretaDerecha (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void DisparoIR (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void FinalDisparoIR (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void ImpactoDetectado (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void FinalizaJuego (fsm_t* this) {
	// A completar por el alumno
	// ...
}
