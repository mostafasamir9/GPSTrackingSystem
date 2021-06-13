#include "Header_Project.h"


void SystemInit(void){}

	
	/****************************************************************************************
	*                         Global Variables initializations
	*****************************************************************************************/
	uint8_t north_east_counter=0; /* Global variable that count  the nunber of the sampled point */

	uint32_t g_TotalDis=0, g_SampleDis = 0; /* Two global variables: g_TotatalDis one for storing the total distance covered by the user */
	/* g_SampleDis for sampling the distance covered by GPS -> Sample = 5 meters */
	
	//uint8_t i=0; /* dumy variable used in calculations */
	uint8_t x; /* dumy variable used in calculations */
	
	Position p1,p2;  /* This structure is defined in GPS_Calculations module */
									/* Two structures of type position holding two members -> for North and East locatons	*/
	
	
	/***************************************************************************************
	*                     Functions Definitions for the main GPS tasks
	*****************************************************************************************/
	
/*
** Function Describtion : Function for Task1 to take sample Points for the GPS position P2
*/
	void GPS_Task1_Sample(void)
	{
	  LCD_goToRowColumn(0, 10); /* Clear the previous the number writen on LCD */
		LCD_Print("     ");
		LCD_goToRowColumn(0, 10); /* Print the latest Total distance value covered by the user */
		LCD_PrintNumber(g_TotalDis);
		SYSTICK_BusyWaitms(1000);
		//UART2_TX('x');
	  x=UART2_RX(); /* Display the data sent by GPS to keep an eye on the reading on the Tera Term while moving */
	  UART0_TX(x);

		p2= GPS_get_coordinates(); /* Read P2 sampling from GPS */
		g_SampleDis = GPS_CalculateDistance(p1.North, p1.East, p2.North, p2.East);/* Calculate the sampled distance */
		/* if the sampled distance less than 5 meters then considered it as an error from GPS and IGNOR it */
		/* if the sampled distance is greater than 5 then considered it as a new position and add the sampled distance to the total distance  */
	}
	  
	
	
	
	
/*
** Function Describtion : Function for Task2 to add the sampled ditance to the Total distance
*/
	void GPS_Task2_TotalDistance(void)
	{
		
		
		if(north_east_counter<16) /* if north_east_counter is less 16 then the block of the eeprom is full and move to another block */
		{
		EEPROM_write(100,p2.North*100000); /* Multiply the reading North from GPS by 10^5 to be able to store the reading as an integer in eeprom */
		SYSTICK_BusyWaitms(500); /* wait half second for the data to be stabled in eerom */
		EEPROM_write(200,p2.East*100000); /* Multiply the reading  Eastfrom GPS by 10^5 to be able to store the reading as an integer in eeprom */
		SYSTICK_BusyWaitms(500); /* wait half second for the data to be stabled in eerom */
			north_east_counter++; /* block offset + 1 */
		}
		
		
		else if(north_east_counter>=16) /* if north_east_counter is less 16 then the block of the eeprom is full and move to another block */
		{
			EEPROM_write(101,p2.North*100000); /* Multiply the reading North from GPS by 10^5 to be able to store the reading as an integer in eeprom */
			SYSTICK_BusyWaitms(500);  /* wait half second for the data to be stabled in eerom */
			EEPROM_write(201,p2.East*100000); /* Multiply the reading  Eastfrom GPS by 10^5 to be able to store the reading as an integer in eeprom */
			SYSTICK_BusyWaitms(500); /* block offset + 1 */
		}
		
		p1=p2; /* Move to the net point */
		g_TotalDis += g_SampleDis; /* Add sampled distance to total distance */
		g_SampleDis=0; /* Re-sampling distance */
	}

int main(void){
//uint8_t i; /* Dumy variable */
	
	uint8_t flag_100Dis = 1; /* Flag for turning on green led one time when total distance>=100 */
	LCD_init(); /* Initialize LCD */
	//LCD_sendCommand(CLEAR_SCREEN); /* Clear LCD */
	LCD_Print("Distance = "); 
	UART_init(UART0); /* Initialize UART0 for USB TivaC -> Tera Term*/
	UART_init(UART2); /* Initialize UART2 for GPS */
	SYSTICK_init(); /* Initalize systick timer*/
	PFInterruptInit();
	EnableInterrupts();
//	LCD_sendCommand(CLEAR_SCREEN );
	EEPROM_init();

	
    DIO_init(PORTF, GREEN, OUTPUT, NO_PUR);
//UART2_TX('x');
//while(UART2_RX()!='U') {};
	//LCD_PrintNumber(EEPROM_read(100));
	p1 = GPS_get_coordinates(); /* Get the coordinate of the initial point from GPS */
	EEPROM_write(100,p1.North*1000000);
	//LCD_goToRowColumn(1,0);
	//LCD_PrintNumber(EEPROM_read(100));
	SYSTICK_BusyWaitms(500);
	EEPROM_write(200,p1.East*100000);
	SYSTICK_BusyWaitms(500);
	north_east_counter=1;

//LCD_goToRowColumn(1,0);
//	LCD_sendChar('R');
//LCD_goToRowColumn(0,10);
	
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



