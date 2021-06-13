#include "Header_Project.h"


void SystemInit(void){}

	uint8_t north_east_counter=0;
	uint32_t g_TotalDis=0, g_SampleDis = 0;
	uint8_t i=0;
	uint8_t x;
	Position p1,p2;
	void GPS_Task1_Sample(void)
	{
		//LCD_PrintNumber(1);
	  LCD_goToRowColumn(0, 10);
		LCD_Print("     ");
		LCD_goToRowColumn(0, 10);
		LCD_PrintNumber(g_TotalDis);
		SYSTICK_BusyWaitms(1000);
		//UART2_TX('x');
	  x=UART2_RX();
	  UART0_TX(x);

		p2= GPS_get_coordinates();
		g_SampleDis = GPS_CalculateDistance(p1.North, p1.East, p2.North, p2.East);
	
	
		
	}