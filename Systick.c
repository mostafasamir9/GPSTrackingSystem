#include "Systick.h"

void Systick_init(void){
	NVIC_ST_CTRL_R = 0;								// Initialization for control reg
	NVIC_ST_RELOAD_R = 0XFFFFFF;			// Maximum value for Reload reg
	NVIC_ST_CURRENT_R = 0;						// Set the current reg to 0
	NVIC_ST_CTRL_R = 0X05;						// enable=1, ClkSrc=1 (System Clk = 16M)
}

void Systick_wait_1ms(){
	NVIC_ST_RELOAD_R = 15999;					// Reload Value = (Time in Sec * 16M) - 1
	NVIC_ST_CURRENT_R = 0;						// Set the current reg to 0
	while((NVIC_ST_CTRL_R & (1<<16)) == 0){};
}

void Systick_wait(uint32_t count){
	uint32_t i;
	for(i=0; i<count; i++){
		Systick_wait_1ms();
	}
}