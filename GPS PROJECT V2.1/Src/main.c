#include "Header_Project.h"

void SystemInit(void){}


int main(void){
	char x=5;
	uint32_t Distance, total_Distance = 0;
	Position p1,p2;
	LCD_init();
	LCD_Print("Distance= ");
	UART_init(UART0);
	UART_init(UART2);
	LCD_sendChar(x);
	SYSTICK_init();
	PFInterruptInit();
	EnableInterrupts();

	DIO_init(PORTF, GREEN, OUTPUT, NO_PUR);
//	LED_ON(1);
	UART2_TX('x');
	p1 = GPS_get_coordinates();
	while(total_Distance<100){
		//LCD_Print("GVD: ");
			LCD_goToRowColumn(0, 10);
		LCD_Print("     ");
		LCD_goToRowColumn(0, 10);
		LCD_PrintNumber(total_Distance);
		SYSTICK_BusyWaitms(1000);
		UART2_TX('x');
	  x=UART2_RX();
	  UART0_TX(x);

		p2= GPS_get_coordinates();
		//SYSTICK_BusyWaitms(250);
		//SYSTICK_BusyWaitms(250);
		//SYSTICK_BusyWaitms(250);
		//SYSTICK_BusyWaitms(250);
		//avg2.East=(p5.East+p6.East+p7.East+p8.East)/4.0;
	  //avg2.North=(p5.North+p6.North+p7.North+p8.North)/4.0;
	  Distance = GPS_CalculateDistance(p1.North, p1.East, p2.North, p2.East);

		p1=p2;
		
		//totalDistance+=Distance;
		
			total_Distance += Distance;
			//avg1=avg2;
			
			
		
	}
		DIO_WritePin(PORTF, GREEN, HIGH);

}

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
