#ifndef __LED__
#define __LED__
#include "stdint.h"

#include "tm4c123gh6pm.h"

void LED_Toggle(uint16_t color);
void LED_ON(uint16_t color);

#endif // __LED__
