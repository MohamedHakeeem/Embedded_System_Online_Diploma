/*
 * EEPROM.h
 * M95080 STM....................................
 *  Created on: Jan 13, 2025
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INCLUDE_EEPROM_H_
#define INCLUDE_EEPROM_H_





#include "stm32f103x6_spi_driver.h"
#include "stm32f103x6_gpio_driver.h"


//Instruction set....................
#define Read_EEPROM                  (uint8_t)(0x03)
#define Write_EEPROM                 (uint8_t)(0x02)
#define WRDI_Disable_EEPROM          (uint8_t)(0x04)
#define WREN_Enable_EEPROM           (uint8_t)(0x06)
#define RDSR_Status_EEPROM           (uint8_t)(0x05)
#define WRSR_Status_EEPROM           (uint8_t)(0x01)




//Addresses of Memory
#define Address_begin            (uint16_t)(0x0000)
#define Address_end              (uint16_t)(0x03FF)




void EEPROM_SPI_INTT(SPI_TypeDef* SPIx);
void EEPROM_NSS_INIT(GPIO_TypedDef* GPIOx,uint16_t PinNumber);
void EEPROM_READ(SPI_TypeDef* SPIx,GPIO_TypedDef*GPIOx,uint16_t PinNumber,uint8_t* E2RBuffer,uint16_t Address);
void EEPROM_READSEQUENCE(SPI_TypeDef* SPIx,GPIO_TypedDef*GPIOx,uint16_t PinNumber,uint8_t* E2RBuffer,uint16_t Address,uint8_t Data_Length);
void EEPROM_WRITESEQUENCE(SPI_TypeDef* SPIx,GPIO_TypedDef*GPIOx,uint16_t PinNumber,uint8_t* E2TBuffer,uint16_t Address,uint8_t Data_Length);
void EEPROM_Erase(SPI_TypeDef* SPIx, GPIO_TypedDef* GPIOx, uint16_t PinNumber);



#endif /* INCLUDE_EEPROM_H_ */
