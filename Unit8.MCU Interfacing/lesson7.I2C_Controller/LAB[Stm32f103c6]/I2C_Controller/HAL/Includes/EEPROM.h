/*
 * EEPROM.h
 *
 *  Created on: Dec 4, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali
 */

#ifndef INCLUDES_EEPROM_H_
#define INCLUDES_EEPROM_H_




//========================================================
//						INCLUDES
//========================================================

#include "stm32f103x8_i2c_driver.h"

//EEPROM is an I2C SLAVE
//IDLE MODE : Device is in High-impedance state and waits for data
//Master Transmitter Mode : The device Transmits data to a slave Receiver
//Master Receiver Mode : the device Receives data from a slave Transmitter

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

#define EEPROM_SLAVE_ADDRESS					0x2A



//========================================================
//		APIs Supported by "HAL EEPROM DRIVER"
//========================================================

void HAL_EEPROM_Init(void);
uint8_t HAL_EEPROM_Write_NBytes (uint32_t Memory_Address , uint8_t* Bytes , uint8_t Data_Length);
uint8_t HAL_EEPROM_Read_NBytes (uint32_t Memory_Address , uint8_t* Bytes , uint8_t Data_Length);









#endif /* INCLUDES_EEPROM_H_ */
