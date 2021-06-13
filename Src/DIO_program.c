/************************************************************************
* 
* Module      : DIO (Digital Input/Output)
*
* File Nmae   : DIO_program.c
*
* Describtion : Source File for DIO driver containing Functions Definitions and static types
*
* Author      : Hussein Mahmoud Fouad
*
* Version     : V02
*
* Date        : 3 June 2021
*
***************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"stdint.h"
#include"tm4c123gh6pm.h"

#include"DIO_config.h"
#include"DIO_interface.h"

/************************************************************************
*                       Functions Definitions
*************************************************************************/
/*
*  Describtion: Function to initialize DIO driver for one pin
*				        1. Set the RC clock of the required port to start operation
*               2. Wait until PRGPIO_R register confirms the clock
*				        3. Configure the dirction of the selected Pin
*               4. Configure if required internal pull-up for input pins
*				        5. Set DigitalEnable Register (DEN_R) for the selected Pins
*/
void DIO_init(uint8 PORT, uint8 PIN ,uint8 DIR, uint8 Pur)
{
	SET_BIT(SYSCTL_RCGCGPIO_R, PORT); /* Set the RC clock for the selected port */
	while(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,PORT)); /* Wait until PRGPIO_R register confirms the clock */
	
	
	/* Configure the dirction of the selected Pin, required internal pull-up 
	   and Set DigitalEnable Register (DEN_R) for the selected Pins */
	switch(PORT)
	{
		case PORTA: MAKE_BIT_VALUE(GPIO_PORTA_DIR_R, PIN, DIR);
				      	MAKE_BIT_VALUE(GPIO_PORTA_PUR_R, PIN, Pur);
					      SET_BIT(GPIO_PORTA_DEN_R, PIN);
					      break;
					
		case PORTB:	MAKE_BIT_VALUE(GPIO_PORTB_DIR_R, PIN, DIR);
								MAKE_BIT_VALUE(GPIO_PORTB_PUR_R, PIN, Pur);
								SET_BIT(GPIO_PORTB_DEN_R, PIN);
								break;
					
		case PORTC: MAKE_BIT_VALUE(GPIO_PORTC_DATA_R, PIN, DIR);
								MAKE_BIT_VALUE(GPIO_PORTC_PUR_R, PIN, Pur);
								SET_BIT(GPIO_PORTC_DEN_R, PIN);
								break;
					
		case PORTD: MAKE_BIT_VALUE(GPIO_PORTD_DIR_R, PIN, DIR);
								MAKE_BIT_VALUE(GPIO_PORTD_PUR_R, PIN, Pur);
								SET_BIT(GPIO_PORTD_DEN_R, PIN);
								break;
					
		case PORTE: MAKE_BIT_VALUE(GPIO_PORTE_DIR_R, PIN, DIR);
								MAKE_BIT_VALUE(GPIO_PORTE_PUR_R, PIN, Pur);
								SET_BIT(GPIO_PORTE_DEN_R, PIN);
								break;
					
		default: MAKE_BIT_VALUE(GPIO_PORTF_DIR_R, PIN, DIR);
								MAKE_BIT_VALUE(GPIO_PORTF_PUR_R, PIN, Pur);
								SET_BIT(GPIO_PORTF_DEN_R, PIN);
								break;
	}
}
