#include <stm32f10x.h>
#include "COMControll.h"
#include "BaseFunctions.h"

void ButtonInit(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
}
void LedInit(void)
{
//	c9 i 8
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH |= GPIO_CRH_MODE8 |GPIO_CRH_MODE9;
  GPIOC->CRH &=	~(GPIO_CRH_CNF8 | GPIO_CRH_CNF9);
}
void clock_configuration(void)
 {
	 
	RCC->CR |= RCC_CR_HSION; 
	while ((RCC->CR & RCC_CR_HSIRDY)!= RCC_CR_HSIRDY) {};
		
	FLASH->ACR |= FLASH_ACR_HLFCYA;
		
	RCC->CFGR &= ~RCC_CFGR_PLLSRC; 
	RCC->CFGR |= RCC_CFGR_PLLMULL; //4*6 zwielokrotnienie
		
	RCC->CR |= RCC_CR_PLLON;
	while ((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY){};
		
	RCC->CFGR &= ~RCC_CFGR_PPRE1_DIV16;	
	RCC->CFGR &= ~RCC_CFGR_PPRE2_DIV16;	
		
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
		
	RCC->CFGR |= RCC_CFGR_SW_PLL;	
}
