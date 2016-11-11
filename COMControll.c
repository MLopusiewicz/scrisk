#include "COMControll.h"
#define validationRequest 125
#define deviceID 160
void USARTInit(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_AFIOEN ;
	
	AFIO->MAPR &= ~AFIO_MAPR_USART1_REMAP;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	GPIOA ->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
	GPIOA ->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_CNF10_0;
	GPIOA->CRH |= GPIO_CRH_MODE9;
	
	
	
	double div = (double)12000000/(16*9600);
	
	uint32_t mantissa = (int)div;
	
  mantissa = mantissa<< 4;
  USART1->BRR = mantissa;
	

	USART1->CR1  &= ~USART_CR1_M;	// 8 bitow 
	USART1->CR2 &= ~(USART_CR2_STOP); //1 stopbit
	USART1->CR1 |=USART_CR1_TE | USART_CR1_RE;
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART1->CR1 |= USART_CR1_UE;
	
}
void USART1_IRQHandler (void) {
	if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE){
		Autenthicate();
	}
	
				GPIOC->BSRR |= GPIO_BSRR_BS9;
}
void Autenthicate(void)
{
	if(USART1->DR == 125)
				{
					while((USART1 -> SR & USART_SR_TXE) != USART_SR_TXE ){}
					USART1->DR = deviceID;		
					while((USART1->SR & USART_SR_TC) != USART_SR_TC){}
			}
}
void SendByte(uint8_t a)
{
	while((USART1 -> SR & USART_SR_TXE) != USART_SR_TXE ){}
	USART1->DR = a;		
	while((USART1->SR & USART_SR_TC) != USART_SR_TC){}
}
