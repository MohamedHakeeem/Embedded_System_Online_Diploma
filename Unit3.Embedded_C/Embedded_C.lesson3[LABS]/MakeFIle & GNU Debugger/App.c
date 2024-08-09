#include "Uart.h"

unsigned char String_Buffer[100]="Mohamed_Hakeem_El_Said----In--> Online_Diploma ";
void main(void)
{

	Uart_Send_String(String_Buffer);
}