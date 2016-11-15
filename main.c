#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "pll.h"
#include "uart0.h"
#include "portF.h"
#include "systick.h"

#define OFF		0x00U
#define RED		0x02U
#define BLUE	0x04U
#define GREEN	0x08U

uint32_t led;

void systick_handler(){
	GPIO_PORTF_DATA_R ^= led;
}

void main(void){
	char c;

	pll_init(); //80 MHz
	UART0_init();
	portF_init();
	systick_init(16000000);

	led = OFF;
	GPIO_PORTF_DATA_BITS_R[RED|BLUE|GREEN] = led;

	_enable_interrupts();

	while(1){
		c = UART0_InChar();
		switch (c){
			case 'r':
				led = RED;
				break;
			case 'b':
				led = BLUE;
				break;
			case 'g':
				led = GREEN;
				break;
			case 'o':
				led = OFF;
			default:
				led = led;
		}

		GPIO_PORTF_DATA_BITS_R[RED|BLUE|GREEN] = led;
		UART0_OutString("OK");
	}
}
