#include "tm4c123gh6pm.h"
#include "stdint.h"

void Systick_init(void);
void Systick_wait_1ms();
void Systick_wait(uint32_t count);