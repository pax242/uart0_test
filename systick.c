#include <stdint.h>
#include "tm4c123gh6pm.h"

void systick_init(uint32_t period){
	// Deshabilitamos systick durante inicializacion poniendo a cero el bit ENABLE
	NVIC_ST_CTRL_R  &= ~0x01;

	// Cargamos el valor RELOAD
	NVIC_ST_RELOAD_R = period - 1;

	// Cargamos el valor actual
	NVIC_ST_CURRENT_R = 0x00;

	//Establecemos la prioridad de la interrupción
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x40000000; // Prioridad 2

	// Escribimos el modo de trabajo: Reloj interno, habilitamos interrupciones, habilitamos systick
	NVIC_ST_CTRL_R = 0x07;
}
