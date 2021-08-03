/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		GPIO					************************/
/***************	@TITLE:		GPIO_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/************************************************************
*				 	Header Files Inclusion					*
************************************************************/
#include "Std_Types.h"
#include "STM32F401XX.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"



/************************************************************
*				 	Global variables						*
************************************************************/
static GPIO_RegDef_t *GPIO_u8PortArr[6] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH};

/************************************************************
*				 	GPIO PIN INIT							*
************************************************************/
/*********************************************************
 *	@Function Name:		GPIO_voidPinInit
 *
 *	@Description:		The function initialize the required pin configuration options
 *
 *	@Parameters:  1- Copy_pPinCfg_t => pointer to GPIO_PinCfg_t structure which hold the configurations
 *
 *	@Return: 			ErrorState
 *
 ********************************************************/
u8 GPIO_voidPinInit(const GPIO_PinCfg_t* Copy_pPinCfg_t) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pPinCfg_t == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if ((Copy_pPinCfg_t->Port > GPIO_PORTH) || (Copy_pPinCfg_t->PinNumber > GPIO_PIN15)) {
		Local_u8ErrorState = NOK;
	}
	else {
		/*1- Set the mode configuration*/
		GPIO_u8PortArr[Copy_pPinCfg_t->Port]->MODER &= ~(MODE_BIT_MASK << (Copy_pPinCfg_t->PinNumber * 2)); /*Clear the mode bits*/
		GPIO_u8PortArr[Copy_pPinCfg_t->Port]->MODER |= (Copy_pPinCfg_t->Mode << (Copy_pPinCfg_t->PinNumber * 2));

		/*2- Set Pull-up / Pull-down configuration*/
		GPIO_u8PortArr[Copy_pPinCfg_t->Port]->PUPDR &= ~(PULL_UP_DOWN_MASK << (Copy_pPinCfg_t->PinNumber * 2));
		GPIO_u8PortArr[Copy_pPinCfg_t->Port]->PUPDR |= (Copy_pPinCfg_t->PullUpDown << (Copy_pPinCfg_t->PinNumber * 2));

		/*3- Set Output type, output speed in case of output mode */
		if (Copy_pPinCfg_t->Mode == GPIO_MODE_OUTPUT) {
			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->OSPEEDR &= ~(SPEED_BIT_MASK << (Copy_pPinCfg_t->PinNumber * 2));
			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->OSPEEDR |= (Copy_pPinCfg_t->OutputSpeed << (Copy_pPinCfg_t->PinNumber * 2));

			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->OTYPER &= ~(OUTPUT_TYPE_MASK << (Copy_pPinCfg_t->PinNumber));
			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->OTYPER |= (Copy_pPinCfg_t->OutputType << (Copy_pPinCfg_t->PinNumber));

		}
		/*4- Set the alternate function option in case of alternate function mode*/
		else if (Copy_pPinCfg_t->Mode == GPIO_MODE_ALT_FUNC) {
			u8 Local_u8RegisterNumber = (Copy_pPinCfg_t->PinNumber / 8);
			u8 Local_u8PinNumber = (Copy_pPinCfg_t->PinNumber % 8);

			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->AFR[Local_u8RegisterNumber] &= ~(ALT_FUNC_MASK << (Local_u8PinNumber * 4));
			GPIO_u8PortArr[Copy_pPinCfg_t->Port]->AFR[Local_u8RegisterNumber] |= (Copy_pPinCfg_t->AltFunc << (Local_u8PinNumber * 4));
		}
	}
	return Local_u8ErrorState;
}
/*******************************************************************************/




/************************************************************
*				 	GPIO SET PIN VALUE						*
************************************************************/
/*********************************************************
 *	@Function Name:		GPIO_u8SetPinValue
 *
 *	@Description:		The function sets an output value on the output pin
 *
 *	@Parameters:  1- Copy_port:		The port of the required pin
 *				  2- Copy_u8Pin:	the number of the pin in the port
 *				  3- Copy_u8Value:	The required pin state
 *
 *	@Return: 			ErrorState
 *
 ********************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8port <= GPIO_PORTH) && (Copy_u8Pin <= GPIO_PIN15)) {
		if (Copy_u8Value == GPIO_PIN_HIGH) {
			GPIO_u8PortArr[Copy_u8port]->ODR |= 1 << Copy_u8Pin;
		}
		else if (Copy_u8Value == GPIO_PIN_LOW) {
			GPIO_u8PortArr[Copy_u8port]->ODR &= ~(1 << Copy_u8Pin);
		}
		else {
			Local_u8ErrorState = NOK;
		}
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/*******************************************************************************/


/************************************************************
*				 	GPIO SET port VALUE						*
************************************************************/
/*********************************************************
 *	@Function Name:		GPIO_u8SetPortValue
 *
 *	@Description:		The function set an output value on the output port
 *
 *	@Parameters:  1- Copy_port:		The port
 *				  2- Copy_u16Value:	The required value to set the port
 *
 *	@Return: 			ErrorState
 *
 ********************************************************/
u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16Value) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8Port <= GPIO_PORTH) && (Copy_u16Value <= GPIO_PORT_HIGH)) {
		GPIO_u8PortArr[Copy_u8Port]->ODR &= Copy_u16Value;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
/*******************************************************************************/




/************************************************************
*				 	GPIO Read Pin VALUE						*
************************************************************/
/*********************************************************
 *	@Function Name:		GPIO_u8ReadPinValue
 *
 *	@Description:		The function Read the state of the required pin
 *
 *	@Parameters:  1- Copy_port:		The port of the required pin
 *				  2- Copy_u8Pin:	the number of the pin in the port
 *				  3- Copy_pu8Value:	Pointer to u8 variable to pass the state of the pin
 *
 *	@Return: 			ErrorState
 *
 ********************************************************/
u8 GPIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8Port > GPIO_PORTH) || (Copy_u8Pin > GPIO_PIN15)) {
		Local_u8ErrorState = NOK;
	}
	else if (Copy_pu8Value == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {
		*Copy_pu8Value = (u8)((GPIO_u8PortArr[Copy_u8Port]->IDR >> Copy_u8Pin) & 1 );
	}

	return Local_u8ErrorState;
}
/*******************************************************************************/



/************************************************************
*				 	GPIO Toggle Pin VALUE						*
************************************************************/
/*********************************************************
 *	@Function Name:		GPIO_u8TogglePinValue
 *
 *	@Description:		The function Toggle the state of the required pin
 *
 *	@Parameters:  1- Copy_port:		The port of the required pin
 *				  2- Copy_u8Pin:	the number of the pin in the port
 *
 *	@Return: 			ErrorState
 *
 ********************************************************/
u8 GPIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8Port <= GPIO_PORTH) && (Copy_u8Pin <= GPIO_PIN15)) {
		GPIO_u8PortArr[Copy_u8Port]->ODR ^= (1 << Copy_u8Pin);
	}
	else {
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
/*******************************************************************************/


/************************************************************
*				 	END OF FILE								*
************************************************************/

