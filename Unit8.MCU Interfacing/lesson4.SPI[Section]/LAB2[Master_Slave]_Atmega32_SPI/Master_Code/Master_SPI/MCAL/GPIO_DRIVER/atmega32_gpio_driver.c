/*
 * atmega32_gpio_driver.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */


#include <atmega32_gpio_driver.h>



/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 **/


/**================================================================
 * @Fn-MCAL_GPIO_Init
 * @brief -In this Func, You can Initialize All Configuration  of any PinNumber
 * @param [in] - Pointer of GPIOx ,
 * @param [in] -Address of the PinConfig------->>>>(as &PinConfig..)
 * @retval -Not
 * Note-You must Create Instant from "GPIO_PinConfig_t" Structure,
 * Before using This func "MCAL_GPIO_Init" and pass it to @param [in] -Address of the PinConfig
 */

void MCAL_GPIO_Init(GPIO_TypedDef* GPIOx, GPIO_PinConfig_t* PinConfig )
{


	if(PinConfig->GPIO_Mode == GPIO_Mode_Inp_Floating)
	{
		 GPIOx->DDR &= ~  PinConfig->GPIO_PinNumber ;
	}
	else if(PinConfig->GPIO_Mode == GPIO_Mode_Inp_pull_up)
	{

		 GPIOx->DDR  &= ~ PinConfig->GPIO_PinNumber ;
		 GPIOx->PORT |=   PinConfig->GPIO_PinNumber ;

	}
	else if(PinConfig->GPIO_Mode == GPIO_Mode_Out_push_pull)
	{
		 GPIOx->DDR |=   PinConfig->GPIO_PinNumber ;

	}
	else
	{
		//Do Nothing
	}

}



/**================================================================
 * @Fn-MCAL_GPIO_DInit
 * @brief -In This Func, You can Reset All Configuration  of The Selected Portx
 * @param [in] - Pointer of GPIOx ,
 * @retval -Not
 * Note-..........................................................
 */
void MCAL_GPIO_DInit(GPIO_TypedDef* GPIOx)
{
		GPIOx->DDR=0x00;
		GPIOx->PORT=0x00;
}




/**================================================================
 * @Fn-MCAL_GPIO_ReadPin
 * @brief -In This Func, You can Read state  of The Selected pin
 * @param [in] - Pointer of GPIOx ,
 * @param [in] - PinNumber >>>>>> based on @ref GPIO_PINS_Define in header of gpio,
 * @retval -State of Pin, 0 or 1
 * Note-..........................................................
 */
uint8_t  MCAL_GPIO_ReadPin(GPIO_TypedDef* GPIOx,uint8_t PinNumber)
{
	if((GPIOx->PIN & PinNumber) != (uint32_t)GPIO_PIN_RESET ) return (uint8_t)GPIO_PIN_SET;
	else return (uint8_t)GPIO_PIN_RESET;

}


/**================================================================
 * @Fn-MCAL_GPIO_ReadPort
 * @brief -In This Func, You can Read All Portx
 * @param [in] - Pointer of GPIOx ,
 * @retval -16bits of selected port.
 * Note-..........................................................
 */
uint8_t MCAL_GPIO_ReadPort(GPIO_TypedDef* GPIOx)
{
	return (uint8_t)(GPIOx->PIN);
}



/**================================================================
 * @Fn-MCAL_GPIO_WritePin
 * @brief -In This Func, You can Write in any PinNumber of the selected port
 * @param [in] - Pointer of GPIOx ,
 * @param [in] - PinNumber >>>>>> based on @ref GPIO_PINS_Define in header of gpio,
 * @param [in] - Set "Value" which is 0 or 1,
 * @retval -NOT......
 * Note-..........................................................
 */
void MCAL_GPIO_WritePin(GPIO_TypedDef* GPIOx,uint8_t PinNumber , uint8_t Value)
{

	if(Value == (uint8_t) GPIO_PIN_SET)
	{
		GPIOx->PORT |= (uint8_t)PinNumber;
	}

	else
	{
		GPIOx->PORT &= ~(uint8_t)(PinNumber);
	}
}



/**================================================================
 * @Fn-MCAL_GPIO_WritePort
 * @brief -In This Func, You can write All The Selected Portx.
 * @param [in] - Pointer of GPIOx ,
 * @param [in] - Value ,
 * @retval -Not
 * Note-..........................................................
 */
void MCAL_GPIO_WritePort(GPIO_TypedDef* GPIOx, uint8_t Value)
{

	GPIOx->PORT = (uint8_t)Value;


}



/**================================================================
 * @Fn-MCAL_GPIO_TogglePin
 * @brief -In This Func, You can Toggle the selected pin of the port.
 * @param [in] - Pointer of GPIOx ,
 * @param [in] - PinNumber >>>>>> based on @ref GPIO_PINS_Define in header of gpio,
 * @retval -Not
 * Note-..........................................................
 */
void MCAL_GPIO_TogglePin(GPIO_TypedDef* GPIOx,uint8_t PinNumber)
{
	GPIOx->PORT ^= (uint8_t)PinNumber;
}


