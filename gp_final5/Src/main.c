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
	
	void GPS_Task2_TotalDistance(void)
	{
		if(north_east_counter<16)
		{
		EEPROM_write(100,p2.North*100000);
		SYSTICK_BusyWaitms(500);
		EEPROM_write(200,p2.East*100000);
		SYSTICK_BusyWaitms(500);
			north_east_counter++;
		}
		else if(north_east_counter>=16)
		{
			EEPROM_write(101,p2.North*100000);
			SYSTICK_BusyWaitms(500);
			EEPROM_write(201,p2.East*100000);
			SYSTICK_BusyWaitms(500);
		}
		p1=p2;
		g_TotalDis += g_SampleDis;
		g_SampleDis=0;
	}

int main(void){
uint8_t i;
	
	uint8_t flag_100Dis = 1;
	LCD_init();
	LCD_sendCommand(CLEAR_SCREEN);
	LCD_Print("Distance = ");
	UART_init(UART0);
	UART_init(UART2);
	SYSTICK_init();
	PFInterruptInit();
	EnableInterrupts();
//	LCD_sendCommand(CLEAR_SCREEN );
	EEPROM_init();
	
	//EEPROM_write(21,3003.65069*100000);
//	LCD_PrintNumber(EEPROM_read(21));
	//EEPROM_read(21);
//SYSTICK_BusyWaitms(500);
	
	
/* LCD_goToRowColumn(0,0);
	for( i = 0 ;i<5;i++)
	{
	//EEPROM_write(21,i*2);
LCD_PrintNumber(EEPROM_read(21));
		//LCD_PrintNumber(EEPROM_read(20+i/16, i%16));
		//LCD_sendChar(' ');
		SYSTICK_BusyWaitms(500);
	}
	SYSTICK_BusyWaitms(1000);
	LCD_goToRowColumn(1,0);
//	EEPROM_write(1);
	//EEPROM_read();
	for( i = 0 ;i<5;i++)
	{
//	EEPROM_write(25,i*3);
	LCD_PrintNumber(EEPROM_read(25));
	//LCD_PrintNumber(EEPROM_read(20+i/16, i%16));
	//LCD_sendChar(' ');
	SYSTICK_BusyWaitms(500);
	}*/
	
	

	
    DIO_init(PORTF, GREEN, OUTPUT, NO_PUR);
//UART2_TX('x');
//while(UART2_RX()!='U') {};
	//LCD_PrintNumber(EEPROM_read(100));
	p1 = GPS_get_coordinates(); /* Get the coordinate of the initial point from GPS */
	//EEPROM_write(100,p1.North*1000000);
	LCD_goToRowColumn(1,0);
	LCD_PrintNumber(EEPROM_read(100));
	SYSTICK_BusyWaitms(500);
	//EEPROM_write(200,p1.East*100000);
	//SYSTICK_BusyWaitms(500);
	north_east_counter=1;

LCD_goToRowColumn(1,0);
	LCD_sendChar('R');
LCD_goToRowColumn(0,10);
	
	g_TotalDis = 0;
	g_SampleDis=0;
	while(1)
	{//3002.76643
if(g_TotalDis<100)
	{
		if( g_SampleDis < 5)
		{
	
	   GPS_Task1_Sample();
		}
		else if(g_SampleDis>=5)
			{
			
	     GPS_Task2_TotalDistance();
			}
	}
//Check if the distance covered reached 100 meter the turn on green LED for one time according to the flag variable "flag_100Dis" */
	else if( (g_TotalDis >=100)&&(flag_100Dis) )  
		{
			 LCD_goToRowColumn(0, 10);
		   LCD_Print("     ");
		   LCD_goToRowColumn(0, 10);
		   LCD_PrintNumber(g_TotalDis);
			DIO_WritePin(PORTF, GREEN, HIGH);
			flag_100Dis=0;
		}	
		
	}
	
	}



