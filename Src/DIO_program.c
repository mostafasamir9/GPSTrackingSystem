/************************************************************************************/
/*
*  Describtion: Function to Write required Pin output
*/
void DIO_WritePin(uint8 PORT, uint8 PIN, uint8 WriteValue)
{
	switch(PORT)
	{
	  case PORTA: MAKE_BIT_VALUE(GPIO_PORTA_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTB:	MAKE_BIT_VALUE(GPIO_PORTB_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTC: MAKE_BIT_VALUE(GPIO_PORTC_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTD: MAKE_BIT_VALUE(GPIO_PORTD_DATA_R, PIN, WriteValue&1);
							  break;
					
		case PORTE: MAKE_BIT_VALUE(GPIO_PORTE_DATA_R, PIN, WriteValue&1);
							  break;
					
		default: MAKE_BIT_VALUE(GPIO_PORTF_DATA_R, PIN, WriteValue);
							  break;
					
	}
}