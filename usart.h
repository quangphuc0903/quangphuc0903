#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"                  // Device header

void USART_Config(USART_TypeDef* USARTx,uint32_t baud);
void USART_SendString_(USART_TypeDef* USARTx, char *s);

#endif
