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