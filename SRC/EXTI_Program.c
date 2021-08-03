/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/************************************************************
*				 	Header Files Inclusion					*
************************************************************/
#include "Std_Types.h"
#include "STM32F401XX.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

/************************************************************
*				 	Global variables						*
************************************************************/
static void(*EXTI_pCallBackFunc)(void) = NULL;
static void(*EXTI_pCallBackFuncArr[22])(void) = {NULL};

/*********************************************************
 *	Function Name:	EXTI_u8EnableLine
 *
 *	Description:	This function enables the interrupt on a given EXTI line
 *
 *	Parameters:		Copy_u8LineNum ->	Hold the EXTI line
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8EnableLine(u8 Copy_u8LineNum, u8 Copy_u8State)	{
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8LineNum <= EXTI_LINE22) && (Copy_u8LineNum != EXTI_LINE19) && (Copy_u8LineNum != EXTI_LINE20))	{
		if (Copy_u8State == EXTI_ENABLE) {
			//EXTI->IMR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
			EXTI->IMR |= EXTI_LINE_MASK << Copy_u8LineNum;
		}
		else if (Copy_u8State == EXTI_DISABLE) {
			EXTI->IMR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
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

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_EnableRisingTrigger
 *
 *	Description:	This function enables/disable Rising trigger on  a given EXTI line
 *
 *	Parameters:		Copy_u8LineNum 	->	Hold the EXTI line
 *					2) Copy_u8State	-> 	Hold the state (EXTI_ENABLE / EXTI_DISABLE)
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8ConfigRisingTrigger(u8 Copy_u8LineNum, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8LineNum <= EXTI_LINE22) && (Copy_u8LineNum != EXTI_LINE19) && (Copy_u8LineNum != EXTI_LINE20))	{
		if (Copy_u8State == EXTI_ENABLE) {
			//EXTI->RTSR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
			EXTI->RTSR |= EXTI_LINE_MASK << Copy_u8LineNum;
		}
		else if (Copy_u8State == EXTI_DISABLE) {
			EXTI->RTSR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
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

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_FallingRisingTrigger
 *
 *	Description:	This function enables/disable Falling trigger on  a given EXTI line
 *
 *	Parameters:		1) Copy_u8LineNum 	->	Hold the EXTI line
 *					2) Copy_u8State		-> 	Hold the state (EXTI_ENABLE / EXTI_DISABLE)
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8ConfigFallingTrigger(u8 Copy_u8LineNum, u8 Copy_u8State) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8LineNum <= EXTI_LINE22) && (Copy_u8LineNum != EXTI_LINE19) && (Copy_u8LineNum != EXTI_LINE20))	{
		if (Copy_u8State == EXTI_ENABLE) {
			//EXTI->FTSR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
			EXTI->FTSR |= EXTI_LINE_MASK << Copy_u8LineNum;
		}
		else if (Copy_u8State == EXTI_DISABLE) {
			EXTI->FTSR &= ~(EXTI_LINE_MASK << Copy_u8LineNum);
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

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_u8ClearPIF
 *
 *	Description:	This function clears the peripheral interrupt flag of a given EXTI line
 *
 *	Parameters:		1) Copy_u8LineNum 	->	Hold the EXTI line
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8ClearPIF(u8 Copy_u8LineNum) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8LineNum <= EXTI_LINE22) && (Copy_u8LineNum != EXTI_LINE19) && (Copy_u8LineNum != EXTI_LINE20))	{
		/*atomic*/
		EXTI->PR = EXTI_LINE_MASK << Copy_u8LineNum;
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_u8PinSelect
 *
 *	Description:	This function Select the source input of the EXTIx External interrupt
 *
 *	Parameters:		1) Copy_u8Port 	 ->	Hold the Port
 *					2) Copy_u8PinNum -> Hold the Pin number
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8PinSelect(u8 Copy_u8Port, u8 Copy_u8PinNum) {
	u8 Local_u8ErrorState = OK;
	if (( (Copy_u8Port == EXTI_PORTH) || (Copy_u8Port <= EXTI_PORTE) ) && (Copy_u8PinNum <= EXTI_PIN15))	{

		u8 Local_u8RegNum = (Copy_u8PinNum / EXTICR_MASK);
		u8 Local_u8PinNumber = (Copy_u8PinNum % EXTICR_MASK);

		SYSCFG->EXTICR[Local_u8RegNum] &= ~(PIN_SELECT_MASK << (Local_u8PinNumber * EXTICR_MASK));
		SYSCFG->EXTICR[Local_u8RegNum] |= (Copy_u8Port << (Local_u8PinNumber * EXTICR_MASK));
	}
	else {
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/**********************************************************************/


/*********************************************************
 *	Function Name:	EXTI_u8PinInit
 *
 *	Description:	This function Configure a MCU pin as external interrupt pin
 *
 *	Parameters:		1) Copy_pPinCfg_t ->	Pointer to constant EXTI_PinCfg_t structure (external interrupt pin configuration structure)
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8PinInit(const EXTI_PinCfg_t* Copy_pPinCfg_t) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_pPinCfg_t == NULL) || (Copy_pPinCfg_t->CallBackFunc == NULL)) {
		Local_u8ErrorState = NULL_POINTER;
	}
	if (Copy_pPinCfg_t->Trigger > EXTI_RIS_FALL_TRIGGER) {
		Local_u8ErrorState = NOK;
	}
	else {
		if ((EXTI_u8PinSelect(Copy_pPinCfg_t->Port, Copy_pPinCfg_t->Pin) == OK) && (EXTI_u8EnableLine(Copy_pPinCfg_t->Pin, EXTI_ENABLE) == OK)) {
			if (Copy_pPinCfg_t->Trigger == EXTI_RISING_TRIGGER) {
				EXTI_u8ConfigRisingTrigger(Copy_pPinCfg_t->Pin, EXTI_ENABLE);
			}
			else if (Copy_pPinCfg_t->Trigger == EXTI_FALLING_TRIGGER) {
				EXTI_u8ConfigFallingTrigger(Copy_pPinCfg_t->Pin, EXTI_ENABLE);
			}
			else  {
				EXTI_u8ConfigRisingTrigger(Copy_pPinCfg_t->Pin, EXTI_ENABLE);
				EXTI_u8ConfigFallingTrigger(Copy_pPinCfg_t->Pin, EXTI_ENABLE);
			}
			/*Sending the address of the notification function to the handler via global variable */
			//EXTI_pCallBackFunc = Copy_pPinCfg_t->CallBackFunc;
			EXTI_pCallBackFuncArr[Copy_pPinCfg_t->Pin] = Copy_pPinCfg_t->CallBackFunc;

		}
		else {
			Local_u8ErrorState = NOK;
		}
	}

	return Local_u8ErrorState;
}

/************************************************************
*				 	EXTI handlers							*
************************************************************/
void EXTI0_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE0);
	//EXTI_pCallBackFuncArr[0]();
	EXTI_pCallBackFunc();
}
void EXTI1_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE1);
	EXTI_pCallBackFunc();
}
void EXTI2_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE2);
	EXTI_pCallBackFunc();
}
void EXTI3_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE3);
	EXTI_pCallBackFunc();
}
void EXTI4_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE4);
	EXTI_pCallBackFunc();
}
void EXTI15_10_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE10);
	EXTI_u8ClearPIF(EXTI_LINE11);
	EXTI_u8ClearPIF(EXTI_LINE12);
	EXTI_u8ClearPIF(EXTI_LINE13);
	EXTI_u8ClearPIF(EXTI_LINE14);
	EXTI_u8ClearPIF(EXTI_LINE15);

	//EXTI_pCallBackFunc();
	EXTI_pCallBackFuncArr[13]();
}
void EXTI9_5_IRQHandler() {
	EXTI_u8ClearPIF(EXTI_LINE10);
	EXTI_u8ClearPIF(EXTI_LINE11);
	EXTI_u8ClearPIF(EXTI_LINE12);
	EXTI_u8ClearPIF(EXTI_LINE13);
	EXTI_u8ClearPIF(EXTI_LINE14);
	EXTI_u8ClearPIF(EXTI_LINE15);

	EXTI_pCallBackFunc();
}


/************************************************************
*				 	END OF FILE								*
************************************************************/

