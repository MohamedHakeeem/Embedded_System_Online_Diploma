#Copyright: Mohamed Abd El Hakeem El Said El Ali .
CC=arm-none-eabi-
CFLAGES= -gdwarf-2 -g -mcpu=cortex-m4 -mthumb   #gdwarf-2 is defined to protuse debugger  & -mthumb to operate on my  target cpu
INCS=-I .          	        #Add Paths of Header Files ---> . mean same folder.
LIBS=						#for including static library 'files.a' or'files.lib' in Linking time.
SRC=$(wildcard *.c)			#wildcard searchd any files.c   in the folder.
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)			#wildcard searchd any files.s   in the folder.
ASOBJ=$(AS:.s=.o)
Project_Name=Toggle_Led_TivaC

all:$(Project_Name).bin
	@echo  "==============Build is Done================="

%.o:%.s
	$(CC)as.exe  $(CFLAGES)  $< -o $@

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGES) $(INCS)  $< -o $@

$(Project_Name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe  -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Mapfile.map
	cp $(Project_Name).elf $(Project_Name).axf                            #.axf  Keil u vision  understands it

$(Project_Name).bin:$(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@


clear_all:
	rm *.o *.elf *.bin *.map *.axf

clear:
	rm *.elf *.bin *.map *.axf