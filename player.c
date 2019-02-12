
#include "player.h"

//------------------------------------------------------
// PROCEDIMIENTOS DE INICIALIZACION DE LOS OBJETOS ESPECIFICOS
//------------------------------------------------------

//------------------------------------------------------
// void InicializaEfecto (TipoEfecto *p_efecto)
//
// Descripcion: inicializa los parametros del objeto efecto.
// Ejemplo de uso:
//
// ...
//
// TipoEfecto efecto_demo;
//
// if ( InicializaEfecto (&efecto_demo, "DISPARO", frecuenciasDisparo, tiemposDisparo, 16) < 0 ) {
// 		printf("\n[ERROR!!!][InicializaEfecto]\n");
// 		fflush(stdout);
// 		}
//
// ...
//
//------------------------------------------------------
int InicializaEfecto (TipoEfecto *p_efecto, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {
	// A completar por el alumno...
	// ...

	return p_efecto->num_notas;
}

// Procedimiento de inicializacion del objeto especifico
// Nota: parte inicialización común a InicializaPlayDisparo y InicializaPlayImpacto
void InicializaPlayer (TipoPlayer *p_player) {
	// A completar por el alumno
	// ...
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaStartDisparo (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaStartImpacto (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaNuevaNota (fsm_t* this){
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaNotaTimeout (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

int CompruebaFinalEfecto (fsm_t* this) {
	int result = 0;

	// A completar por el alumno
	// ...

	return result;
}

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

void InicializaPlayDisparo (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void InicializaPlayImpacto (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void ComienzaNuevaNota (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void ActualizaPlayer (fsm_t* this) {
	// A completar por el alumno
	// ...
}

void FinalEfecto (fsm_t* this) {
	// A completar por el alumno
	// ...
}

//------------------------------------------------------
// PROCEDIMIENTOS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------

static void timer_player_duracion_nota_actual_isr (union sigval value) {
	// A completar por el alumno...
	// ...
}
