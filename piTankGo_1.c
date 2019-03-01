
#include "piTankGo_1.h"
#include <softTone.h>

int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};

int frecuenciasDisparo[16] = {2500,2400,2300,2200,2100,2000,1900,1800,1700,1600,1500,1400,1300,1200,1100,1000};
int tiemposDisparo[16] = {75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75};
int frecuenciasImpacto[32] = {97,109,79,121,80,127,123,75,119,96,71,101,98,113,92,70,114,75,86,103,126,118,128,77,114,119,72};
int tiemposImpacto[32] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

int flags_juego = 0;
int flags_player = 0;

static TipoTeclado teclado;
static int flags = 0;
int debounceTime[NUM_ROWS] = {0,0,0,0}; // Timeout to avoid bouncing after pin event

char tecladoTL04[4][4] = {
	{'1', '2', '3', 'C'},
	{'4', '5', '6', 'D'},
	{'7', '8', '9', 'E'},
	{'A', '0', 'B', 'F'}
};



//------------------------------------------------------
// FUNCIONES DE CONFIGURACION/INICIALIZACION
//------------------------------------------------------

// int ConfiguracionSistema (TipoSistema *p_sistema): procedimiento de configuracion del sistema.
// RealizarÃ¡, entra otras, todas las operaciones necesarias para:
// configurar el uso de posibles librerÃ­as (e.g. Wiring Pi),
// configurar las interrupciones externas asociadas a los pines GPIO,
// configurar las interrupciones periÃ³dicas y sus correspondientes temporizadores,
// crear, si fuese necesario, los threads adicionales que pueda requerir el sistema

int ConfiguraSistema (TipoSistema *p_sistema) {
	int result = 0;

	piLock (STD_IO_BUFFER_KEY);

	wiringPiSetupGpio();
	pinMode (23, OUTPUT); //declaro pin 23 como salida
	//Hace falta algo mÃ¡s? Las entradas estan en el teclado del ordenador

	piUnlock (STD_IO_BUFFER_KEY);

	softToneCreate(23);

	// Crear timer
	
	//tmr_t* tmr_new (notify_func_t isr);
	// tmr_t* tmr_new (timer_player_duracion_nota_actual_isr);
	// p_sistema -> p_player.tmr = tmr_new;
		
	p_sistema->player.myTmr = tmr_new(timer_player_duracion_nota_actual_isr);

	return result;
}

// int InicializaSistema (TipoSistema *p_sistema): procedimiento de inicializacion del sistema.
// RealizarÃ¡, entra otras, todas las operaciones necesarias para:
// la inicializacion de los diferentes elementos de los que consta nuestro sistema,
// la torreta, los efectos, etc.
// igualmente arrancarÃ¡ el thread de exploraciÃ³n del teclado del PC

int InicializaSistema (TipoSistema *p_sistema) {
	int result = 0;

	char *miEfectoDisparo = "disparo";
	char *miEfectoImpacto = "impacto";


	//Incializamos el efecto disparo
	InicializaEfecto(&(p_sistema->player.efecto_disparo),miEfectoDisparo,frecuenciasDisparo,tiemposDisparo,16);
	InicializaEfecto(&(p_sistema->player.efecto_impacto),miEfectoImpacto,frecuenciasImpacto,tiemposImpacto,32);

	//p_sistema->player.p_efecto = &(p_sistema->player.efecto_disparo);

	//InicializaPlayer(&(p_sistema->player));

	// Lanzamos thread para exploracion del teclado convencional del PC
	//result = piThreadCreate (thread_explora_teclado_PC);

	if (result != 0) {
		printf ("Thread didn't start!!!\n");
		return -1;
	}




	return result;
}

//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------

/*

PI_THREAD (thread_explora_teclado_PC) {
	int teclaPulsada;

	while(1) {
		delay(10); // Wiring Pi function: pauses program execution for at least 10 ms

		piLock (STD_IO_BUFFER_KEY);

		if(kbhit()) {
			teclaPulsada = kbread();

			switch(teclaPulsada) {
				case 'j' :
					piLock (PLAYER_FLAGS_KEY);
					flags_player |= FLAG_NOTA_TIMEOUT;
					piUnlock (PLAYER_FLAGS_KEY);

					printf("Tecla J pulsada!\n");
					fflush(stdout);
					break;

				case 't':

					piLock (PLAYER_FLAGS_KEY);
					flags_player |= FLAG_PLAYER_STOP;
					piUnlock (PLAYER_FLAGS_KEY);

					printf("Tecla T pulsada!\n");
					fflush(stdout);
					break;

				case 's':  //tecla de disparo

					piLock (PLAYER_FLAGS_KEY);
					flags_player |= FLAG_START_DISPARO;

					piUnlock (PLAYER_FLAGS_KEY);

					printf("Tecla S pulsada!\n");
					fflush(stdout);
					break;

				case 'm':  //tecla de disparo

					piLock (PLAYER_FLAGS_KEY);
					flags_player |= FLAG_START_IMPACTO;

					piUnlock (PLAYER_FLAGS_KEY);

					printf("Tecla M pulsada!\n");
					fflush(stdout);
					break;


				case 'q':
					exit(0);
					break;

				default:
					printf("INVALID KEY!!!\n");
					break;
			}
		}

		piUnlock (STD_IO_BUFFER_KEY);
	}
}

*/

// Codigo Teclado_Tl04.c

int CompruebaColumnTimeout (fsm_t* this) {
	int result = 0;
	piLock (FLAG_KEY);
	result = (flags & FLAG_TMR_TIMEOUT);
	piUnlock (FLAG_KEY);
	return result;
}

static void row_1_isr (void) {
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTime[ROW_1]) {
		debounceTime[ROW_1] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (FLAG_KEY);

	teclado.teclaPulsada.row = ROW_1;
	teclado.teclaPulsada.col = teclado.columna_actual;

	flags |= FLAG_KEY_PRESSED;

	piUnlock (FLAG_KEY);

	debounceTime[ROW_1] = millis () + DEBOUNCE_TIME ;
}

static void row_2_isr (void) {
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTime[ROW_2]) {
		debounceTime[ROW_2] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (FLAG_KEY);

	teclado.teclaPulsada.row = ROW_2;
	teclado.teclaPulsada.col = teclado.columna_actual;

	flags |= FLAG_KEY_PRESSED;

	piUnlock (FLAG_KEY);

	debounceTime[ROW_2] = millis () + DEBOUNCE_TIME ;
}

static void row_3_isr (void) {
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTime[ROW_3]) {
		debounceTime[ROW_3] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (FLAG_KEY);

	teclado.teclaPulsada.row = ROW_3;
	teclado.teclaPulsada.col = teclado.columna_actual;

	flags |= FLAG_KEY_PRESSED;

	piUnlock (FLAG_KEY);

	debounceTime[ROW_3] = millis () + DEBOUNCE_TIME ;
}

static void row_4_isr (void) {
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTime[ROW_4]) {
		debounceTime[ROW_4] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (FLAG_KEY);

	teclado.teclaPulsada.row = ROW_4;
	teclado.teclaPulsada.col = teclado.columna_actual;

	flags |= FLAG_KEY_PRESSED;

	piUnlock (FLAG_KEY);

	debounceTime[ROW_4] = millis () + DEBOUNCE_TIME ;
}

static void col_1 (fsm_t* this) {
	TipoTeclado *p_teclado;
	p_teclado = (TipoTeclado*)(this->user_data);

	piLock (FLAG_KEY);

	digitalWrite (GPIO_COL_4, LOW);
	digitalWrite (GPIO_COL_1, HIGH);
	digitalWrite (GPIO_COL_2, LOW);
	digitalWrite (GPIO_COL_3, LOW);

	flags &= (~FLAG_TMR_TIMEOUT);

	p_teclado->columna_actual = COL_1;

	piUnlock (FLAG_KEY);

	tmr_startms((tmr_t*)(p_teclado->tmr_duracion_columna), COL_REFRESH_TIME);
}

static void col_2 (fsm_t* this) {
	TipoTeclado *p_teclado;
	p_teclado = (TipoTeclado*)(this->user_data);

	piLock (FLAG_KEY);

	digitalWrite (GPIO_COL_1, LOW);
	digitalWrite (GPIO_COL_2, HIGH);
	digitalWrite (GPIO_COL_3, LOW);
	digitalWrite (GPIO_COL_4, LOW);

	flags &= (~FLAG_TMR_TIMEOUT);

	p_teclado->columna_actual = COL_2;

	piUnlock (FLAG_KEY);

	tmr_startms((tmr_t*)(p_teclado->tmr_duracion_columna), COL_REFRESH_TIME);
}

static void col_3 (fsm_t* this) {
	TipoTeclado *p_teclado;
	p_teclado = (TipoTeclado*)(this->user_data);

	piLock (FLAG_KEY);

	digitalWrite (GPIO_COL_2, LOW);
	digitalWrite (GPIO_COL_3, HIGH);
	digitalWrite (GPIO_COL_4, LOW);
	digitalWrite (GPIO_COL_1, LOW);

	flags &= (~FLAG_TMR_TIMEOUT);

	p_teclado->columna_actual = COL_3;

	piUnlock (FLAG_KEY);

	tmr_startms((tmr_t*)(p_teclado->tmr_duracion_columna), COL_REFRESH_TIME);
}

static void col_4 (fsm_t* this) {
	TipoTeclado *p_teclado;
	p_teclado = (TipoTeclado*)(this->user_data);

	piLock (FLAG_KEY);

	digitalWrite (GPIO_COL_3, LOW);
	digitalWrite (GPIO_COL_4, HIGH);
	digitalWrite (GPIO_COL_1, LOW);
	digitalWrite (GPIO_COL_2, LOW);

	flags &= (~FLAG_TMR_TIMEOUT);

	p_teclado->columna_actual = COL_4;

	piUnlock (FLAG_KEY);

	tmr_startms((tmr_t*)(p_teclado->tmr_duracion_columna), COL_REFRESH_TIME);
}

static int key_pressed (fsm_t* this) {
	int result = 0;

	piLock (FLAG_KEY);
	result = (flags & FLAG_KEY_PRESSED);
	piUnlock (FLAG_KEY);

	return result;
}

static void process_key (fsm_t* this) {
	TipoTeclado *p_teclado;
	p_teclado = (TipoTeclado*)(this->user_data);

	piLock (FLAG_KEY);

	flags &= (~FLAG_KEY_PRESSED);

	switch(p_teclado->teclaPulsada.col){
		case COL_1:
		case COL_2:
		case COL_3:
		case COL_4:
			printf("\nKeypress \"%c\"...\n",
					tecladoTL04[p_teclado->teclaPulsada.row][p_teclado->teclaPulsada.col]);
			fflush(stdout);

			piLock (PLAYER_FLAGS_KEY);
			flags_juego |= FLAG_SYSTEM_START;
			piUnlock (PLAYER_FLAGS_KEY);

			// Si la tecla es la 8 entonces sonará el disparo.
			if ((p_teclado->teclaPulsada.row == 2) & (p_teclado->teclaPulsada.col == 1)) {
				printf("\n8 pulsado \"%c\"...\n",
					tecladoTL04[p_teclado->teclaPulsada.row][p_teclado->teclaPulsada.col]);
				fflush(stdout);

				piLock (PLAYER_FLAGS_KEY);
				flags_juego |= FLAG_START_DISPARO;
				piUnlock (PLAYER_FLAGS_KEY);

			}

			// Si la tecla es la 7 entonces se moverá hacia la izquierda.
			if ((p_teclado->teclaPulsada.row == 2) & (p_teclado->teclaPulsada.col == 0)) {
				printf("Izquierda");
				fflush(stdout);

				piLock (PLAYER_FLAGS_KEY);
				flags_juego |= FLAG_JOYSTICK_LEFT;
				piUnlock (PLAYER_FLAGS_KEY);

			}

			// Si la tecla es la 5 entonces se moverá hacia arriba.
			if ((p_teclado->teclaPulsada.row == 1) & (p_teclado->teclaPulsada.col == 1)) {
				printf("arriba");
				fflush(stdout);

				piLock (PLAYER_FLAGS_KEY);
				flags_juego |= FLAG_JOYSTICK_UP;
				piUnlock (PLAYER_FLAGS_KEY);
			}

			// Si la tecla es la 9 entonces se moverá hacia la derecha.
			if ((p_teclado->teclaPulsada.row == 2) & (p_teclado->teclaPulsada.col == 2)) {
				printf("derecha");
				fflush(stdout);

				piLock (PLAYER_FLAGS_KEY);
				flags_juego |= FLAG_JOYSTICK_RIGHT;
				piUnlock (PLAYER_FLAGS_KEY);
			}

			// Si la tecla es la 0 entonces se moverá hacia abajo.
			if ((p_teclado->teclaPulsada.row == 3) & (p_teclado->teclaPulsada.col == 1)) {
				printf("abajo");
				fflush(stdout);

				piLock (PLAYER_FLAGS_KEY);
				flags_juego |= FLAG_JOYSTICK_DOWN;
				piUnlock (PLAYER_FLAGS_KEY);
			}


			break;

		default:
			printf("\nERROR!!!! invalid number of column (%d)!!!\n", p_teclado->teclaPulsada.col);
			fflush(stdout);

			p_teclado->teclaPulsada.row = -1;
			p_teclado->teclaPulsada.col = -1;

			break;
	}

	piUnlock (FLAG_KEY);

}

// wait until next_activation (absolute time)
void delay_until (unsigned int next) {
	unsigned int now = millis();
	if (next > now) {
		delay (next - now);
	}
}

static void timer_duracion_columna_isr (union sigval value) {
	piLock (FLAG_KEY);
	flags |= FLAG_TMR_TIMEOUT;
	piUnlock (FLAG_KEY);
}

int initialize(TipoTeclado *p_teclado) {


	// Comenzamos excitacion por primera columna
	p_teclado->columna_actual = COL_1;

	// Inicialmente no hay tecla pulsada
	p_teclado->teclaPulsada.col = -1;
	p_teclado->teclaPulsada.row = -1;

	pinMode (GPIO_ROW_1, INPUT);
	pullUpDnControl(GPIO_ROW_1, PUD_DOWN);
	wiringPiISR (GPIO_ROW_1, INT_EDGE_RISING, row_1_isr);

	pinMode (GPIO_ROW_2, INPUT);
	pullUpDnControl(GPIO_ROW_2, PUD_DOWN);
	wiringPiISR (GPIO_ROW_2, INT_EDGE_RISING, row_2_isr);

	pinMode (GPIO_ROW_3, INPUT);
	pullUpDnControl(GPIO_ROW_3, PUD_DOWN);
	wiringPiISR (GPIO_ROW_3, INT_EDGE_RISING, row_3_isr);

	pinMode (GPIO_ROW_4, INPUT);
	pullUpDnControl(GPIO_ROW_4, PUD_DOWN);
	wiringPiISR (GPIO_ROW_4, INT_EDGE_RISING, row_4_isr);

	pinMode (GPIO_COL_1, OUTPUT);
	digitalWrite (GPIO_COL_1, HIGH);

	pinMode (GPIO_COL_2, OUTPUT);
	digitalWrite (GPIO_COL_2, LOW);

	pinMode (GPIO_COL_3, OUTPUT);
	digitalWrite (GPIO_COL_3, LOW);

	pinMode (GPIO_COL_4, OUTPUT);
	digitalWrite (GPIO_COL_4, LOW);

	p_teclado->tmr_duracion_columna = tmr_new (timer_duracion_columna_isr);
	tmr_startms((tmr_t*)(p_teclado->tmr_duracion_columna), COL_REFRESH_TIME);

	printf("\nSystem init complete! keypad ready to process the code!!!\n");
	fflush(stdout);

	return 0;
}

// Fin codigo



int main ()
{
	TipoSistema sistema;
	unsigned int next;

	// Configuracion e inicializacion del sistema
	ConfiguraSistema (&sistema);

	InicializaSistema (&sistema);

	fsm_trans_t reproductor[] = {
		{ WAIT_START, CompruebaStartDisparo, WAIT_NEXT, InicializaPlayDisparo },
		{ WAIT_START, CompruebaStartImpacto, WAIT_NEXT, InicializaPlayImpacto },
		{ WAIT_NEXT, CompruebaStartImpacto, WAIT_NEXT, InicializaPlayImpacto },
		{ WAIT_NEXT, CompruebaNotaTimeout, WAIT_END, ActualizaPlayer },
		{ WAIT_END, CompruebaFinalEfecto, WAIT_START, FinalEfecto },
		{ WAIT_END, CompruebaNuevaNota, WAIT_NEXT, ComienzaNuevaNota},
		{-1, NULL, -1, NULL },
	};


	fsm_trans_t columns[] = {
		{ KEY_COL_1, CompruebaColumnTimeout, KEY_COL_2, col_2 },
		{ KEY_COL_2, CompruebaColumnTimeout, KEY_COL_3, col_3 },
		{ KEY_COL_3, CompruebaColumnTimeout, KEY_COL_4, col_4 },
		{ KEY_COL_4, CompruebaColumnTimeout, KEY_COL_1, col_1 },
		{-1, NULL, -1, NULL },
	};

	fsm_trans_t keypad[] = {
		{ KEY_WAITING, key_pressed, KEY_WAITING, process_key},
		{-1, NULL, -1, NULL },
	};


	fsm_trans_t juego[] = {
			{ WAIT_START, CompruebaComienzo, WAIT_MOVE, ComienzaSistema },
			{ WAIT_MOVE, CompruebaJoystickUp, JOYSTICK_UP, MueveTorretaArriba },
			{ JOYSTICK_UP, Devuelve1, WAIT_MOVE, NULL },
			{ WAIT_MOVE, CompruebaJoystickDown, JOYSTICK_DOWN, MueveTorretaAbajo },
			{ JOYSTICK_DOWN, Devuelve1, WAIT_MOVE, NULL },
			{ WAIT_MOVE, CompruebaJoystickRight, JOYSTICK_RIGHT, MueveTorretaDerecha },
			{ JOYSTICK_RIGHT, Devuelve1, WAIT_MOVE, NULL },
			{ WAIT_MOVE, CompruebaJoystickLeft, JOYSTICK_LEFT, MueveTorretaIzquierda },
			{ JOYSTICK_LEFT, Devuelve1, WAIT_MOVE, NULL },
			{ WAIT_MOVE, CompruebaTriggerButton, TRIGGER_BUTTON, DisparoIR },
			{ TRIGGER_BUTTON, CompruebaImpacto, WAIT_MOVE, ImpactoDetectado },
			{ TRIGGER_BUTTON, CompruebaTimeoutDisparo, WAIT_MOVE, FinalDisparoIR },
			{ WAIT_MOVE, CompruebaFinalJuego, WAIT_END, FinalizaJuego },
			{-1, NULL, -1, NULL },
		};



	initialize(&teclado);

	fsm_t* player_fsm = fsm_new (WAIT_START, reproductor, &(sistema.player));

	fsm_t* columns_fsm = fsm_new (KEY_COL_1, columns, &teclado);
	fsm_t* keypad_fsm = fsm_new (KEY_WAITING, keypad, &teclado);

	// Crear la máquina de estados
	fsm_t* juego_fsm = fsm_new (WAIT_START, juego, NULL);

	// A completar por el alumno...
	// ...

	next = millis();
	while (1) {
		fsm_fire (player_fsm);

		fsm_fire (columns_fsm);
		fsm_fire (keypad_fsm);
		fsm_fire (juego_fsm);

		// A completar por el alumno...
		// ...

		next += CLK_MS;
		delay_until (next);
	}

	return 0;
}
