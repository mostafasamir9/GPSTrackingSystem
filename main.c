#include "tm4c123gh6pm.h"
#include "PF_init.h"
#include "LED.h"

int main()
{
	PF_init();
	uint16_t distance = 100;
	while(1)
	{
		uint16_t x = 50;
		if ( x > distance )
			LED_ON(0);
	}
}
