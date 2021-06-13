/************************************************************************
* 
* Module      : UART
*
* File Nmae   : UART.h
*
* Describtion : Source file for "GPS Module" containing the function definitions for GPS driver
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V02
*
* Date        : 10 June 2021
*
***************************************************************************/


#include"stdint.h"
#include"tm4c123gh6pm.h"

/**************************************************
*                  UART CONFIG
****************************************************/
#define UART0 0
#define UART1 1
#define UART2 2
#define PORTD 3




#define GPIO_PA10_M 0x03
#define GPIO_PD67_M 0xC0

void UART_init(uint8_t UART_no);

void UART0_TX(uint8_t data);

uint8_t UART0_RX(void);

void UART0_TX(uint8_t data);

uint8_t UART0_RX(void);

void UART2_TX(uint8_t data);

uint8_t UART2_RX(void);

