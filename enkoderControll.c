#include "enkoderControll.h"


void ResetEncoder(struct ENCODER* a)
{
	a->ticks = 0;
	a->misstakes =0;
}
void SetUpInterrupt(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	GPIOA->CRL &= ~(GPIO_CRL_CNF5 | GPIO_CRL_CNF4 );
	GPIOA->CRL |= GPIO_CRL_CNF5_1 | GPIO_CRL_CNF4_1;
	
	
	EXTI->IMR = (1<<5) | (1<<4);
	EXTI->RTSR = (1<<5) | (1<<4);
	EXTI->FTSR &= ~(1<<5) | (1<<4);
	
	
	

	NVIC_EnableIRQ(EXTI4_IRQn);
	
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	NVIC_SetPriority(EXTI4_IRQn, 1);
	NVIC_SetPriority(EXTI9_5_IRQn, 1);
}



