#include"stdint.h"
#include"tm4c123gh6pm.h"
void SystemInit(){}
	
#include"BIT_MATH.h"
#include"STD_TYPES.h"	
	
#include"DIO_interface.h"
#include"SYSTICK_interface.h"

#include"LCD_interface.h"	
	
#include"GPS_Calculations.h"
	
int main()
{
	int32_t x_initial = 10, y_initial = -20;  /* iniitial values for the start point (x,y)  */
	
	
/****************** This is used as a test for now till functions are ready **************************/
	int32_t arr_x[] = {13,   18,  25,  37,  40,  42,  50,  93};
	int32_t arr_y[] = {-22, -29, -33, -35, -35, -35, -38, -38};
	uint32_t current = 0; /* Dummy variable for the test case array for GPS function */
	uint32_t Distance;  /* Distance covered from initial point */
	
	
	SYSTICK_init();
	DIO_init(PORTF, GREEN, OUTPUT, NO_PUR);
	LCD_init();
	

	
	while(1)
	{
		
		LCD_Print("Distance: ");
		
		Distance = GPS_CalculateDistance(x_initial, arr_x[current], y_initial, arr_y[current]);	
		
		LCD_PrintNumber(Distance);
		
		if(Distance>=100)
		{
		DIO_WritePin(PORTF, GREEN, HIGH);
		}
		
		else
		{
			DIO_WritePin(PORTF, GREEN, LOW);
		}
		
		SYSTICK_BusyWaitms(1500);
		
		LCD_sendCommand(CLEAR_SCREEN);
		
		if(current<7)
		{ 
		current++;
		}
		
}
	
}

