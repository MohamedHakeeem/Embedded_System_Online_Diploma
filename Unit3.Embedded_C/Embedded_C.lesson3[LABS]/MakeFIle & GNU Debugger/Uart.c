#include "Uart.h"


#define UART0DR   *(volatile unsigned int*)((unsigned int *)0x101f1000)

void Uart_Send_String(unsigned char* Ptr_String)
{

	if(Ptr_String!=0)
	{	while(*Ptr_String != '\0')
		{
			UART0DR = (unsigned int )*Ptr_String;
			Ptr_String++;
		}

	}


}
