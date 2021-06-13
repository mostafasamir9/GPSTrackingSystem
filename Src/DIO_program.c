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


/************************************************************************************/
/*
*  Describtion: Function to Read required Port value
*/
uint32 DIO_ReadPort(uint8 PORT)
{
	switch(PORT)
	{
		case PORTA: return GPIO_PORTA_DATA_R;
					 
		case PORTB:	return GPIO_PORTB_DATA_R;
				   
		case PORTC: return GPIO_PORTC_DATA_R;
					    
		case PORTD: return GPIO_PORTD_DATA_R;
					
		case PORTE: return GPIO_PORTE_DATA_R;
				       
		default: return GPIO_PORTF_DATA_R;
					
	}
}