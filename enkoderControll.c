#include "enkoderControll.h"


void ResetEncoder(struct ENCODER* a)
{
	a->firstTick = true;
	a->ticks = 0;
}
void SetUpInterrupt(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOB->CRL &= ~(GPIO_CRL_CNF0);
	GPIOB->CRL |= GPIO_CRL_CNF0_1;
	
	GPIOA->CRL &= ~(GPIO_CRL_CNF1 | GPIO_CRL_CNF2 | GPIO_CRL_CNF3 | GPIO_CRL_CNF4 );
	GPIOA->CRL |= GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1 |GPIO_CRL_CNF3_1 | GPIO_CRL_CNF4_1;
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	EXTI->IMR = 0x001E;
	EXTI->RTSR = 0x001E;
	EXTI->FTSR &= ~0x001E;
	
	
	
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	
	NVIC_SetPriority(EXTI1_IRQn, 1);
	NVIC_SetPriority(EXTI2_IRQn, 1);
	NVIC_SetPriority(EXTI3_IRQn, 1);
	NVIC_SetPriority(EXTI4_IRQn, 1);
}



