#include "led.h"
#include "usart.h"
#include<stdio.h>
int main()
{
	led2_init();
	usart_init();

	while(1)
	{
//		led2_on();
//		for(int i=0;i<900000;i++){}
//		led2_off();
//		for(int i=0;i<900000;i++){}
		char *data;
		usart_receive_bytes(data);
		usart_send_bytes(data);
//		if(data == 'h')
//		{
//			led2_on();
//			for(int i=0;i<900000;i++){}
//		}
//		else
//		{
//			led2_off();
//			for(int i=0;i<900000;i++){}
//		}
//		usart_send_bytes("Hi, Hello world!\n");
//		printf("Hello from STM32F4.........\n\r");
	}
}
