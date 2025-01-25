/*
 * atmega32_timer_driver.h
 * TIMER0 [8 bits Counter]
 *  Created on: Dec 8, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INCLUDE_ATMEGA32_TIMER_DRIVER_H_
#define INCLUDE_ATMEGA32_TIMER_DRIVER_H_


/******************************************************************************
 *                               Macros 			                          *
 *******************************************************************************/

typedef unsigned char E_STATUS_t;
#define E_OK		(E_STATUS_t)(0)
#define E_NOK		(E_STATUS_t)(1)
#define NULL_PTR		((void*) (0))


typedef unsigned char* ptr_uint8_t;
typedef void(*PTR_VoidFuncVoid_t)(void);




/******************************************************************************
 *                               INCLUDES			                          *
 *******************************************************************************/
#include <ATMEGA32.h>


/******************************************************************************
 *									ENUMS	                				  *
 *******************************************************************************/
typedef enum
{
	NORMAL,
	CTC = 0x08,

}TIMER0_MODE_t;

typedef enum
{
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_t;

typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOVFIE0_t;

typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,

}TIMER0_CLOCK_t;


/******************************************************************************
 *									STRUCT	                				  *
 *******************************************************************************/
typedef struct
{
	TIMER0_MODE_t mode;
	OCMIE0_t  ocmInterrupt;
	TOVFIE0_t ovfInterrupt;
	TIMER0_CLOCK_t clk;
}STIMER0_CONFIG;


/******************************************************************************
 *									APIS				                      *
 *******************************************************************************/
E_STATUS_t MCAL_TIMER0_Init(STIMER0_CONFIG* configuartion);
E_STATUS_t MCAL_TIMER0_Stop();

E_STATUS_t MCAL_TIMER0_GetCompareValue(ptr_uint8_t pu8_TicksNumber);
E_STATUS_t MCAL_TIMER0_SetCompareValue(uint8_t u8_TicksNumber);

E_STATUS_t MCAL_TIMER0_GetCounterValue(ptr_uint8_t pu8_TicksNumber);
E_STATUS_t MCAL_TIMER0_SetCounterValue(uint8_t u8_TicksNumber);

E_STATUS_t MCAL_TIMER0_GetOverflowValue(ptr_uint8_t pu8_TicksNumber);
E_STATUS_t MCAL_TIMER0_SetOverflowValue(uint8_t u8_TicksNumber);


void MCAL_TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFuncVoid_t callback);
void MCAL_TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFuncVoid_t callback);




#endif /* INCLUDE_ATMEGA32_TIMER_DRIVER_H_ */
