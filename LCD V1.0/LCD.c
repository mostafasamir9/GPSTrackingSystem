#include "LCD.h"
#include "Systick.h"
#include "math.h"

void LCD_Command(char command){
	GPIO_PORTB_DATA_R = command;
	GPIO_PORTE_DATA_R |= 0X08;
	Systick_wait(2);
	GPIO_PORTE_DATA_R = 0;
}

void Lcd_init(void){
	Systick_wait(50);
	SYSCTL_RCGCGPIO_R |= 0X12;
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R = 0XFF;
	GPIO_PORTB_DIR_R = 0XFF;
	GPIO_PORTB_DEN_R = 0XFF;
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R = 0XFF;
	GPIO_PORTE_DIR_R = 0X0E;
	GPIO_PORTE_DEN_R = 0X0E;
	LCD_Command(0X38);								// 2 Lines & 5*7 character
	Systick_wait(1);
	LCD_Command(0X0C);								// Display On, Cursor On, Blinking off
	Systick_wait(1);
	LCD_Command(0X01);								// Clear Display
	Systick_wait(2);
}

void LCD_Data(char Data){
	GPIO_PORTE_DATA_R = 0X02;
	GPIO_PORTB_DATA_R = Data;
	GPIO_PORTE_DATA_R |= 0X08;
	Systick_wait(2);
	GPIO_PORTE_DATA_R = 0X02;
} 

void LCD_Clear(void){
	LCD_Command(0X01);
	Systick_wait(2);
}

void Set_Cursor(char x, char y){
	uint8_t comm = 0;
	comm |= (x==0)? 0x80:0xC0;
	comm += (y%16);
	LCD_Command(comm);
}

void LCD_Print(char (word)[]){
	uint32_t i = 0;
	while(word[i] != '\0'){							// Check the character with Null char(end of string)
		LCD_Data(word[i]);
		i = i + 1;
	}
}

void LCD_Print_Numbers(uint32_t num){
	uint32_t x, y;
	uint32_t count = 0;
	x = num;
	if(x == 0){
		LCD_Data(48);
	}
	while(x != 0){
		x = x / 10;
		count++;
	}
	x = num;
	while(count != 0){
		y = x%(int)pow(10, count);
		y = y/pow(10, count-1);
		count--;
			LCD_Data(y+48);
	}
}