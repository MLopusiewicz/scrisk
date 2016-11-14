#include <stm32f10x.h>

#include "COMControll.h"
#include "BaseFunctions.h"
#include "enkoderControll.h"

volatile struct ENCODER force;
volatile struct ENCODER translation;
volatile bool up;
int main()
{
	clock_configuration();
	ButtonInit();
	LedInit();
	USARTInit();
	SetUpInterrupt();
	
	ResetEncoder(&force);
	ResetEncoder(&translation);
	
	while(1){
		if((GPIOA->IDR & GPIO_IDR_IDR0) == GPIO_IDR_IDR0)
		{
		}
		
	}
	return 0;
}

void EXTI1_IRQHandler() //PA1 linia - A 
{
	//dodac linie ~A
	if((GPIOA->IDR & GPIO_IDR_IDR2) == GPIO_IDR_IDR2)
	{
		++force.ticks;		
	}
	else {
		--force.ticks;
	}
	
	EXTI->PR &= ~EXTI_PR_PR0;
}

void EXTI2_IRQHandler() //PA2 linia - B
{
//	if(force.lineA)
//	{
//		--force.ticks;
//		force.lineA = false;
//		force.lineB = false;
//	}
//	else {
//		force.lineB = true;
//	}
//	
	EXTI->PR &= ~EXTI_PR_PR2;
}
void EXTI3_IRQHandler()
{
	GPIOC->BSRR |= GPIO_BSRR_BS9;
	EXTI->PR &= ~EXTI_PR_PR3;
}
void EXTI4_IRQHandler()
{
	GPIOC->BSRR |= GPIO_BSRR_BR9;
	
	EXTI->PR &= ~EXTI_PR_PR4;
}

void USART1_IRQHandler (void) {
	if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE){
		
		if(USART1->DR == ForceTickValueRequest){
			SendInt(force.ticks);
			force.ticks = 0;
		}
		if(USART1->DR == validationRequest)
			Autenthicate();
	}
}



