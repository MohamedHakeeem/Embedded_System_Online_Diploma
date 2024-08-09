/* 
"Toggle_Led" From Scratch on Board "STM32F103C8T6"  "Cortex_M3"
 Mohamed_Hakeem ------> 9/8/2024
*/

#include <stdint.h>
#include "Platform_Types.h"

//Access to RCC Register
#define RCC_BASE  0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR	*(vuint32*)(RCC_BASE+0x18)
#define GPIOA_CRH   *(vuint32*)(PORTA_BASE+0x04)
#define GPIOA_ODR   *(vuint32*)(PORTA_BASE+0x0C)


typedef union
{
	vuint32 All_Pins;
	struct
	{
		vuint32 reserved:13;
		vuint32 Pin13:1;

	}Pin;

}Bit_Select;

volatile Bit_Select* ODR_Bit=(volatile Bit_Select*)(PORTA_BASE+0x0C);
vuint8 Date[]="9/8/2024" ;
const uint8 name[3]={100,200,30};
vuint16 Dumy;


int main(void)
{

	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH  &=0xFF0FFFFF;
	GPIOA_CRH  |=0x00200000;
	int i;
	while(1)
	{
		ODR_Bit->Pin.Pin13=1;
		for(i=0;i<50000;i++);
		ODR_Bit->Pin.Pin13=0;
		for( i=0;i<50000;i++);

	}


	return 0;
}
