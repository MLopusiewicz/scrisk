#ifndef _COMControl_H
#define _COMControl_H

#define validationRequest 125
#define deviceID 160
#define ForceTickValueRequest 167

#include <stm32f10x.h>


void USARTInit(void);
void Autenthicate(void);
void SendByte(uint8_t a);
void SendInt(int a);

#endif /* _COMControl_H */
