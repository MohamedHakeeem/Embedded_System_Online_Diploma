#Copyright: Mohamed Abd El Hakeem El Said El Ali .
CC=arm-none-eabi-
CFLAGES=-g -mcpu=arm926ej-s
INCS=-I .          	        #Add Paths of Header Files ---> . mean same folder.
LIBS=						#for including static library 'files.a' or'files.lib' in Linking time.
SRC=$(wildcard *.c)			#wildcard searchd any files.c   in the folder.
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)			#wildcard searchd any files.s   in the folder.
ASOBJ=$(AS:.s=.o)
Project_Name=learn_in_depth

all:$(Project_Name).bin
	@echo  "==============Build is Done================="

Startup.o:Startup.s
	$(CC)as.exe  $(CFLAGES)  $< -o $@

%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGES)  $< -o $@

$(Project_Name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe  -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@

$(Project_Name).bin:$(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@


clear_all:
	rm *.o *.elf *.bin  

clear:
	rm *.elf  *.bin