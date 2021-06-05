/************************************************************************
* 
* Module      : SYSTICK timer
*
* File Nmae   : SYSTICK_interface.h
*
* Describtion : Source File for "ARM SYSTICK driver" containing the function definitions for SYSTICK driver
*
* Author      : Hussein Mahmoud Fouad
*
* Version     : V01
*
* Date        : 31 MAY 2021
*
***************************************************************************/


#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"stdint.h"
#include"C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

#include"SYSTICK_interface.h"


/*********************************************************************
*                          Functions Definitions
**********************************************************************/

/*
*  Function Describtion : Initialize SYSTICK timer	
*  						  1. Disable SYSTICK timer to start intialization
*						  2. Disable SYSTICK interrupt
*						  3. Set CLK_Source bit
*                         4. Clear NVIC_ST_CURRENT_R register
*/
void SYSTICK_init(void)
{
	NVIC_ST_CTRL_R = 0; /* Disable SYSTICK Enable & interrupt bits */ 
	SET_BIT(NVIC_ST_CTRL_R, 2); /* Set CLK_Source bit */
	NVIC_ST_CURRENT_R = 0; /* Clear NVIC_ST_CURRENT_R register */
}


/*
*  Function Describtion : make the processor wait for 1 msec
*                         1. Clear NVIC_ST_CURRENT_R register
*                         2. Set SYSTICK enable bit in NVIC_ST_CTRL_R register
*                         2. Wait until COUNT bit in NVIC_ST_CTRL_R register is set
*                         3. Stop SYSTICK timer by clearing Enable bit in SYSTICK
*/
void SYSTICK_BusyWait_1ms(void)
{
	NVIC_ST_RELOAD_R = 15999; /* Reload value for 1 msec delay */
	SET_BIT(NVIC_ST_CTRL_R, 0); /* Set SYSTICK enable bit in NVIC_ST_CTRL_R register */
	while(BIT_IS_CLEAR(NVIC_ST_CTRL_R, 16)); /* wait until COUNT bit in NVIC_ST_CTRL_R register is set */
	CLEAR_BIT(NVIC_ST_CTRL_R, 0); /* Clear SYSTICK enable bit in NVIC_ST_CTRL_R register */
}



/*
*  Function Describtion : make the processor wait for certain time in ms
*/
void SYSTICK_BusyWaitms(uint32 time_ms)
{
	uint32 i;
	for( i = 0; i<time_ms; i++)
	{
	SYSTICK_BusyWait_1ms();
	}
}

