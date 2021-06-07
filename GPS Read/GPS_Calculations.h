/************************************************************************
* 
* Module      : LCD
*
* File Nmae   : LCD_program.c
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
#include "UART.h"
#include "math.h"
#define PI 3.14159265


typedef struct{
	double North;
	double Earth;
} Position;

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
uint32_t GPS_CalculateDistance(double long1, double lat1, double long2, double lat2);


//-------------------------------------------------------------//
/* Function Parameters : uint32_t Final Distance
*                        
*  Function Return     : void
*/
Position GPS_get_coordinates(void);


//-------------------------------------------------------------//
/* Function Parameters : array of char, uint8_t size
*                        
*  Function Return     : double
*/
double GPS_S_to_f(char *str, uint8 size);
