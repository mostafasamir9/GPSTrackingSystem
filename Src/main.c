void GPIOF_Handler(void){
	uint8_t chr;
	GPIO_PORTF_ICR_R |= 0x10; // acknowledge flag
	LED_OFF();
	chr = UART0_RX();
	while(1){
		if (chr == 'U'){
			//EEPROM SEND
		
		}
	}
}
