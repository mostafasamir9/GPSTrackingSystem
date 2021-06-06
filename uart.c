#include "uart.h"

#define PORT 'A'
#define Uart_D 2
#define Uart_E 5

void UART_Enable(uint32_t uart)
{
	//UART Enable register select
	SYSCTL_RCGCUART_R |= uart;
} 


void Port_Enable(uint32_t port)
{
	//Enable which port we will work with
	SYSCTL_RCGCGPIO_R |= port;
} 

void UART_Select(void)
{
	//en is the variable which select the uart bits in each port
	//port is the var which select the port we will work with as uart like portA or portB or so on
	//bits is the var which select each bit of the the port we set in  PCTL REG
	// clear the PCTL reg before we deal with
	//is the var which set the digital ports
	//in this function i don't put port C because of the locks
	switch(PORT)
	{
		case 'A':
			GPIO_PORTA_AFSEL_R |= 0x00000003;
			GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) + 0x00000011;
			GPIO_PORTA_DEN_R |= 0x00000003;
			GPIO_PORTA_AMSEL_R &= ~(0x00000003); //disable the analog on this ports
		case 'B':
			GPIO_PORTB_AFSEL_R |= 0x00000003;
			GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00) + 0x00000011;
			GPIO_PORTB_DEN_R |= 0x00000003;
			GPIO_PORTB_AMSEL_R &= ~(0x00000003);
		case 'D':
			switch(Uart_D)
			{
				case (6):
					GPIO_PORTD_AFSEL_R |= 0x00000030;
					GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF) + 0x00110000;
					GPIO_PORTD_DEN_R |= 0x00000030;
					GPIO_PORTD_AMSEL_R &= ~(0x00000030);
				case (2):
					GPIO_PORTD_AFSEL_R |= 0x000000C0;
					GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FFFFFF) + 0x11000000;
					GPIO_PORTD_DEN_R |= 0x000000C0;
					GPIO_PORTD_AMSEL_R &= ~(0x000000C0);
			}

		case 'E':
			switch(Uart_E)
			{
				case (7):
					GPIO_PORTE_AFSEL_R |= 0x00000003;
					GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFFFFFF00) + 0x00000011;
					GPIO_PORTE_DEN_R |= 0x00000003;
					GPIO_PORTE_AMSEL_R &= ~(0x00000003);
				case (5):
					GPIO_PORTE_AFSEL_R |= 0x00000030;
					GPIO_PORTE_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF) + 0x00110000;
					GPIO_PORTE_DEN_R |= 0x00000030;
					GPIO_PORTE_AMSEL_R &= ~(0x00000030);
			}
		default:
			GPIO_PORTA_AFSEL_R |= 0x00000003;
			GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) + 0x00000011;
			GPIO_PORTA_DEN_R |= 0x00000003;
			GPIO_PORTA_AMSEL_R &= ~(0x00000003);
	}
}

void Baud_rate_set(uint32_t i,uint32_t f)
{
	switch(PORT)
	{
		case 'A':
			UART0_CTL_R &= ~(0x00000001);//disable the uart first
			UART0_IBRD_R = i;
			UART0_FBRD_R = f;
			UART0_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
			UART0_CTL_R |= 0x00000301;
		case 'B':
			UART1_CTL_R &= ~(0x00000001);//disable the uart first
			UART1_IBRD_R = i;
			UART1_FBRD_R = f;
			UART1_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
			UART1_CTL_R |=0x00000301;
		case 'D':
			switch(Uart_D)
			{
				case(6):
					UART6_CTL_R &= ~(0x00000001);//disable the uart first
					UART6_IBRD_R = i;
					UART6_FBRD_R = f;
					UART6_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
					UART6_CTL_R |= 0x00000301;
				case(2):
					UART2_CTL_R &= ~(0x00000001);//disable the uart first
					UART2_IBRD_R = i;
					UART2_FBRD_R = f;
					UART2_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
					UART2_CTL_R |= 0x00000301;
			}
		case 'E':
			switch(Uart_E)
			{
				case(7):
					UART7_CTL_R &= ~(0x00000001);//disable the uart first
					UART7_IBRD_R = i;
					UART7_FBRD_R = f;
					UART7_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
					UART7_CTL_R |= 0x00000301;
				case(5):
					UART5_CTL_R &= ~(0x00000001);;//disable the uart first
					UART5_IBRD_R = i;
					UART5_FBRD_R = f;
					UART5_LCRH_R = 0x00000070; //8 bits , no parity , one stop, FIFO 
					UART5_CTL_R |= 0x00000301;
			}
	}
	
}

//function that initalize uart A
void UART0_Init(void)
{
	UART_Enable(0x00000001);
	Port_Enable(0x00000001);
	Baud_rate_set(104,11);//port A
	UART_Select();
	//GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	//GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	//GPIO_PORTA_DEN_R |= GPIO_PA10_M;
}

void SystemInit(){}
	
int main(void)
{

return 1;
}
