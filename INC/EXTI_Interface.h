/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
/************************************************************
*				 	File Guards								*
************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/************************************************************
*					Trigger enum							*
************************************************************/
typedef	enum	{
	EXTI_RISING_TRIGGER,
	EXTI_FALLING_TRIGGER,
	EXTI_RIS_FALL_TRIGGER,
}Trigger_t;

/************************************************************
*		Pin configuration structure lines macros			*
************************************************************/
typedef struct	{
	u8 			Port;
	u8 			Pin;
	Trigger_t 	Trigger;
	void(*CallBackFunc)(void);
}EXTI_PinCfg_t;


/************************************************************
*				 EXTI lines macros							*
************************************************************/
#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2
#define EXTI_LINE3		3
#define EXTI_LINE4		4
#define EXTI_LINE5		5
#define EXTI_LINE6		6
#define EXTI_LINE7		7
#define EXTI_LINE8		8
#define EXTI_LINE9		9
#define EXTI_LINE10		10
#define EXTI_LINE11		11
#define EXTI_LINE12		12
#define EXTI_LINE13		13
#define EXTI_LINE14		14
#define EXTI_LINE15		15
#define EXTI_LINE16		16
#define EXTI_LINE17		17
#define EXTI_LINE18		18
#define EXTI_LINE19		19
#define EXTI_LINE20		20
#define EXTI_LINE21		21
#define EXTI_LINE22		22

/************************************************************
*				 EXTI Port macros							*
************************************************************/
#define EXTI_PORTA		(0u)
#define EXTI_PORTB		(1u)
#define EXTI_PORTC		(2u)
#define EXTI_PORTD		(3u)
#define EXTI_PORTE		(4u)
#define EXTI_PORTH		(7u)
/************************************************************
*				 EXTI Pins macros							*
************************************************************/
#define EXTI_PIN0 		(0u)
#define EXTI_PIN1 		(1u)
#define EXTI_PIN2 		(2u)
#define EXTI_PIN3 		(3u)
#define EXTI_PIN4 		(4u)
#define EXTI_PIN5 		(5u)
#define EXTI_PIN6 		(6u)
#define EXTI_PIN7 		(7u)
#define EXTI_PIN8 		(8u)
#define EXTI_PIN9 		(9u)
#define EXTI_PIN10 		(10u)
#define EXTI_PIN11 		(11u)
#define EXTI_PIN12 		(12u)
#define EXTI_PIN13 		(13u)
#define EXTI_PIN14 		(14u)
#define EXTI_PIN15 		(15u)
/************************************************************
*				 EXTI lines State macros					*
************************************************************/
#define EXTI_ENABLE	(1u)
#define EXTI_DISABLE	(2u)

/************************************************************
*				 Functions declarations						*
************************************************************/
/*********************************************************
 *	Function Name:	EXTI_u8EnableLine
 *
 *	Description:	This function enables/disable the interrupt on a given EXTI line
 *
 *	Parameters:		1) Copy_u8LineNum ->	Hold the EXTI line
 *					2) Copy_u8State	  -> 	Hold the state (EXTI_ENABLE / EXTI_DISABLE)
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8EnableLine(u8 Copy_u8LineNum, u8 Copy_u8State);

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_u8EnableRisingTrigger
 *
 *	Description:	This function enables/disable Rising trigger on  a given EXTI line
 *
 *	Parameters:		1) Copy_u8LineNum 	->	Hold the EXTI line
 *					2) Copy_u8State		-> 	Hold the state (EXTI_ENABLE / EXTI_DISABLE)
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8ConfigRisingTrigger(u8 Copy_u8LineNum, u8 Copy_u8State);

/**********************************************************************/

/*********************************************************
 *	Function Name:	EXTI_u8FallingRisingTrigger
 *
 *	Description:	This function enables/disable Falling trigger on  a given EXTI line
 *
 *	Parameters:		1) Copy_u8LineNum 	->	Hold the EXTI line
 *					2) Copy_u8State		-> 	Hold the state (EXTI_ENABLE / EXTI_DISABLE)
 *
 *	Return:			Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 EXTI_u8ConfigFallingTrigger(u8 Copy_u8LineNum, u8 Copy_u8State);

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
u8 EXTI_u8ClearPIF(u8 Copy_u8LineNum);

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
u8 EXTI_u8PinSelect(u8 Copy_u8Port, u8 Copy_u8PinNum);

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
u8 EXTI_u8PinInit(const EXTI_PinCfg_t* Copy_pPinCfg_t);


/************************************************************
*				 	END OF FILE								*
************************************************************/
#endif /* EXTI_INTERFACE_H_ */
