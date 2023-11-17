#include "led.h"
#include "usart.h"
#include "gpio.h"
#include<stdio.h>
#include<string.h>
//#define BL_RX_LEN  200
//uint8_t bl_rx_buffer2[BL_RX_LEN];
//int main()
//{
//	led2_init();
//	usart_init();
//	uint8_t rcv_len=0;
//	while(1)
//	{
//		gpio_init();
//		led2_on();
//		for(int i=0;i<900000;i++){}
//		led2_off();
//		for(int i=0;i<900000;i++){}
//		memset(bl_rx_buffer2,0,200);
//		//here we will read and decode the commands coming from host
//		//first read only one byte from the host , which is the "length" field of the command packet
//		usart_receive_bytes(bl_rx_buffer2,2);
//		usart_send_bytes(bl_rx_buffer2,2);
//		rcv_len= bl_rx_buffer2[0]-'0';
//		usart_receive_bytes(&bl_rx_buffer2[2],rcv_len+1);
//		usart_send_bytes(bl_rx_buffer2+2,2);
//		uint8_t payLoad[100];
//		memset(payLoad,0,100);
//		sprintf(payLoad,"BL_DEBUG_MSG:command code received from host:%d %d%d \r\n" , bl_rx_buffer2[0], bl_rx_buffer2[2],bl_rx_buffer2[3]);
//	    usart_send_bytes(payLoad,sizeof(payLoad));
//		uint8_t data[50];
//		uint8_t length = 2;
//		usart_receive_bytes(data,length);
//		usart_send_bytes(data,length);
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
//		uint8_t payLoad[100];
//		memset(payLoad,0,sizeof(payLoad));
//		sprintf(payLoad,"Hi, Hello world %d !\r\n",20);
//		//uint8_t payLoad[] = "Hi, Hello world" +20+"!\r\n";
//		usart_send_bytes(payLoad,sizeof(payLoad));
//		printf("Hello from STM32F4.........\n\r");
//	}
//}


int main()
{
	gpio_init();
	led2_init();
	usart_init();
	uint8_t payLoad[100];
	while(1)
	{
	  if ( isButtonPressed() == 0 )
	  {
		  sprintf(payLoad,"BL_DEBUG_MSG:Button is pressed .. going to BL mode\n\r") ;
		  usart_send_bytes(payLoad,sizeof(payLoad));
		  //we should continue in bootloader mode
		  bootloader_uart_read_data();

	  }
	  else
	  {
		  sprintf(payLoad,"BL_DEBUG_MSG:Button is not pressed .. executing user app\n" );
		  usart_send_bytes(payLoad,sizeof(payLoad));
			//jump to user application
			bootloader_jump_to_user_app();

	  }
	}
}

