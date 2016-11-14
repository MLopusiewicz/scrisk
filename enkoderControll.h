#ifndef _ENKODER_H
#define _ENKODER_H
#include <stm32f10x.h>

typedef enum
{
    true=1, false=0
}bool;

struct ENCODER
{
	int ticks;
	bool firstTick;
};

void SetUpInterrupt(void);

void ResetEncoder(struct ENCODER* a);







#endif /* _ENKODER_H */
