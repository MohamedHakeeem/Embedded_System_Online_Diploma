/*learn-in-depth unit3_lesson3-lab2 part1
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
	} > flash

	.data : 
	{
		*(.data)
	} > flash

	.bss :
	 {
		
		*(.bss*) 

		} > sram
}