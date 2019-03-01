
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

//	printf("CompruebaComienzo\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_START);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickUp (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickUp\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_UP);
	piUnlock (PLAYER_FLAGS_KEY);

	return result;
}

int CompruebaJoystickDown (fsm_t* fsm_player){
	int result = 0;

//	printf("CompruebaJoystickDown\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_DOWN);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickLeft (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickLeft\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_LEFT);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickRight (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickRight\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_RIGHT);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTimeoutDisparo (fsm_t* this) {
	int result = 0;

//	printf("CompruebaTimeoutDisparo\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_SHOOT_TIMEOUT);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaImpacto (fsm_t* this) {
	int result = 0;

//	printf("CompruebaImpacto\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_TARGET_DONE);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTriggerButton (fsm_t* this) {
	int result = 0;

//	printf("CompruebaTriggerButton\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_TRIGGER_BUTTON);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaFinalJuego (fsm_t* this) {
	int result = 0;

//	printf("CompruebaFinalJuego\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_END);
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int Devuelve1 (fsm_t* this) {
	int result = 1;

//	printf("Devuelve1\n");
//	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	flags_juego = FLAG_SYSTEM_START;
	piUnlock (PLAYER_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}


//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------




void ComienzaSistema (fsm_t* this) {

	printf("ComienzaSistema\n");
	fflush(stdout);


	// A completar por el alumno
	// ...
}

void MueveTorretaArriba (fsm_t* this) {

	printf("MueveTorretaArriba\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void MueveTorretaAbajo (fsm_t* this) {

	printf("MueveTorretaAbajo\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void MueveTorretaIzquierda (fsm_t* this) {

	printf("MueveTorretaIzquierda\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void MueveTorretaDerecha (fsm_t* this) {

	printf("MueveTorretaDerecha\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void DisparoIR (fsm_t* this) {

	printf("DisparoIR\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void FinalDisparoIR (fsm_t* this) {

	printf("FinalDisparoIR\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void ImpactoDetectado (fsm_t* this) {

	printf("ImpactoDetectado\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}

void FinalizaJuego (fsm_t* this) {

	printf("FinalizaJuego\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}
