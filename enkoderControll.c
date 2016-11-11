#include "enkoderControll.h"

void SetUpInterrupt(void)
{
	
	EXTI->IMR = 0x0001;
	EXTI->RTSR = 0x001;
	EXTI->FTSR = 0x0001;
	
	NVIC_EnableIRQ(EXTI0_IRQn);
	
}
