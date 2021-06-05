#include "PF_init.h"

void PF_init(void){
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){};
	GPIO_PORTF_CR_R =  0x1F;	// 0001 1111 control register
	GPIO_PORTF_DIR_R = 0x0E;	// 0000 1110 Direction input/output
	GPIO_PORTF_PUR_R = 0x11;	// 0001 0001 Pull up resistor
	GPIO_PORTF_DEN_R = 0x1F;	//0001 1111 Digital
}
