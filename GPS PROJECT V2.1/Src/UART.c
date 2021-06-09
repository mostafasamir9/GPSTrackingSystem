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
* Version     : V01
*
* Date        : 5 June 2021
*
***************************************************************************/
#include"BIT_MATH.h"
#include"UART.h"

void UART_init(uint8_t UART_no)
{

	


/* For UART0 */
	switch(UART_no)
	{
		case UART0:
			SET_BIT(SYSCTL_RCGCUART_R,UART0);
      SET_BIT(SYSCTL_RCGCGPIO_R,UART0);
     CLEAR_BIT( UART0_CTL_R,UART_CTL_UARTEN);
     UART0_IBRD_R = 104;    
     UART0_FBRD_R = 11;
  
     UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN); /* Enable 8bit mode , Enable FIFO */
	   UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

     GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	   GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	   GPIO_PORTA_DEN_R |= GPIO_PA10_M;
		break;
		case UART2:
			SET_BIT(SYSCTL_RCGCUART_R,UART2);
      SET_BIT(SYSCTL_RCGCGPIO_R,PORTD);
		  CLEAR_BIT( UART2_CTL_R,UART_CTL_UARTEN);
      UART2_IBRD_R = 104;    
      UART2_FBRD_R = 11;
		  UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN); /* Enable 8bit mode , Enable FIFO */
	    UART2_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
      GPIO_PORTD_AFSEL_R |= GPIO_PD67_M;
		  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FFFFFF) | (GPIO_PCTL_PD7_U2TX | GPIO_PCTL_PD6_U2RX);
		   GPIO_PORTD_DEN_R |= GPIO_PD67_M;
		 break;
	}
}
	

void UART0_TX(uint8_t data)
{
	while( BIT_IS_SET(UART0_FR_R,5)); //UART_FR_TXFF->5
	UART0_DR_R = data;
}

uint8_t UART0_RX(void)
{
	while( BIT_IS_SET(UART0_FR_R,4)); //UART_FR_RXFE->4
	return UART0_DR_R;
}
void UART2_TX(uint8_t data)
{
	while( BIT_IS_SET(UART0_FR_R,5)); //UART_FR_TXFF->5
	UART2_DR_R = data;
}
uint8_t UART2_RX(void)
{
	while( BIT_IS_SET(UART0_FR_R,4)); //UART_FR_RXFE->4
	return UART2_DR_R;
}

