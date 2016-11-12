#include <stm32f10x.h>
#include "COMControll.h"
#include "BaseFunctions.h"
#include "enkoderControll.h"



int main()
{
	
	clock_configuration();
	ButtonInit();
	LedInit();
	USARTInit();
	NVIC_EnableIRQ(USART1_IRQn);
	GPIOC->BSRR |= GPIO_BSRR_BR9;
	SetUpInterrupt();
	
	while(1){
	}
	return 0;
}


