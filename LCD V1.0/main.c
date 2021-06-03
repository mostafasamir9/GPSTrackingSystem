#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "LCD.h"
#include "Systick.h"
#include "Calculations.h"
#include "string.h"
#include "PF_init.h"
#include "LED.h"
void SystemInit(){}
	
int main(){
	int32_t arr_x[] = {10,  13, 75, 80, 92, 90, 98, 100};
	int32_t arr_y[] = {-20, -25, -35, -40, -42, -48, -56, -56};
	uint32_t Distance = 0;																		// Initialize The Distance Variable
	int32_t prevx = arr_x[0];	int32_t prevy = arr_y[0];				// Initialize The previos variables with first value that GPS read
	int32_t curx;	int32_t cury;
	int32_t count = 0;
	Systick_init();
	PF_init();
	while(Distance <= 500){																		// Set The MAx distance needed to be reachesd to 500 m
		Lcd_init();
		LCD_Print("Distance: ");
		LCD_Print_Numbers(Distance);														// Wait 2 seconds between every point and the other from GPS
		Systick_wait(2000);
		curx = arr_x[count];	cury = arr_y[count];							// New Coordinates from GPS
		Distance += Short_Distance(prevx, prevy, curx, cury);		// Calculate Distance between 2 points
		prevx = curx;		prevy = cury;														// Give the old values to previous variables 
		count = (count+1) % 8;
	}
	Lcd_init();																								// to get cursor at the first position & clear screen
	LCD_Print("Distance: ");
	LCD_Print_Numbers(Distance);															// Print Final Distance
	LED_ON(0);																								// Red Led On after reaching the needed distance
}