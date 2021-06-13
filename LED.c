// NEW PART
/************************************************************************
* 
* Module      : LED
*
* File Nmae   : LED.h
*
* Describtion : Source file for "Portf Led Part" containing the functions of turnning on & off for LED
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 11 June 2021
*
***************************************************************************/

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
