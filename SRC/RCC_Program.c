/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		RCC						************************/
/***************	@TITLE:		RCC_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/************************************************************
*				 	Header Files Inclusion					*
************************************************************/
#include "Std_Types.h"
#include "STM32F401XX.h"
#include "RCC_Interface.h"
/************************************************************
*			AHB1 Enable/Disable peripheral clock	 		*
************************************************************/
u8 RCC_voidAHB1SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8State == RCC_DISABLE_CLOCK) {
		RCC->AHB1ENR &= ~(ONE_BIT_MASK << Copy_u8Peripheral);
	}
	else if (Copy_u8State == RCC_ENABLE_CLOCK) {
		RCC->AHB1ENR |= ONE_BIT_MASK << Copy_u8Peripheral;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/************************************************************
*			AHB2 Enable/Disable peripheral clock	 		*
************************************************************/
u8 RCC_voidAHB2SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8State == RCC_DISABLE_CLOCK) {
		RCC->AHB2ENR &= ~(ONE_BIT_MASK << Copy_u8Peripheral);
	}
	else if (Copy_u8State == RCC_ENABLE_CLOCK) {
		RCC->AHB2ENR |= ONE_BIT_MASK << Copy_u8Peripheral;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
/************************************************************
*			APB1 Enable/Disable peripheral clock	 		*
************************************************************/
u8 RCC_voidAPB1SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8State == RCC_DISABLE_CLOCK) {
		RCC->APB1ENR &= ~(ONE_BIT_MASK << Copy_u8Peripheral);
	}
	else if (Copy_u8State == RCC_ENABLE_CLOCK) {
		RCC->APB1ENR |= ONE_BIT_MASK << Copy_u8Peripheral;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
/************************************************************
*			APB2 Enable/Disable peripheral clock	 		*
************************************************************/
u8 RCC_voidAPB2SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8State == RCC_DISABLE_CLOCK) {
		RCC->APB2ENR &= ~(ONE_BIT_MASK << Copy_u8Peripheral);
	}
	else if (Copy_u8State == RCC_ENABLE_CLOCK) {
		RCC->APB2ENR |= ONE_BIT_MASK << Copy_u8Peripheral;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
/************************************************************
*						END OF FILE					 		*
************************************************************/


