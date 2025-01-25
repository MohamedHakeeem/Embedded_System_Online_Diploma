/*
 * atmega32_PWM_driver.h
 * TIMER0 [8 bits Counter]
 *  Created on: Dec 8, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INCLUDE_ATMEGA32_PWM_DRIVER_H_
#define INCLUDE_ATMEGA32_PWM_DRIVER_H_

#include "ATMEGA32.h"

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
*									ENUMS	                				  *
*******************************************************************************/

typedef enum{
	FAST_PWM=0x48,
	PH_CORRECT_PWM=0x40
}PWM_MODE_T;


typedef enum{
	PWM_OCIE_DISABLE=0x00,
	PWM_OCIE_ENABLE=0x02

}PWM_OCM_T;

typedef enum{
	PWM_TOIE_DISABLE=0x00,
	PWM_TOIE_ENABLE=0x01

}PWM_OVF_T;

typedef enum{
	PWM_NO_CLCK_SOURCE,
	PWM_NO_PRESC,
	PWM_PRESC_CLCK8,
	PWM_PRESC_CLCK64,
	PWM_PRESC_CLCK256,
	PWM_PRESC_CLCK1024,
	PWM_EXTI_CLCK_FALLING,
	PWM_EXTI_CLCK_RAISING
}PWM_CLCK_T;



typedef enum
{
	PWM_INVERTING = 0x30,
	PWM_NON_INVERTING = 0x20

}PWM_STATE_T;




/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{

	PWM_MODE_T MODE;
	PWM_OCM_T OCM_INTERRUPT;
	PWM_OVF_T OVF_INTERRUPT;
	PWM_CLCK_T CLCK;
	PWM_STATE_T STATE;

}PWM_CONFIG_T;



/******************************************************************************************************
*									APIS				                      *
********************************************************************************************************/

E_STATUS_t MCAL_PWM_INIT(PWM_CONFIG_T* CONFIG);
E_STATUS_t MCAL_PWM_STOP();

E_STATUS_t MCAL_PWM_GET_CMP_VALUE(ptr_uint8_t P_TICKS);		//COMPARE VALUE
E_STATUS_t MCAL_PWM_SET_CMP_VALUE(uint8_t TICKS);

E_STATUS_t MCAL_PWM_GET_COUNTER_VALUE(ptr_uint8_t P_TICKS);	//COUNTER VALUE
E_STATUS_t MCAL_PWM_SET_COUNTER_VALUE(uint8_t TICKS);

E_STATUS_t MCAL_PWM_GET_OVF_VALUE(ptr_uint8_t P_TICKS);		//OVERFLOW VALUE
E_STATUS_t MCAL_PWM_SET_OVF_VALUE(uint8_t TICKS);

void MCAL_PWM_SETCALLBACK_OVF_INTERRUPT(PTR_VoidFuncVoid_t CALLBACK);
void MCAL_PWM_SETCALLBACK_CMP_INTERRUPT(PTR_VoidFuncVoid_t CALLBACK);


#endif /* INCLUDE_ATMEGA32_PWM_DRIVER_H_ */
