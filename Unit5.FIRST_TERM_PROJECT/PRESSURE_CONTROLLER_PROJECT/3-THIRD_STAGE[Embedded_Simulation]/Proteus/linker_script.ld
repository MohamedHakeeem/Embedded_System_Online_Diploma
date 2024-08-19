/*learn-in-depth 
  Mohamed Abd El Hakeem EL Said Ali.
  linker_script.ld
*/ 

MEMORY
{
	
		flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
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
		E_data = . ;

	} > sram AT> flash

	.bss :
	 {
		
		S_bss = . ;
		*(.bss*) 
		E_bss = . ;
		. = . + 0x1000;
		Stack_Top = . ;
	

		} > sram
}