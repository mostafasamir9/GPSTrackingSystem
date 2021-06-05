/************************************************************************
* 
* Module      : LCD
*
* File Nmae   : GPS_Calculation.c
*
* Describtion : Source file for "GPS Module" containing the function definitions for GPS driver
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 5 June 2021
*
***************************************************************************/
#include "GPS_Calculations.h"

//---------------------------------------------------------//
/************************************************************  
*  Describtion: static (private) function used to find the +ve value of the passed argument
**************************************************************/
static uint32_t absolute(int32_t num){
	return (num >= 0)? num: -1*num;
}


//---------------------------------------------------------//
/***********************************************************  
*  Describtion: Function used to calculate the distance covered by from the start(initial point) 
**************************************************************/
uint32_t GPS_CalculateDistance(int32_t initial_x, int32_t current_x, int32_t initial_y, int32_t current_y)
{	
	return absolute(current_y - initial_y) + absolute(current_x - initial_x);
}

