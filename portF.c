#include <stdint.h>
#include "tm4c123gh6pm.h"

void portF_init(void){
	// PF3 digital output PF4 digital input
	SYSCTL_RCGCGPIO_R |= (0x01<<5);
	while((SYSCTL_PRGPIO_R & (0x01<<5)) == 0){};
	GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock CR register
	GPIO_PORTF_CR_R = 0x1F;
	GPIO_PORTF_AMSEL_R = 0x00; //no analog functions
	GPIO_PORTF_PCTL_R = 0x00;
	GPIO_PORTF_AFSEL_R = 0x00;
	GPIO_PORTF_DIR_R = 0x0E; //PF0 and PF4 input, PF[3:1] output
	GPIO_PORTF_PUR_R = 0x11; //Pull up resistors in PF0 and PF4
	GPIO_PORTF_DEN_R = 0x1F; //Enable PF[4:0]
}


