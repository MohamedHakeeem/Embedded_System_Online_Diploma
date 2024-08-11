/*learn-in-depth unit3_lesson4-lab3 
  Mohamed Abd El Hakeem EL Said Ali.
  linker_script.ld  on Tivec_Board 
*/ 

MEMORY
{
	
		flash(RX) : ORIGIN = 0x00000000, LENGTH = 128K
		sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K

}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		E_text = . ;
	} > flash

	.data : 
	{
		S_data = . ;
		*(.data)
		. = ALIGN(4) ;
		E_data = . ;

	} > sram AT> flash

	.bss :
	 {
		
		S_bss = . ;
		*(.bss*) 
		E_bss = . ;
		

		} > sram
}