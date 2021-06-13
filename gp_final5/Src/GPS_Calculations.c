/************************************************************************
* 
* Module      : GPS Module
*
* File Nmae   : GPS_Calculations.c
*
* Describtion : Source file for "GPS Module" containing the function definitions for GPS driver
*
* Authors     : Mohamed Ahmed - Hussein Mahmoud
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
uint32_t absolute(int32_t num){
	return (num >= 0)? num: -1*num;
}


//---------------------------------------------------------//
/***********************************************************  
*  Describtion: Function used to calculate the distance covered by from the start(initial point) 
**************************************************************/
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


//---------------------------------------------------------//
/***********************************************************  
*  Describtion: Function used to convert array of character to double datatype 
**************************************************************/
double GPS_S_to_f(char *str, uint8_t size){
	int8_t i;
	double Num = 0.00;
	for(i = size; i > 0; i--){
		Num += pow(10, i-1) * (int32_t)(str[size-i] - 48);
	}
	for(i = -1; i >= -5; i--){
		Num += pow(10, i) * (int32_t)(str[size+(-1*i)] - 48);
	}
	Num /= pow(10, size-2);
	return Num;
}


//---------------------------------------------------------//
/***********************************************************  
*  Describtion: Function used to Read the Coordinates from UART 
**************************************************************/
//line = UART2_RX(); UART0_TX(line);
// KMDHCDUDWEVC
// $GPGGA,185114.00,3003.92086,N,03116.55069,E,2,05,2.47,35.5,M,15.4,M,,*6
// $GPGSA,A,3,04,01,21,31,08,,,,,,,,3,32,2.47,2.22*0F
// $GPGSU,2,2,07,21,67,164,26,22,61,029,16,31,37,069,21*4A
// $GPGLL,3003.92086,N,03116.55069,E,185114.00,A,A*6E
Position GPS_get_coordinates(void){
	char line, North[12], East[12];
	uint8_t  counter=0;
	Position PT;
	while(1){
		line = UART2_RX(); UART0_TX(line); 
		if(line == '$'){
			line = UART2_RX(); UART0_TX(line);
			if(line == 'G'){
				line = UART2_RX(); UART0_TX(line);
				if(line == 'P'){
					line = UART2_RX(); UART0_TX(line);
					if(line == 'G'){
						line = UART2_RX(); UART0_TX(line);
						if(line == 'L'){
							line = UART2_RX(); UART0_TX(line);
							if(line == 'L'){
								line = UART2_RX(); UART0_TX(line);
								if(line == ','){
									/* Get The North Character */
									do{
										line = UART2_RX(); UART0_TX(line);
										North[counter] = line;
										counter++;
									}while(line != ',');
									PT.North = GPS_S_to_f(North, 4);
									counter = 0;
									line = UART2_RX(); UART0_TX(line);
									if(line == 'N'){
										line = UART2_RX(); UART0_TX(line);
										if(line == ','){
											/* Get the East Character */
											line = UART2_RX(); UART0_TX(line);
											while(line != ','){
												line = UART2_RX(); UART0_TX(line);
												East[counter] = line;
												counter++;
											}
											PT.East = GPS_S_to_f(East, 5);
											return PT;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

