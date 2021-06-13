/*
*  Function Describtion : make the processor wait for certain time in ms
*/
void SYSTICK_BusyWaitms(uint32 time_ms)
{
	uint32 i;
	for( i = 0; i<time_ms; i++)
	{
	SYSTICK_BusyWait_1ms();
	}
}
