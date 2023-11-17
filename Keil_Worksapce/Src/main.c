#include<stdio.h>
#include<string.h>
#include "led.h"
#include "usart.h"

int main()
{
	led2_init();
	usart_init();
	while(1)
	{
		led2_on();
		for(int i=0;i<90000;i++){}
		led2_off();
		for(int j=0;j<90000;j++){}
		uint8_t payLoad[100];
		memset(payLoad,0,sizeof(payLoad));
		sprintf(payLoad,"Hi, Welcome to the Application !\r\n");
		usart_send_bytes(payLoad,sizeof(payLoad));
	}
	return 0;
}