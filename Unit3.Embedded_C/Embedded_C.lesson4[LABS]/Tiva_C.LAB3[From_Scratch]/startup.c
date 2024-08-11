/*learn-in-depth unit3_lesson3-lab2 part1
  Mohamed Abd El Hakeem EL Said Ali.
  startup.c
  */ 

/*SRAM 0x20000000 */


#include<stdint.h>
#include"Platform_Types.h"
extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);


void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Hard_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));

//256 element ----> 1024 Byte  unintialized array is stored in section (.bss) with zero in SRAM  
/*Now I don't need to  add storage class "EXTERN" to Stack_top,
*because it is defined in another method inside startup file ,
*you should element it from linker_script
*/
static uint32 Stack_Top[256];

/*uint32 Vectors[] __attribute__((section(".vectors")))={
(uint32) &Stack_Top,
(uint32) &Reset_Handler,
(uint32) &NMI_Handler,
(uint32) &Hard_Fault_Handler,
(uint32) &MM_Fault_Handler,
(uint32) &Bus_Fault_Handler,
(uint32) &Usage_Fault_Handler,
};*/


/* ^^^^^^^^^______Another Complex Method.......SORRY______^^^^^^^^^^^  */
/*--Array of const Pointer to function takes nothing and return void --*/ 
void (*const Vector_ptr[])() __attribute__((section(".vectors")))=
{
	(void(*)()) (Stack_Top+sizeof(Stack_Top)),
	&Reset_Handler,
	&NMI_Handler,
	&Hard_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler,


};

/*----------------------------------------------------------------------*/ 

extern uint32 E_text;
extern uint32 S_data;
extern uint32 E_data;
extern uint32 S_bss;
extern uint32 E_bss;
uint32 i;

void Reset_Handler(void)
{
	//Copy data section from flash to ram
	uint32 Data_Size=(uint8*)&E_data-(uint8*)&S_data;
	uint8* Ptr_Src=(uint8*)&E_text;
	uint8* Ptr_Dst=(uint8*)&S_data;


	for(i=0;i<Data_Size;i++)
	{

		*((uint8*)Ptr_Dst++)=*((uint8*)Ptr_Src++);
	}

  //Initialization bss section in SRAM with Zero
	uint32 bss_Size=(uint8*)&E_bss-(uint8*)&S_bss;
	Ptr_Dst=(uint8*)&S_bss;


	for(i=0;i<Data_Size;i++)
	{

		*((uint8*)Ptr_Dst++)=((uint8) 0 );
	}

	main();

}

void Default_Handler(void)
{
	Reset_Handler();
}