

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#include"BIT_MATH.h"

/**************************************************
*           Config Ports
******************************************************/
#define LCD_DATA_PORT_R    GPIO_PORTB_DATA_R
#define LCD_CTRL_PORT_R    GPIO_PORTE_DATA_R


#define LCD_DATA_PORT_CONFIG  PORTB
#define LCD_CTRL_PORT_CONFIG  PORTE



/***********************************************
*           Config Pins
************************************************/
#define RS 1
#define RW 2
#define EN 3


/*************************************************
*                LCD Commands
*************************************************/
#define CLEAR_SCREEN        0x01
#define CURSOR_OFF          0x0C
#define TWO_LINES_8BIT_MODE 0x38


/********** Config Delay Time ***********/
#define DELAY_TIME 3


#endif

