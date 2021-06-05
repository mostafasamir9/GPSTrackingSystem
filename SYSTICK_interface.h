/************************************************************************
* 
* Module      : SYSTICK timer
*
* File Nmae   : SYSTICK_interface.h
*
* Describtion : Header File for "ARM SYSTICK driver" containing the function prototype for SYSTICK driver
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 31 MAY 2021
*
***************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


#include"BIT_MATH.h"
#include"STD_TYPES.h"


/*********************************************************************
*                          Function Portotype
**********************************************************************/

/*
*  Function Parameters : void	
*  Function Return     : void
*/
void SYSTICK_init(void);


/*
*  Function Parameters : Time to wait in msec	
*  Function Return     : void
*/
void SYSTICK_BusyWaitms(uint32 time_ms);

#endif /* SYSTICK_interface_h_ */
