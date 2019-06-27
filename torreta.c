
#include "torreta.h"
#include <softPwm.h>


//------------------------------------------------------
// PROCEDIMIENTOS DE INICIALIZACION DE LOS OBJETOS ESPECIFICOS
//------------------------------------------------------

void InicializaTorreta (TipoTorreta *p_torreta) {


	p_torreta->servo_x.incremento = SERVO_INCREMENTO;
	p_torreta->servo_x.minimo 	= SERVO_MINIMO;
	p_torreta->servo_x.maximo = SERVO_MAXIMO;

	p_torreta->servo_x.inicio = SERVO_MINIMO + (SERVO_MAXIMO - SERVO_MINIMO)/2;

	p_torreta->posicion.x = p_torreta->servo_x.inicio;

		if(p_torreta->posicion.x > p_torreta->servo_x.maximo)
			p_torreta->posicion.x  = p_torreta->servo_x.maximo;

		if(p_torreta->posicion.x < p_torreta->servo_x.minimo)
			p_torreta->posicion.x  = p_torreta->servo_x.minimo;

	softPwmCreate(SERVO_PINX, p_torreta->posicion.x, SERVO_PWM_RANGE); // Internamente ya hace: piHiPri (90) ;
	softPwmWrite(SERVO_PINX, p_torreta->posicion.x);


	p_torreta->servo_y.incremento = SERVO_INCREMENTO;
	p_torreta->servo_y.minimo 	= SERVO_MINIMO;
	p_torreta->servo_y.maximo = SERVO_MAXIMO;

	p_torreta->servo_y.inicio = SERVO_MINIMO + (SERVO_MAXIMO - SERVO_MINIMO)/2;

	p_torreta->posicion.y = p_torreta->servo_y.inicio;

		if(p_torreta->posicion.y > p_torreta->servo_y.maximo)
			p_torreta->posicion.y  = p_torreta->servo_y.maximo;

		if(p_torreta->posicion.y < p_torreta->servo_y.minimo)
			p_torreta->posicion.y  = p_torreta->servo_y.minimo;

	softPwmCreate(SERVO_PINY, p_torreta->posicion.y, SERVO_PWM_RANGE); // Internamente ya hace: piHiPri (90) ;
	softPwmWrite(SERVO_PINY, p_torreta->posicion.y);
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaComienzo (fsm_t* this) {
	int result = 0;

//	printf("CompruebaComienzo\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_START);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickUp (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickUp\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_UP);
	piUnlock (SYSTEM_FLAGS_KEY);

	return result;
}

int CompruebaJoystickDown (fsm_t* fsm_player){
	int result = 0;

//	printf("CompruebaJoystickDown\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_DOWN);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickLeft (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickLeft\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_LEFT);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaJoystickRight (fsm_t* this) {
	int result = 0;

//	printf("CompruebaJoystickRight\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_JOYSTICK_RIGHT);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTimeoutDisparo (fsm_t* this) {
	int result = 0;

//	printf("CompruebaTimeoutDisparo\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_SHOOT_TIMEOUT);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaImpacto (fsm_t* this) {
	int result = 0;

//	printf("CompruebaImpacto\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_TARGET_DONE);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaTriggerButton (fsm_t* this) {
	int result = 0;

//	printf("CompruebaTriggerButton\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_TRIGGER_BUTTON);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaFinalJuego (fsm_t* this) {
	int result = 0;

//	printf("CompruebaFinalJuego\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_END);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...

	return result;
}

int Devuelve1 (fsm_t* this) {
	int result = 1;

//	printf("Devuelve1\n");
//	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	flags_juego = FLAG_SYSTEM_START;
	piUnlock (SYSTEM_FLAGS_KEY);

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

	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	flags_juego &= (~FLAG_JOYSTICK_UP);

	if(p_torreta->posicion.y + p_torreta->servo_y.incremento <= p_torreta->servo_y.maximo) {
		p_torreta->posicion.y = p_torreta->posicion.y + p_torreta->servo_y.incremento;

		softPwmWrite(SERVO_PINY, p_torreta->posicion.y);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->posicion.y);
		fflush(stdout);
	}
}

void MueveTorretaAbajo (fsm_t* this) {

	printf("MueveTorretaAbajo\n");
	fflush(stdout);

	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	flags_juego &= (~FLAG_JOYSTICK_DOWN);

	if(p_torreta->posicion.y - p_torreta->servo_y.incremento >= p_torreta->servo_y.minimo) {
		p_torreta->posicion.y = p_torreta->posicion.y - p_torreta->servo_y.incremento;

		softPwmWrite(SERVO_PINY, p_torreta->posicion.y);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->posicion.y);
		fflush(stdout);
	}
}

void MueveTorretaIzquierda (fsm_t* this) {

	printf("MueveTorretaIzquierda\n");
	fflush(stdout);

	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	flags_juego &= (~FLAG_JOYSTICK_LEFT);

	if(p_torreta->posicion.x - p_torreta->servo_x.incremento >= p_torreta->servo_x.minimo) {
		p_torreta->posicion.x = p_torreta->posicion.x - p_torreta->servo_x.incremento;

		softPwmWrite(SERVO_PINX, p_torreta->posicion.x);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->posicion.x);
		fflush(stdout);
	}
}

void MueveTorretaDerecha (fsm_t* this) {

	printf("MueveTorretaDerecha\n");
	fflush(stdout);

	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	flags_juego &= (~FLAG_JOYSTICK_RIGHT);

	if(p_torreta->posicion.x + p_torreta->servo_x.incremento <= p_torreta->servo_x.maximo) {
		p_torreta->posicion.x = p_torreta->posicion.x + p_torreta->servo_x.incremento;

		softPwmWrite(SERVO_PINX, p_torreta->posicion.x);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->posicion.x);
		fflush(stdout);
	}
}

void DisparoIR (fsm_t* this) {

	printf("DisparoIR\n");
	fflush(stdout);

	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	digitalWrite (GPIO_LIGHT, 1);


	int p = 1200;


	tmr_startms(p_torreta->myTorretaTmr, p);

	// A completar por el alumno
	// ...
}

void FinalDisparoIR (fsm_t* this) {

	printf("FinalDisparoIR\n");
	fflush(stdout);

	digitalWrite (GPIO_LIGHT, 0);

	piLock (SYSTEM_FLAGS_KEY);

	flags_juego &= ~(FLAG_SHOOT_TIMEOUT);

	piUnlock (SYSTEM_FLAGS_KEY);


	// A completar por el alumno
	// ...
}

void ImpactoDetectado (fsm_t* this) {

	printf("ImpactoDetectado\n");
	fflush(stdout);

	piLock (PLAYER_FLAGS_KEY);
	flags_player |= FLAG_START_IMPACTO;
	piUnlock (PLAYER_FLAGS_KEY);

	piLock (SYSTEM_FLAGS_KEY);
	flags_juego &= ~(FLAG_TARGET_DONE);
	flags_juego &= ~(FLAG_SHOOT_TIMEOUT);
	piUnlock (SYSTEM_FLAGS_KEY);

	// A completar por el alumno
	// ...
}

void FinalizaJuego (fsm_t* this) {

	printf("FinalizaJuego\n");
	fflush(stdout);

	// A completar por el alumno
	// ...
}


// Prototipos de procedimientos de atencion a las interrupciones

void timer_duracion_disparo_isr (union sigval value) {

	printf("Final Timer Disparo \n");
	fflush(stdout);

	piLock (SYSTEM_FLAGS_KEY);
	flags_juego |= FLAG_SHOOT_TIMEOUT;
	flags_juego &= ~(FLAG_TRIGGER_BUTTON);
	piUnlock (SYSTEM_FLAGS_KEY);

}

