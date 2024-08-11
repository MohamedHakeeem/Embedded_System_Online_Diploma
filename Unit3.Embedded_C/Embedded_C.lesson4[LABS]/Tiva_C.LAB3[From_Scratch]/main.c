/* 
"Toggle_Led" From Scratch on Board "TM4C123"  "Cortex_M4"
 Mohamed_Hakeem 
*/

#include <stdint.h>
#include "Platform_Types.h"

#define SYSCTL_RCGC2_R			*(vuint32*)(0x400FE108)
#define GPIO_PORTF_DIR_R   		*(vuint32*)(0x40025400)
#define GPIOA_PORTF_DEN_R   	*(vuint32*)(0x4002551C)
#define GPIOA_PORTF_DATA_R   	*(vuint32*)(0x400253FC)


int main(void)
{
	vuint32 i;

	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIOF is up and running
	for(i=0;i<100;i++);
	// Set Direction Register to be Output for Pin 3 PortF
	GPIO_PORTF_DIR_R  |= (1 << 3);	 
	GPIOA_PORTF_DEN_R |= (1 << 3);	 

	while(1)
	{
		GPIOA_PORTF_DATA_R |= (1 << 3);
		for(i=0;i<200000;i++);
		GPIOA_PORTF_DATA_R &= ~(1 << 3);
		for(i=0;i<200000;i++);

	}


	return 0;
}
