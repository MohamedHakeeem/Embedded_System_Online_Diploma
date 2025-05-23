/*
 * STM32F103X8.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_




//-----------------------------
//Includes
#include <stdio.h>
#include <stdlib.h>
//-----------------------------


//-----------------------------
//Base addresses for Memories
#define FLASH_Memory_BASE     						0x08000000UL
#define System_Memory_BASE     						0x1FFFF000UL
#define SRAM_BASE              						0x20000000UL

#define Peripherals_BASE       						0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE         0xE0000000UL
//-----------------------------

//...............................
//NVIC_Adresses
#define NVIC_BASE									0xE000E100UL
#define NVIC_ISER0       				*(volatile unsigned long *)(NVIC_BASE+ 0x000)
#define NVIC_ISER1       				*(volatile unsigned long *)(NVIC_BASE+ 0x004)
#define NVIC_ISER2       				*(volatile unsigned long *)(NVIC_BASE+ 0x008)
#define NVIC_ICER0       				*(volatile unsigned long *)(NVIC_BASE+ 0x080)
#define NVIC_ICER1       				*(volatile unsigned long *)(NVIC_BASE+ 0x084)
#define NVIC_ICER2       				*(volatile unsigned long *)(NVIC_BASE+ 0x088)






//-----------------------------
//Base addresses for BUS Peripherals
/*Base addresses for AHB Peripherals*/
#define RCC_BASE                                  (Peripherals_BASE + 0x00021000UL)



/*Base addresses for APB2  Peripherals*/

//GPIO
//A, B fully included in LQFP48 Package
#define GPIOA_BASE      (Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE      (Peripherals_BASE + 0x00010C00UL)
//C, D partial included in LQFP48 Package
#define GPIOC_BASE      (Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE      (Peripherals_BASE + 0x00011400UL)
//E, P Not  included in LQFP48 Package
#define GPIOE_BASE      (Peripherals_BASE + 0x00011800UL)


//Alternative & External Interrupt
#define AFIO_BASE      (Peripherals_BASE + 0x00010000UL)
#define EXTI_BASE      (Peripherals_BASE + 0x00010400UL)



#define USART1_BASE             (Peripherals_BASE + 0x00013800UL)
//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------
#define USART2_BASE             (Peripherals_BASE + 0x00004400UL)
#define USART3_BASE             (Peripherals_BASE + 0x00004800UL)



#define SPI1_BASE              	0x40013000UL
#define SPI2_BASE         	    0x40003800UL


//I2C
#define I2C1_BASE				0x40005400UL
#define I2C2_BASE				0x40005800UL


//..........
//-----------------------------




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypedDef;




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypedDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_TypedDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{

	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypedDef;




//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
} USART_TypeDef;



typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_TypeDef;



//========================================================
//		    Peripheral Registers : I2C
//========================================================

typedef struct
{
	volatile uint32_t CR1 ;					//Control Register 	1				(0x00)
	volatile uint32_t CR2 ;					//Control Register 	2				(0x04)
	volatile uint32_t OAR1 ;				//Own Address Register	1			(0x08)
	volatile uint32_t OAR2 ;				//Own Address Register	2			(0x0C)
	volatile uint32_t DR ;					//Data Register						(0x10)
	volatile uint32_t SR1 ;					//Status Register 1					(0x14)
	volatile uint32_t SR2 ;					//Status Register 2					(0x18)
	volatile uint32_t CCR ;					//Clock Control Register			(0x1C)
	volatile uint32_t TRISE ;				//Rise Time Register				(0x20)
}I2C_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*





//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
#define RCC     			 ((RCC_TypedDef*) RCC_BASE    )


#define GPIOA                ((GPIO_TypedDef*) GPIOA_BASE )
#define GPIOB                ((GPIO_TypedDef*) GPIOB_BASE )
#define GPIOC                ((GPIO_TypedDef*) GPIOC_BASE )
#define GPIOD                ((GPIO_TypedDef*) GPIOD_BASE )
#define GPIOE                ((GPIO_TypedDef*) GPIOE_BASE )

#define AFIO                 ((AFIO_TypedDef*) AFIO_BASE  )
#define EXTI                 ((EXTI_TypedDef*) EXTI_BASE  )

#define USART1                ((USART_TypeDef *)USART1_BASE)
#define USART2                ((USART_TypeDef *)USART2_BASE)
#define USART3                ((USART_TypeDef *)USART3_BASE)


#define SPI1				  ((SPI_TypeDef *)SPI1_BASE)
#define SPI2				  ((SPI_TypeDef *)SPI2_BASE)

#define I2C1				  ((I2C_TypeDef *)I2C1_BASE)
#define I2C2				  ((I2C_TypeDef *)I2C2_BASE)

//-*-*-*-*-*-*-*-*-*-*-*



//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:RCC_GPIO
#define GPIOA_CLOCK_ENABLE     (RCC->APB2ENR |= (1 << 2)  )
#define GPIOB_CLOCK_ENABLE     (RCC->APB2ENR |= (1 << 3)  )
#define GPIOC_CLOCK_ENABLE     (RCC->APB2ENR |= (1 << 4)  )
#define GPIOD_CLOCK_ENABLE     (RCC->APB2ENR |= (1 << 5)  )

//clock disable Macros:RCC_GPIO
#define GPIOA_CLOCK_DISABLE    (RCC->APB2ENR &= ~(1 << 2) )
#define GPIOB_CLOCK_DISABLE    (RCC->APB2ENR &= ~(1 << 3) )
#define GPIOC_CLOCK_DISABLE    (RCC->APB2ENR &= ~(1 << 4) )
#define GPIOD_CLOCK_DISABLE    (RCC->APB2ENR &= ~(1 << 5) )

//clock enable Macros:RCC_AFIO
#define AFIO_CLOCK_ENABLE      (RCC->APB2ENR |=  (1 << 0) )

//clock disable Macros:RCC_AFIO
#define AFIO_CLOCK_DISABLE     (RCC->APB2ENR &= ~(1 << 0) )


//Clock enable  Macros:USARTx.....
#define RCC_USART1_CLK_EN()	( RCC->APB2ENR |= (1<<14) )
#define RCC_USART2_CLK_EN()	( RCC->APB1ENR |= (1<<17) )
#define RCC_USART3_CLK_EN()	( RCC->APB1ENR |= (1<<18) )


//Clock disable  Macros:USARTx.....
#define RCC_USART1_CLK_DI()	( RCC->APB2ENR &= ~(1<<14) )
#define RCC_USART2_CLK_DI()	( RCC->APB1ENR &= ~(1<<17) )
#define RCC_USART3_CLK_DI()	( RCC->APB1ENR &= ~(1<<18) )


//Clock Reset  Macros:USARTx.....
#define RCC_USART1_Reset()	( RCC->APB2RSTR |= (1<<14) )
#define RCC_USART2_Reset()	( RCC->APB1RSTR |= (1<<17) )
#define RCC_USART3_Reset()	( RCC->APB1RSTR |= (1<<18) )



//Clock enable  Macros:SPIx.....
#define RCC_SPI1_CLK_EN()	(RCC->APB2ENR |= 1 << 12)
#define RCC_SPI2_CLK_EN()	(RCC->APB1ENR |= 1 << 14)

//Clock disable  Macros:SPIx.....
#define RCC_SPI1_CLK_DI()	(RCC->APB2ENR &= ~(1 << 12))
#define RCC_SPI2_CLK_DI()	(RCC->APB1ENR &= ~(1 << 14))

//Clock reset  Macros:SPIx.....
#define RCC_SPI1_RESET()	(RCC->APB2RSTR |= 1 << 12)
#define RCC_SPI2_RESET()	(RCC->APB1RSTR |= 1 << 14)


//Enable I2C Clock
#define RCC_I2C1_CLK_EN()		(RCC->APB1ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()		(RCC->APB1ENR |= 1<<22)

//Disable I2C Clock
#define RCC_I2C1_CLK_RESET()	(RCC->APB1RSTR |= 1<<21)
#define RCC_I2C2_CLK_RESET()	(RCC->APB1RSTR |= 1<<22)


//-*-*-*-*-*-*-*-*-*-*-*





//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//IVT----------EXTIx:
#define EXTI0_IRQ        0
#define EXTI1_IRQ        1
#define EXTI2_IRQ        2
#define EXTI3_IRQ        3
#define EXTI4_IRQ        4
#define EXTI5_IRQ        5
#define EXTI6_IRQ        6
#define EXTI7_IRQ        7
#define EXTI8_IRQ        8
#define EXTI9_IRQ        9
#define EXTI10_IRQ       10
#define EXTI11_IRQ       11
#define EXTI12_IRQ       12
#define EXTI13_IRQ       13
#define EXTI14_IRQ       14
#define EXTI15_IRQ       15


#define USART1_IRQ		 37
#define USART2_IRQ		 38
#define USART3_IRQ		 39




#define SPI1_IRQ		35
#define SPI2_IRQ		36



#define I2C1_EV_IRQ					31
#define I2C1_ER_IRQ					32

#define I2C2_EV_IRQ					33
#define I2C2_ER_IRQ					34




//NVIC_EXTI_IRQ_ENABLE_Define
#define NVIC_IRQ6_EXTI0_ENABLE     		       (NVIC_ISER0 |= (1 << 6))
#define NVIC_IRQ7_EXTI1_ENABLE    		       (NVIC_ISER0 |= (1 << 7))
#define NVIC_IRQ8_EXTI2_ENABLE     		       (NVIC_ISER0 |= (1 << 8))
#define NVIC_IRQ9_EXTI3_ENABLE     		       (NVIC_ISER0 |= (1 << 9))
#define NVIC_IRQ10_EXTI4_ENABLE     	       (NVIC_ISER0 |= (1 << 10))
#define NVIC_IRQ23_EXTI5_9_ENABLE    	       (NVIC_ISER0 |= (1 << 23))
#define NVIC_IRQ40_EXTI10_15_ENABLE    	       (NVIC_ISER1 |= (1 << 8)) //40-32=8

//NVIC_EXTI_IRQ_DISABLE_Define
#define NVIC_IRQ6_EXTI0_DISABLE                (NVIC_ISER0 &=  ~(1 << 6))
#define NVIC_IRQ7_EXTI1_DISABLE    		       (NVIC_ISER0 &=  ~(1 << 7))
#define NVIC_IRQ8_EXTI2_DISABLE     		   (NVIC_ISER0 &=  ~(1 << 8))
#define NVIC_IRQ9_EXTI3_DISABLE     		   (NVIC_ISER0 &=  ~(1 << 9))
#define NVIC_IRQ10_EXTI4_DISABLE     	 	   (NVIC_ISER0 &=  ~(1 << 10))
#define NVIC_IRQ23_EXTI5_9_DISABLE    	 	   (NVIC_ISER0 &=  ~(1 << 23))
#define NVIC_IRQ40_EXTI10_15_DISABLE    	   (NVIC_ISER1 &=  ~(1 << 8)) //40-32=8




//NVIC_USART_IRQ_ENABLE_Define
#define NVIC_IRQ37_USART1_Enable          	(NVIC_ISER1 |= 1<<( USART1_IRQ - 32 )) //IRQ-32
#define NVIC_IRQ38_USART2_Enable   	        (NVIC_ISER1 |= 1<<( USART2_IRQ - 32 )) //IRQ-32
#define NVIC_IRQ39_USART3_Enable   			(NVIC_ISER1 |= 1<<( USART3_IRQ - 32 )) //IRQ-32

//NVIC_USART_IRQ_DISABLE_Define
#define NVIC_IRQ37_USART1_Disable   		(NVIC_ICER1 |= 1<<( USART1_IRQ- 32 )) //IRQ-32
#define NVIC_IRQ38_USART2_Disable   		(NVIC_ICER1 |= 1<<( USART2_IRQ- 32 )) //IRQ-32
#define NVIC_IRQ39_USART3_Disable   		(NVIC_ICER1 |= 1<<( USART3_IRQ- 32 )) //IRQ-32


//NVIC_SPIx_IRQ_ENABLE_Define
#define NVIC_IRQ35_SPI1_Enable()			(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))	// SPI1
#define NVIC_IRQ36_SPI2_Enable()			(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))	// SPI2


//NVIC_SPIx_IRQ__Disable_Define
#define NVIC_IRQ35_SPI1_Disable()			(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))	// SPI1
#define NVIC_IRQ36_SPI2_Disable()			(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))	// SPI2


//NVIC_I2Cx_IRQ_Enable__Define
#define NVIC_IRQ31_I2C1_EV_Enable()			(NVIC_ISER0 |= 1<<(I2C1_EV_IRQ))
#define NVIC_IRQ32_I2C1_ER_Enable()			(NVIC_ISER1 |= 1<<(I2C1_ER_IRQ - 32))
#define NVIC_IRQ33_I2C2_EV_Enable()			(NVIC_ISER1 |= 1<<(I2C2_EV_IRQ - 32))
#define NVIC_IRQ34_I2C2_ER_Enable()			(NVIC_ISER1 |= 1<<(I2C2_ER_IRQ - 32))

//NVIC_I2Cx_IRQ_Disable__Define
#define NVIC_IRQ31_I2C1_EV_Disable()		(NVIC_ICER0 |= 1<<(I2C1_EV_IRQ))
#define NVIC_IRQ32_I2C1_ER_Disable()		(NVIC_ICER1 |= 1<<(I2C1_ER_IRQ - 32))
#define NVIC_IRQ33_I2C2_EV_Disable()		(NVIC_ICER1 |= 1<<(I2C2_EV_IRQ - 32))
#define NVIC_IRQ34_I2C2_ER_Disable()		(NVIC_ICER1 |= 1<<(I2C2_ER_IRQ - 32))






//========================================================
//========================================================
//		  			I2C Bit Definition
//========================================================
//========================================================


/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADDMODE_Pos                (15U)
#define I2C_OAR1_ADDMODE_Msk                (0x1UL << I2C_OAR1_ADDMODE_Pos)      /*!< 0x00008000 */
#define I2C_OAR1_ADDMODE                    I2C_OAR1_ADDMODE_Msk               /*!< 10-bit slave address */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */








#endif /* INC_STM32F103X6_H_ */
