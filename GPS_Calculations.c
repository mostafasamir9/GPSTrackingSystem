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
//Function to calculate distance between two points using haverside algorithm in (degree.min)
uint32_t GPS_CalculateDistance(double long1, double lat1, double long2, double lat2){
	const int32_t r = 6371;
	double x = (long2 - long1) * (PI / 180);
	double y = (lat2 - lat1) * (PI / 180);
	double a = sin(y/2) * sin(y/2) + cos(lat1 * (PI / 180)) * cos(lat2 * (PI / 180)) * sin(x/2) * sin(x/2);
	double i = sqrt(a);
	double j = sqrt(1-a);
	double c = 2 * atan2(i,j);
	double d = r * c * 1000;
	uint32_t dis = (uint32_t) ceil(d);
	return dis; 
}

