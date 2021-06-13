#include "tm4c123gh6pm.h"
#include "DIO_interface.h"

void PFInterruptInit(void){
	
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){};
		
	GPIO_PORTF_CR_R = 0x1F;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_PUR_R = 0x10;
	GPIO_PORTF_DEN_R = 0x1F;
	GPIO_PORTF_IS_R &= ~(0x10); // interrupt sense ( Edge sensitive  not level sensitive )
	GPIO_PORTF_IBE_R  &= ~(0x10); // they're not interrupt both edges
	GPIO_PORTF_IEV_R &= ~(0x10); // failing edge causing the interrupt
	GPIO_PORTF_ICR_R |= 0x10; // clear the flag 
	GPIO_PORTF_IM_R |= 0x10; // enable Arm interrupt
	
		NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|(0x00A00000);
		NVIC_EN0_R |= 0x40000000; // enable Interrupt

}


void GPIOF_Handler(void)
{
	GPIO_PORTF_ICR_R |= 0x10; // acknowledge flag
	 DIO_WritePin(PORTF, GREEN, LOW); /* Turn the green LED off */
}

