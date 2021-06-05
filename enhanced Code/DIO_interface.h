/************************************************************************
* 
* Module      : DIO (Digital Input/Output)
*
* File Nmae   : DIO_interface.h
*
* Describtion : Header File for "ARM DIO driver" containing function prototypes of DIO driver
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V02
*
* Date        : 3 June 2021
*
***************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include"DIO_config.h"
#include"STD_TYPES.h"

/************************************************************************
*                       Functions Prototypes
*************************************************************************/
//--------------------------------------------------------------//
/* Function Parameters : 1. Required Port
*                        2. Required Pin
*                        3. Dirction of the Pin (Input/Output)
*                        4. Required/(Not reuired) internal Pull-up resistor for input Pins
*	
*  Function Return      : void
*/
void DIO_init(uint8 PORT, uint8 PIN ,uint8 DIR, uint8 pur);


//-------------------------------------------------------------//
/* Function Parameters : Required Port
*                        
*  Function Return      : void
*/
void DIO_initPortOutput(uint8 PORT);


//-------------------------------------------------------------//
/* Function Parameters : 1. Required Port
*                        2. Required Pin
*
*  Function Return      : uint8 (one or zero)
*/
uint8 DIO_ReadPin(uint8 PORT, uint8 PIN);


//-------------------------------------------------------------//
/* Function Parameters : Required Port
*
*  Function Return      : uint32
*/
uint32 DIO_ReadPort(uint8 PORT);


//-------------------------------------------------------------//
/************************************************************************************/
/*
*  Function Parameters : 1. Required Port
*                        2. Required output
*
*  Function Return      : void
*/
void DIO_WritePort(uint8 PORT, uint32 WriteValue);


//-------------------------------------------------------------//
/***************************************************************/
/* Function Parameters : 1. Required Port
*                        2. Required Pin
*                        3. Required output (1/0)
*
* Function Return      : void
*/
void DIO_WritePin(uint8 PORT, uint8 PIN, uint8 WriteValue);


#endif /*DIO_INTERFACE_H_*/
