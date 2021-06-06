/************************************************************************
* 
* Module      : LCD
*
* File Nmae   : LCD_interface.h
*
* Describtion : Hearder file File for "LCD driver" containing the function prototypes for LCD driver
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V02
*
* Date        : 6 June 2021
*
***************************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#include"STD_TYPES.h"

#include"LCD_config.h"

/**************************************************************
*           Function Prototypes
**************************************************************/
//-------------------------------------------------------------//
/* Function Parameters : void
*                        
*  Function Return      : void
*/
void LCD_init(void);


//-------------------------------------------------------------//
/* Function Parameters : command (uint8_t)
*                        
*  Function Return      : void
*/
void LCD_sendCommand(uint8 comm);

//-------------------------------------------------------------//
/* Function Parameters : data (uint8_t)
*                        
*  Function Return     : void
*/
void LCD_sendChar(uint8 data);

//-------------------------------------------------------------//
/* Function Parameters : array of char (string)
*                        
*  Function Return     : void
*/
void LCD_Print(uint8_t word[]);

//-------------------------------------------------------------//
/* Function Parameters : 2 variables from datatype uint32_t
*                        
*  Function Return     : uint32_t
*/
static uint32 power(uint32 Base, uint32 Power);

//-------------------------------------------------------------//
/* Function Parameters : uint32_t num
*                        
*  Function Return     : void
*/
void LCD_PrintNumber(uint32 num);

#endif

