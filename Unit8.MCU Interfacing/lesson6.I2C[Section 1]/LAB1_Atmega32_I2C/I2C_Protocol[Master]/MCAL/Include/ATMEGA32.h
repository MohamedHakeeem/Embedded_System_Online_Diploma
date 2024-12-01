/*
 * ATMEGA32.h
 *
 *  Created on: Nov 1, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INC_ATMEGA32_H_
#define INC_ATMEGA32_H_


//-----------------------------
//Includes
#include <stdio.h>
#include <stdlib.h>
//-----------------------------


//-----------------------------
//Base addresses for Memories
#define FLASH_Memory_BASE     						0x0000
#define SRAM_BASE              						0x0060
//-----------------------------

//...............................
//Interrupt_Adresseses
#define SREG						        	   *(volatile unsigned char *)(0x5F)
#define GICR						        	   *(volatile unsigned char *)(0x5B)
#define GIFR       				           		   *(volatile unsigned long *)(0x5A)
#define MCUCR       				        	   *(volatile unsigned long *)(0x55)
#define MCUCSR       				        	   *(volatile unsigned long *)(0x54)

//---------------------------


//GPIO
//A, B fully included in LQFP48 Package
#define GPIOA_BASE      (0x39)
#define GPIOB_BASE      (0x36)
//C, D partial included in LQFP48 Package
#define GPIOC_BASE      (0x33)
#define GPIOD_BASE      (0x30)

//For Disable Pull Up  in All Ports
#define SFIOR      (*(volatile unsigned char *)(0x50)))


//UART
//UART
#define USART_BASE					(0x29)

//Hint:This Registers have the same location
#define UCSRC_BASE					(0x40)
#define UBRRH_BASE					(0x40)


 //SPI
#define SPI_BASE                    (0x2D)

//I2C[Two Wire Interface]
#define I2C_BASE                    (0x20)
#define I2C_TWCR                   (*(volatile unsigned char *)(0x56))


//..........
//-----------------------------



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
}GPIO_TypedDef;




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Registers : USART
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint8_t UBRRL;
	volatile uint8_t UCSRB;
	volatile uint8_t UCSRA;
	volatile uint8_t UDR;
}USART_TypeDef;




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Registers :SPI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint8_t SPCR;
	volatile uint8_t SPSR;
	volatile uint8_t SPDR;
}SPI_TypeDef;





//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Registers :I2C
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint8_t TWBR;
	volatile uint8_t TWSR;
	volatile uint8_t TWAR;
	volatile uint8_t TWDR;
}I2C_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:

//GPIO
#define GPIOA                	((GPIO_TypedDef*) GPIOA_BASE )
#define GPIOB                	((GPIO_TypedDef*) GPIOB_BASE )
#define GPIOC                	((GPIO_TypedDef*) GPIOC_BASE )
#define GPIOD                	((GPIO_TypedDef*) GPIOD_BASE )



//USART
#define USART					((USART_TypeDef*)USART_BASE)

#define UCSRC					*((volatile uint8_t*)UCSRC_BASE)
#define UBRRH					*((volatile uint8_t*)UBRRH_BASE)


//SPI
#define SPI                     ((SPI_TypeDef*)SPI_BASE)


//I2C
#define I2C                     ((I2C_TypeDef*)I2C_BASE)


//-*-*-*-*-*-*-*-*-*-*-*






//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//IVT----------EXTIx:
#define INT0_ISR        6           // -->>>>>>>>> in IVT 2
#define INT1_ISR        7			// -->>>>>>>>> in IVT 3
#define INT2_ISR        5			// -->>>>>>>>> in IVT 4




#define ENABLE_GLOBAL_INTERRUPT()				SREG  |=   (1 << 7)
#define DISABLE_GLOBAL_INTERRUPT()				SREG  &=  ~(1 << 7)
#define DISABLE_PULL_UP_ALL_PORTS()             SFIOR |=   (1 << 2)
#define ENABLE_PULL_UP_ALL_PORTS()              SFIOR &=  ~(1 << 2)




#endif /* INC_ATMEGA32_H_ */
