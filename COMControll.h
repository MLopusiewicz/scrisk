#ifndef _COMControl_H
#define _COMControl_H

#define validationRequest 125
#define deviceID 160
#define resetEncoders 212
#define ticksRequest 230
#define misstakeRequest 45
#include <stm32f10x.h>


void USARTInit(void);

void SendByte(uint8_t a);
void SendInt(int a, int bytesAmount);

#endif /* _COMControl_H */
