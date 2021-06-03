#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "stdint.h"

void LCD_Command(char command);
void Lcd_init(void);
void LCD_Data(char Data);
void LCD_Clear(void);
void LCD_Print(char (word)[]);
void Set_Cursor(char x, char y);
void LCD_Print_Numbers(uint32_t num);