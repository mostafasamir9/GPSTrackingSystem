#include "LED.h"

void LED_ON(uint16_t color){
	if(color == 0)
		GPIO_PORTF_DATA_R = 0x02;
	else if ( color == 1 )
		GPIO_PORTF_DATA_R = 0x04;
	else if ( color == 2 )
		GPIO_PORTF_DATA_R = 0x08;

}

void LED_OFF(){
	GPIO_PORTF_DATA_R = 0;
}
