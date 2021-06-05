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




/*
*  Describtion: Function to initialize DIO driver for 8-bit Port
*				        1. Set the RC clock of the required port to start operation
*               2. Wait until PRGPIO_R register confirms the clock
*				        3. Configure the dirction of the selected Po
*               4. Configure if required internal pull-up for input pins
*				        5. Set DigitalEnable Register (DEN_R) for the selected Pins
*/
void DIO_initPortOutput(uint8 PORT)
{
	SET_BIT(SYSCTL_RCGCGPIO_R, PORT); /* Set the RC clock for the selected port */
	while(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,PORT)); /* Wait until PRGPIO_R register confirms the clock */
	
	
	/* Configure the dirction of the selected Port as output, 
	   and Set DigitalEnable Register (DEN_R) for the selected Port */
	switch(PORT)
	{
		case PORTA: GPIO_PORTA_DIR_R|=0xFF;
					GPIO_PORTA_DEN_R|=0xFF;
					break;
					
		case PORTB:	GPIO_PORTB_DIR_R|=0xFF;
					GPIO_PORTB_DEN_R|=0xFF;
					break;
					
		case PORTC: GPIO_PORTC_DIR_R|=0xFF;
					GPIO_PORTC_DEN_R|=0xFF;
					break;
					
		case PORTD: GPIO_PORTD_DIR_R|=0xFF;
					GPIO_PORTD_DEN_R|=0xFF;
					break;
					
		case PORTE: GPIO_PORTE_DIR_R|=0xFF;
					GPIO_PORTE_DEN_R|=0xFF;
					break;
					
		default: GPIO_PORTF_DIR_R|=0xFF;
					GPIO_PORTF_DEN_R|=0xFF;
					break;	
	}
}




/************************************************************************************/
/*
*  Describtion: Function to Read required Pin value
*/
uint8 DIO_ReadPin(uint8 PORT, uint8 PIN)
{
	switch(PORT){
		
		case PORTA:   return (uint8)((GPIO_PORTA_DATA_R>>PIN)&1);
					
		case PORTB:	return (uint8)((GPIO_PORTB_DATA_R>>PIN)&1);
					
		case PORTC: return (uint8)((GPIO_PORTC_DATA_R>>PIN)&1);
					
		case PORTD: return (uint8)((GPIO_PORTD_DATA_R>>PIN)&1);
					
		case PORTE: return (uint8)((GPIO_PORTE_DATA_R>>PIN)&1);
					
			default:  return ((GPIO_PORTF_DATA_R>>PIN)&1);
		
	}
}

/************************************************************************************/
/*
*  Describtion: Function to Read required Port value
*/
uint32 DIO_ReadPort(uint8 PORT)
{
	switch(PORT)
	{
		case PORTA: return GPIO_PORTA_DATA_R;
					 
		case PORTB:	return GPIO_PORTB_DATA_R;
				   
		case PORTC: return GPIO_PORTC_DATA_R;
					    
		case PORTD: return GPIO_PORTD_DATA_R;
					
		case PORTE: return GPIO_PORTE_DATA_R;
				       
		default: return GPIO_PORTF_DATA_R;
					
	}
}

/************************************************************************************/
/*
*  Describtion: Function to Read required port value
*/
void DIO_WritePort(uint8 PORT, uint32 WriteValue)
{
	switch(PORT)
	{
	  case PORTA: GPIO_PORTA_DATA_R = WriteValue;
							  break;
					
		case PORTB:	GPIO_PORTB_DATA_R = WriteValue;
								break;
					
		case PORTC: GPIO_PORTC_DATA_R = WriteValue;
								break;
					
		case PORTD: GPIO_PORTD_DATA_R = WriteValue;
								break;
					
		case PORTE: GPIO_PORTE_DATA_R = WriteValue;
								break;
					
			default: GPIO_PORTF_DATA_R = WriteValue;
								break;
					
					//default: 
					//#error "INVALIDE PORT SELECTION in DIO_ReadPort Function"
	}
}

/************************************************************************************/
/*
*  Describtion: Function to Write required Pin output
*/
void DIO_WritePin(uint8 PORT, uint8 PIN, uint8 WriteValue)
{
	switch(PORT)
	{
	  case PORTA: MAKE_BIT_VALUE(GPIO_PORTA_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTB:	MAKE_BIT_VALUE(GPIO_PORTB_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTC: MAKE_BIT_VALUE(GPIO_PORTC_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTD: MAKE_BIT_VALUE(GPIO_PORTD_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTE: MAKE_BIT_VALUE(GPIO_PORTE_DATA_R, PIN, WriteValue&1);
							  break;
					
		default: MAKE_BIT_VALUE(GPIO_PORTF_DATA_R, PIN, WriteValue);
							  break;
					
	}
}
