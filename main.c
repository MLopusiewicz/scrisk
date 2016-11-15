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

void EXTI4_IRQHandler()
{
	if((GPIOA->IDR & E1_nA) == E1_nA){
		EXTI->PR |= EXTI_PR_PR4;
		force.misstakes ++;
		return;
	}
	if((GPIOA->IDR & E1_B) == E1_B){
		if((GPIOA->IDR & E1_nB) != E1_nB)
				++force.ticks;		
		else
				force.misstakes ++;
	}
	else {
		if((GPIOA->IDR & E1_nB) == E1_nB)
			--force.ticks;
		else
			force.misstakes ++;
	}
	
	EXTI->PR |= EXTI_PR_PR4;
}
void EXTI9_5_IRQHandler()
{	
	
	if((GPIOA->IDR & E2_nA) == E2_nA){
		EXTI->PR |= EXTI_PR_PR5;
		translation.misstakes ++;
		return;
	}
	if((GPIOA->IDR & E2_B) == E2_B){
		if((GPIOA->IDR & E2_nB) != E2_nB)
				++translation.ticks;		
		else
				translation.misstakes ++;
	}
	else {
		if((GPIOA->IDR & E2_nB) == E2_nB)  
			--translation.ticks;
		else
			translation.misstakes ++;
	}
	
	
	EXTI->PR |= EXTI_PR_PR5;
}

void USART1_IRQHandler (void) 
	{
	if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE){
		
		switch(USART1->DR)
		{
			case validationRequest:
						SendByte(deviceID); 
						break;
			case resetEncoders:
						force.ticks = 0;
						break;
			case ticksRequest:
							SendInt(force.ticks, 2);
							SendInt(translation.ticks, 2);
							force.ticks = 0;
							translation.ticks = 0;
							break;
			case misstakeRequest:
							SendInt(force.misstakes,2);
							SendInt(translation.misstakes,2);
							break;
		}
	}
}
