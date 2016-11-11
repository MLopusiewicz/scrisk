#ifndef _COMControl_H
#define _COMControl_H

#include <stm32f10x.h>

void USARTInit(void);
void Autenthicate(void);
void SendByte(uint8_t a);


#endif /* _COMControl_H */
