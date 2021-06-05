/************************************************************************
* 
* Module      : DIO (Digital Input/Output)
*
* File Nmae   : DIO_config.h
*
* Describtion : Header File for "ARM DIO driver" containing configuration parameters
*
* Author      : Hussein Mahmoud
*
* Version     : V02
*
* Date        : 6 June 2021
*
***************************************************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* Ports Definition  */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

/* Input/Output Definition */
#define INPUT  0
#define OUTPUT 1

/* Pull-up resistor definition */
#define NO_PUR 0
#define PUR    1

/* LEds Colors */
#define RED 1
#define BLUE 2
#define GREEN 3

#endif /* DIO_config_h_*/
