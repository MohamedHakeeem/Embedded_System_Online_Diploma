/*
 * stm32f103x6_rcc_driver.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INC_STM32F103X6_RCC_DRIVER_H_
#define INC_STM32F103X6_RCC_DRIVER_H_


//includes
#include "STM32F103X6.h"



#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);







#endif /* INC_STM32F103X6_RCC_DRIVER_H_ */