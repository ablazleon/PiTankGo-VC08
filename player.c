
#include "player.h"
#include <string.h>
#include <softTone.h>

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
	p_player->frecuencia_nota_actual = p_player->p_efecto->frecuencias[0];
	p_player->duracion_nota_actual = p_player->p_efecto->duraciones[0];

}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaStartDisparo (fsm_t* this) {
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_START_DISPARO);
	piUnlock (PLAYER_FLAGS_KEY);


	return result;
}

int CompruebaStartImpacto (fsm_t* this) {
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_START_IMPACTO);
	piUnlock (PLAYER_FLAGS_KEY);

	return result;
}

int CompruebaNuevaNota (fsm_t* this){
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = ~(flags_player & FLAG_PLAYER_END);
	piUnlock (PLAYER_FLAGS_KEY);

	return result;


}

int CompruebaNotaTimeout (fsm_t* this) {
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_NOTA_TIMEOUT);
	piUnlock (PLAYER_FLAGS_KEY);

	return result;
}

int CompruebaFinalEfecto (fsm_t* this) {
	int result = 0;

	piLock (PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_PLAYER_END);
	piUnlock (PLAYER_FLAGS_KEY);

	return result;
}

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

void InicializaPlayDisparo (fsm_t* this) {

	TipoPlayer *p_player; // Creamos variable TipoPlayer

	// Hacemos un casting de TipoPlayer a los datos pasados en piTankGo_1.c
	// => fsm_t* player_fsm = fsm_new (WAIT_START, reproductor, &(sistema.player));

	p_player = (TipoPlayer*)(this->user_data);

	p_player->p_efecto = &(p_player->efecto_disparo);

	InicializaPlayer(p_player);

	printf("[PLAYER][ComienzaNuevaNota][Nota %d][Frecuencia %d][Duracion %d][Numero de Notas %d] \n",p_player->posicion_nota_actual+1,p_player->frecuencia_nota_actual,p_player->duracion_nota_actual, p_player->p_efecto->num_notas);

	// Se generan los sonidos
	softToneWrite(23, p_player->frecuencia_nota_actual);

	piLock (PLAYER_FLAGS_KEY);
	flags_player &= ~FLAG_START_DISPARO;
	piUnlock (PLAYER_FLAGS_KEY);

	tmr_startms(p_player->myTmr, p_player->duracion_nota_actual);

	piLock (STD_IO_BUFFER_KEY);
	printf("Inicializa Disparo\n");
	piUnlock (STD_IO_BUFFER_KEY);
}

void InicializaPlayImpacto (fsm_t* this) {

	TipoPlayer *p_player; // Creamos variable TipoPlayer

	// Hacemos un casting de TipoPlayer a los datos pasados en piTankGo_1.c
	// => fsm_t* player_fsm = fsm_new (WAIT_START, reproductor, &(sistema.player));

	p_player = (TipoPlayer*)(this->user_data);

	p_player->p_efecto = &(p_player->efecto_impacto);

	InicializaPlayer(p_player);

	printf("[PLAYER][ComienzaNuevaNota][Nota %d][Frecuencia %d][Duracion %d][Numero de Notas %d] \n",p_player->posicion_nota_actual+1,p_player->frecuencia_nota_actual,p_player->duracion_nota_actual, p_player->p_efecto->num_notas);

	// Se generan los sonidos
	softToneWrite(23, p_player->frecuencia_nota_actual);

	piLock (PLAYER_FLAGS_KEY);
	flags_player &= ~FLAG_START_IMPACTO;
	piUnlock (PLAYER_FLAGS_KEY);

	tmr_startms(p_player->myTmr, p_player->duracion_nota_actual);

	piLock (STD_IO_BUFFER_KEY);
	printf("Inicializa Impactos\n");
	piUnlock (STD_IO_BUFFER_KEY);

}

/*
 * Habiendo comprobado FLAG_PLAY_END, mostramos por pantalla cada una de las notas del array.
 */

void ComienzaNuevaNota (fsm_t* this) {

	TipoPlayer *p_player;
	p_player = (TipoPlayer*) (this->user_data);
	piLock(PLAYER_FLAGS_KEY);
	flags_player &= ~(FLAG_PLAYER_END);
	piUnlock(PLAYER_FLAGS_KEY);

	piLock(STD_IO_BUFFER_KEY);
	printf("[PLAYER][ComienzaNuevaNota][Nota %d][Frecuencia %d][Duracion %d][Numero de Notas %d] \n",p_player->posicion_nota_actual+1,p_player->frecuencia_nota_actual,p_player->duracion_nota_actual, p_player->p_efecto->num_notas);

	//Comenzamos un nuevo timer para la nueva nota.
	tmr_startms(p_player->myTmr, p_player->duracion_nota_actual);

	// Generamos una nota
	softToneWrite(23, p_player->frecuencia_nota_actual);

	piUnlock(STD_IO_BUFFER_KEY);

}
/*
 * Actualizar el valor de la nota actual.
 */

void ActualizaPlayer (fsm_t* this) {

	TipoPlayer *p_player;
	p_player = (TipoPlayer*) (this->user_data);

	//Comprobamos si la nota es la ultima o no.
	//En caso de que no: avanzamos una nota
	//En caso de que si: avisamos que la melodia ha terminado
	p_player->posicion_nota_actual++;

	if(p_player->posicion_nota_actual < p_player->p_efecto->num_notas){

		p_player->frecuencia_nota_actual=p_player->p_efecto->frecuencias[p_player->posicion_nota_actual];
		p_player->duracion_nota_actual= p_player->p_efecto->duraciones[p_player->posicion_nota_actual];

		piLock(PLAYER_FLAGS_KEY);
		flags_player &= ~(FLAG_NOTA_TIMEOUT);
		piUnlock(PLAYER_FLAGS_KEY);
	} else{
		piLock(PLAYER_FLAGS_KEY);
		flags_player |= FLAG_PLAYER_END;
		printf("Aqui %d", flags_player);
		fflush(stdout);
		piUnlock(PLAYER_FLAGS_KEY);

		piLock(STD_IO_BUFFER_KEY);

		printf("[FinalMelodia]");
		fflush(stdout);
		piUnlock(STD_IO_BUFFER_KEY);
	}
}

void FinalEfecto (fsm_t* this) {
	piLock(PLAYER_FLAGS_KEY);
	flags_player &= (FLAG_PLAYER_END);
	piUnlock(PLAYER_FLAGS_KEY);
}

//------------------------------------------------------
// PROCEDIMIENTOS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------

void timer_player_duracion_nota_actual_isr (union sigval value) {

	piLock (PLAYER_FLAGS_KEY);

	printf("Final Timer \n");
	fflush(stdout);
	flags_player |= FLAG_NOTA_TIMEOUT;
	printf("%d", flags_player);
	fflush(stdout);

	piUnlock (PLAYER_FLAGS_KEY);

}

