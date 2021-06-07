#include "PFInterruptInit.h"
#include "LED.h"
#include "tm4c123gh6pm.h"
#include "Systick.h"

void GPIOF_Handler();
void SysTick_Handler(void);


int main(){
		PFInterruptInit();
		Systick_init();
		EnableInterrupts();
		while(1);
}

uint8_t i = 0;

void GPIOF_Handler(void){
	GPIO_PORTF_ICR_R |= 0x11; // acknowledge flag
	i = (i + 1) % 3;
	LED_ON(i);
	
	Systick_wait_1s();
}

void SysTick_Handler(void)
{
		LED_OFF();
}

