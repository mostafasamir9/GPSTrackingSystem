/************************************************************************
* 
* Module      : GPS
*
* File Nmae   : GPS_Calculation.c
*
* Describtion : Header file for "GPS Module" containing the function prototypes for GPS driver
*
* Authors     : Mohamed Ahmed - Hussein Mahmoud
*
* Version     : V01
*
* Date        : 5 June 2021
*
***************************************************************************/
#include "stdint.h"
#include "LCD_interface.h"
#include "SYSTICK_interface.h"

//-------------------------------------------------------------//
/* Function Parameters : uint32_t num
*                        
*  Function Return     : abolute number (uint32_t)
*/
static uint32_t absolute(int32_t num);


//-------------------------------------------------------------//
/* Function Parameters : int32_t initial point coordinate x and y
*                        int32_t finale point coordinate x and y
*                        
*  Function Return     : Distance Covered (uint32_t)
*/
uint32_t GPS_CalculateDistance(int32_t initial_x, int32_t current_x, int32_t initial_y, int32_t current_y);

