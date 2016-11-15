#ifndef _ENKODER_H
#define _ENKODER_H

#define E1_nB GPIO_IDR_IDR1 //stan wysoki na lini ~B enkodera 1
#define E1_B 	GPIO_IDR_IDR2	// analogicznie ... 
#define E1_nA GPIO_IDR_IDR3
#define E1_A 	GPIO_IDR_IDR4

#define E2_nB GPIO_IDR_IDR8
#define E2_B 	GPIO_IDR_IDR7
#define E2_nA GPIO_IDR_IDR6
#define E2_A 	GPIO_IDR_IDR5

#include <stm32f10x.h>


typedef enum
{
    true=1, false=0
}bool;

struct ENCODER
{
	int ticks;
	int misstakes;
};

void SetUpInterrupt(void);

void ResetEncoder(struct ENCODER* a);




/*
enkoder #1
	PA1 - ~B
	PA2 -  B
	PA3 - ~A
	PA4 -	 A

enkoder #2
	PA8 - ~B
	PA7 -	 B
	PA6	- ~A
	PA5	-	 A
*/




#endif /* _ENKODER_H */
