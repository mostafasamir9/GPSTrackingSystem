#include "tm4c123gh6pm.h"
#include "stdint.h"

void UART_Enable(uint32_t uart);
void Port_Enable(uint32_t port);
void UART_Select(void);
void Baud_rate_set(uint32_t i,uint32_t f);
void UART0_Init(void);

