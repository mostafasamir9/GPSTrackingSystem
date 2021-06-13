/************************************************************************
* 
* Module      : LCD
*
* File Nmae   : LCD_program.c
*
* Describtion : Source file for "LCD driver" containing the function definitions for LCD driver
*
* Authors     : Mustafa Mohsen - Mohamed Ahmed - Hussein Mahmoud
*
* Version     : V02
*
* Date        : 6 June 2021
*
***************************************************************************/
#include"stdint.h"
#include"tm4c123gh6pm.h"

#include"LCD_interface.h"
#include"LCD_config.h"


#include"DIO_interface.h"
#include"SYSTICK_interface.h"

//---------------------------------------------------------//
/*  Describtion: Function to send a command to LCD
*								 1. Clear RS Pin.
*                2. Clear RW Pin then wait for a delay.
*				 				 3. Set EN Pin then wait for a delay.
*                4. Send the required command then wait for a delay.
*                5. Clear EN Pin then wait for a delay.
*************************************************************/
void LCD_sendCommand(uint8 comm)
{
  CLEAR_BIT(LCD_CTRL_PORT_R,RS); /* Instruction Mode: RS=0 */
  CLEAR_BIT(LCD_CTRL_PORT_R,RW); /* RW=0 -> Write command to LCD */
  SYSTICK_BusyWaitms(DELAY_TIME);
	
	SET_BIT(LCD_CTRL_PORT_R,EN); 
	SYSTICK_BusyWaitms(DELAY_TIME);
	
	LCD_DATA_PORT_R=comm; /* send command to LCD */
  SYSTICK_BusyWaitms(DELAY_TIME);  
	
	CLEAR_BIT(LCD_CTRL_PORT_R, EN);
	SYSTICK_BusyWaitms(DELAY_TIME); 
}