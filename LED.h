// NEW PART
/************************************************************************
* 
* Module      : LED
*
* File Nmae   : LED.h
*
* Describtion : Header file for "Portf Led Part" containing the functions of turnning on & off for LED
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 11 June 2021
*
***************************************************************************/

#ifndef __LED__
#define __LED__
#include "stdint.h"

#include "tm4c123gh6pm.h"

void LED_ON(uint16_t color);
void LED_OFF(void);

#endif // __LED__
