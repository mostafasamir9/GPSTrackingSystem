//---------------------------------------------------------//
/*  Describtion: Function to Print Number On LCD
*				 1. Get number og digits in the number
*        2. Get the number of each digit & print it on LCD
*************************************************************/
void LCD_PrintNumber(uint32 a_num){
	uint32 dummy_var=a_num; /* a dummy variable used in displaying the number on LCD */
	uint8 digit_count = 0; /* variable to count the number of digit of a_num variable */

	/* check if the sent number is zero Print zero on LCD then edummy_varit function */
	if(a_num == 0){
		LCD_sendChar('0');
		return;
	}
	
	/* count the number of digits of the passed number "num" and store it in digit_count variable*/
	while(dummy_var != 0){
		dummy_var = dummy_var / 10;
		digit_count++;
	}
	
	
	/* Print the number on LCD screen starting form highest digit */
	dummy_var = a_num;
	while(digit_count != 0){
		dummy_var = a_num/power(10, digit_count-1);
		LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
		a_num     = a_num - dummy_var*power(10,digit_count-1); /* remove the greates digit from the number a_num as its printed */
		digit_count--;
	}
	
	/* Check for floating point */
	if((uint32_t)(a_num*100) % 100 != 0){
		LCD_sendChar('.');
		dummy_var = a_num * 100;
		digit_count = 2;
		dummy_var = dummy_var % power(10, digit_count);
		dummy_var /= power(10, digit_count-1);
		LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
		dummy_var = a_num * 100;
		dummy_var = dummy_var % power(10, digit_count-1);
		dummy_var = dummy_var / power(10, digit_count-2);
		if(dummy_var != 0)	LCD_sendChar(dummy_var+48);  /* add 48 to the number to be dispalyed on LCD as a character */
	}
}