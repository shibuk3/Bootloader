#ifndef __USART_H__
#define __USART_H__
#include "stm32f4xx.h"

void usart_init();
void usart_send_char(char data);
void usart_send_bytes(char data[]);
void usart_receive_char(char *data);
void usart_receive_bytes(char *data[]);

#endif


