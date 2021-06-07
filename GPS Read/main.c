#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "UART.h"
#include "stdint.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SYSTICK_interface.h"
#include "LCD_interface.h"	
#include "GPS_Calculations.h"

void SystemInit(void){
	PLL_Init();
	UART0_Init();
	LCD_init();
	SYSTICK_init();
}

int main(void){
	uint8_t in;
	uint8_t out;
	Position p1;
	p1 = GPS_get_coordinates();
	LCD_PrintNumber(p1.North);
	LCD_Print(" ");
	LCD_PrintNumber(p1.Earth);
	//in = UART0_Read();
	//out = in - 0x20;
	//UART0_Write(out);
	//LCD_sendChar(out);
	//while(1){}
}
