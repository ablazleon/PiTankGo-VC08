
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

// Asignar al objecto p_efecto los atributos dados.

int InicializaEfecto (TipoEfecto *p_efecto, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {

	// A completar por el alumno...
	// ...
	strcpy(p_efecto->nombre,nombre);
	//p_efecto->nombre = nombre;
	int i = 0;

	for (i=0; i<num_notas; i++) {
		p_efecto->frecuencias[i] = array_frecuencias[i];
		p_efecto->duraciones[i] = array_duraciones[i];
	}

	p_efecto->num_notas = num_notas;

	return p_efecto->num_notas;
}

// Procedimiento de inicializacion del objeto especifico
// Nota: parte inicialización común a InicializaPlayDisparo y InicializaPlayImpacto
void InicializaPlayer (TipoPlayer *p_player) {
	// A completar por el alumno
	// ...
	p_player->posicion_nota_actual = 0;
	p_player->frecuencia_nota_actual;
	p_player->posicion_nota_actual;
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaStartDisparo (fsm_t* this) {
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = (flags & FLAG_TECLA_ON);
	piUnlock (PLAYER_FLAGS_KEY);


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
