#include "enkoderControll.h"

struct ENCODER force;
struct ENCODER translation;

void SetUpInterrupt(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOB->CRL &= ~(GPIO_CRL_CNF0);
	GPIOB->CRL |= GPIO_CRL_CNF0_1;
	
	GPIOA->CRL &= ~(GPIO_CRL_CNF1 | GPIO_CRL_CNF2 | GPIO_CRL_CNF3 | GPIO_CRL_CNF4 );
	GPIOA->CRL |= GPIO_CRL_CNF1_1 | GPIO_CRL_CNF2_1 |GPIO_CRL_CNF3_1 | GPIO_CRL_CNF4_1;
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	EXTI->IMR = 0x001E;
	EXTI->RTSR = 0x01E;
	//EXTI->FTSR = 0x001F;
	
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
}



void EXTI1_IRQHandler() //PA1 linia - A 
{
		
}
void EXTI2_IRQHandler() //PA2 linia - B
{
	
}
void EXTI3_IRQHandler()
{
	GPIOC->BSRR |= GPIO_BSRR_BS9;
}
void EXTI4_IRQHandler()
{
	GPIOC->BSRR |= GPIO_BSRR_BR9;
}