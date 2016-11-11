#include <stm32f10x.h>
#include "COMControll.h"
#include "BaseFunctions.h"
#include "enkoderControll.h"

typedef enum
{
    true=1, false=0
}bool;


int main()
{
	
	bool done = false;
	
	clock_configuration();
	ButtonInit();
	LedInit();
	USARTInit();
	NVIC_EnableIRQ(USART1_IRQn);
	GPIOC->BSRR |= GPIO_BSRR_BR9;
	SetUpInterrupt();
	
	while(1){
		
		if((GPIOA->IDR & GPIO_IDR_IDR0)==GPIO_IDR_IDR0)
		{
		if(done == false)
			
//				if((USART1 -> SR & USART_SR_TXE) == USART_SR_TXE ){
//					USART1->DR = 0x5A;		
//					while((USART1->SR & USART_SR_TC) != USART_SR_TC){}
//						done = true;
//				}
				GPIOC->BSRR |= GPIO_BSRR_BR8;// | GPIO_BSRR_BR9;
			
		}
		else {
			done = false;
			GPIOC->BSRR |= GPIO_BSRR_BS8; //GPIO_BSRR_BS9;
		}
		
		
	}
	return 0;
}
void EXTI0_IRQHandler()
{
	if((GPIOC->ODR & GPIO_ODR_ODR9) ==  GPIO_IDR_IDR9)
			GPIOC->BSRR |= GPIO_BSRR_BR9;
	else
			GPIOC->BSRR |= GPIO_BSRR_BS9;
}
