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
* Version     : V03
*
* Date        : 10 June 2021
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



//---------------------------------------------------------//
/*  Describtion: Function to display character on LCD
*								 1. Set RS Pin.
*                2. Clear RW Pin then wait for a delay.
*				 				 3. Set EN Pin then wait for a delay.
*                4. Send the required data character then wait for a delay.
*                5. Clear EN Pin then wait for a delay.
*************************************************************/
void LCD_sendChar(uint8 data)
{
  SET_BIT(LCD_CTRL_PORT_R, RS);/* Data Mode: RS=1 */
	CLEAR_BIT(LCD_CTRL_PORT_R, RW);/* RW=0-> Write data */
	SYSTICK_BusyWaitms(DELAY_TIME);
	
	SET_BIT(LCD_CTRL_PORT_R, EN);/* EN=1->Set Enable Pin */
	SYSTICK_BusyWaitms(DELAY_TIME);
	
  LCD_DATA_PORT_R= data; /* Send data */
	SYSTICK_BusyWaitms(DELAY_TIME);
	
  CLEAR_BIT(LCD_CTRL_PORT_R,EN);/* Clear Enable-Pin */
  SYSTICK_BusyWaitms(DELAY_TIME);
}


//---------------------------------------------------------//
/*  Describtion: Function to initialize LCD
*				 1. Initialize LCD Data Port and CTRL Pins
*                2. Configure Two-line 8-bit mode
*                3. Turn-off cursor then clear the screen
*************************************************************/
void LCD_init(void)
{
	/* Initialize LCD  Ports */
   DIO_initPortOutput(LCD_DATA_PORT_CONFIG); 
   DIO_init(LCD_CTRL_PORT_CONFIG, RS , OUTPUT, NO_PUR);
   DIO_init(LCD_CTRL_PORT_CONFIG, RW , OUTPUT, NO_PUR);
   DIO_init(LCD_CTRL_PORT_CONFIG, EN , OUTPUT, NO_PUR);
   
   LCD_sendCommand(TWO_LINES_8BIT_MODE); /* Two-line 8-bit mode */
   LCD_sendCommand(CURSOR_OFF); /* Cursor-off  */
   LCD_sendCommand(CLEAR_SCREEN); /* Clear screen */
}

//---------------------------------------------------------//
/*  Describtion: Function to Print String On LCD
*************************************************************/
void LCD_Print(uint8 word[]){
	uint32_t i = 0;
	while(word[i] != '\0'){				/* Check the character with Null char(end of string) */
		LCD_sendChar(word[i]);
		i = i + 1;
	}
}


//---------------------------------------------------------//
/*  Describtion: static "Privite" function in LCD  unction to calculate the power of base number
*************************************************************/
static uint32 power(uint32 Base, uint32 Power){
	uint32_t num = 1;
	uint32_t i;
	for(i=Power; i>0; i--){
		num *= Base;
	}
	return num;
}


// NEW PART
//---------------------------------------------------------//
/*  Describtion: Function to Print Number On LCD
*				 1. Get number og digits in the number
*        2. Get the number of each digit & print it on LCD
*************************************************************/
void LCD_PrintNumber(uint32 a_num){
	uint32 dummy_var=a_num; /* a dummy variable used in displaying the number on LCD */
	uint8 digit_count = 0; /* variable to count the number of digit of a_num variable */

	/* check if the sent number is zero Print zero on LCD then edummy_varit function */
	if(a_num == 0){
		LCD_sendChar('0');
		return;
	}
	
	/* count the number of digits of the passed number "num" and store it in digit_count variable*/
	while(dummy_var != 0){
		dummy_var = dummy_var / 10;
		digit_count++;
	}
	
	
	/* Print the number on LCD screen starting form highest digit */
	dummy_var = a_num;
	while(digit_count != 0){
		dummy_var = a_num/power(10, digit_count-1);
		LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
		a_num     = a_num - dummy_var*power(10,digit_count-1); /* remove the greates digit from the number a_num as its printed */
		digit_count--;
	}
	
	/* Check for floating point */
	if((uint32_t)(a_num*100) % 100 != 0){
		LCD_sendChar('.');
		dummy_var = a_num * 100;
		digit_count = 2;
		dummy_var = dummy_var % power(10, digit_count);
		dummy_var /= power(10, digit_count-1);
		LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
		dummy_var = a_num * 100;
		dummy_var = dummy_var % power(10, digit_count-1);
		dummy_var = dummy_var / power(10, digit_count-2);
		if(dummy_var != 0)	LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
	}
}
//--------------------------------------------------------------//
/* description:function to go to specified cursor
     *   1-gets the num of row&column on the cursor
      *  2- go to this position
*************************************************************/
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;
	switch(row)
	{
		case 0:
			Address=col;
		  break;
		case 1:
			Address=col+0x40;
		  break;
	}
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}
/* description:function to clear all screen
     *   1- send command to clear all the screen
*************************************************************/
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_SCREEN); 
}

