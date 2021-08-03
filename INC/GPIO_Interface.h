/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		GPIO					************************/
/***************	@TITLE:		GPIO_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
/************************************************************
*				 	File Guards								*
************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/************************************************************
*				 Pin Configuration structure				*
************************************************************/
typedef struct	{
	u8				Port;			/*Refer Port to Possible values*/
	u8				PinNumber;		/*Refer Pin Number to Possible values*/
	u8				Mode;			/*Refer Mode to Possible values*/
	u8				OutputType;		/*Refer	Output Type to Possible values*/
	u8				OutputSpeed;	/*Refer Output Speed to Possible values*/
	u8				PullUpDown;		/*Refer Pull up/ Pull down to Possible values*/
	u8				AltFunc;		/*Refer Alternate Function to Possible values*/
}GPIO_PinCfg_t;
/*
 * Example Configuration structure to Nucleo-stm32f401re on-board LED
 *
 * 	GPIO_PinCfg_t Nucleo_Led = {GPIO_PORTA, GPIO_PIN5, GPIO_MODE_OUTPUT, GPIO_OP_PUSHPULL, GPIO_OP_MEDIUM_SPEED, GPIO_PULL_DOWN, GPIO_AF0};
 *
 */

/************************************************************
*				 I/O direction mode							*
************************************************************/
#define GPIO_MODE_INPUT		(0u)
#define GPIO_MODE_OUTPUT		(1u)
#define GPIO_MODE_ALT_FUNC	(2u)
#define GPIO_MODE_ANALOG		(3u)
/************************************************************
*				 Output type of the I/O port				*
************************************************************/
#define GPIO_OP_PUSHPULL		(0u)
#define GPIO_OP_OPEN_DRAIN		(1u)
/************************************************************
*				 I/O output speed							*
************************************************************/
#define GPIO_OP_LOW_SPEED			(0u)
#define GPIO_OP_MEDIUM_SPEED		(1u)
#define GPIO_OP_HIGH_SPEED			(2u)
#define GPIO_OP_VERY_HIGH_SPEED	(3u)
/************************************************************
*				 I/O pull-up or pull-down					*
************************************************************/
#define GPIO_NO_PULL	(0u)
#define GPIO_PULL_UP	(1u)
#define GPIO_PULL_DOWN	(2u)
/************************************************************
*				 Alternate function I/OS					*
************************************************************/
#define GPIO_NO_AF  (16u)
#define GPIO_AF0	(0u)
#define GPIO_AF1	(1u)
#define GPIO_AF2	(2u)
#define GPIO_AF3	(3u)
#define GPIO_AF4	(4u)
#define GPIO_AF5	(5u)
#define GPIO_AF6	(6u)
#define GPIO_AF7	(7u)
#define GPIO_AF8	(8u)
#define GPIO_AF9	(9u)
#define GPIO_AF10	(10u)
#define GPIO_AF11	(11u)
#define GPIO_AF12	(12u)
#define GPIO_AF13	(13u)
#define GPIO_AF14	(14u)
#define GPIO_AF15	(15u)
/************************************************************
*				 GPIO PINS									*
************************************************************/
#define GPIO_PIN0	(0u)
#define GPIO_PIN1	(1u)
#define GPIO_PIN2	(2u)
#define GPIO_PIN3	(3u)
#define GPIO_PIN4	(4u)
#define GPIO_PIN5	(5u)
#define GPIO_PIN6	(6u)
#define GPIO_PIN7	(7u)
#define GPIO_PIN8	(8u)
#define GPIO_PIN9	(9u)
#define GPIO_PIN10	(10u)
#define GPIO_PIN11	(11u)
#define GPIO_PIN12	(12u)
#define GPIO_PIN13	(13u)
#define GPIO_PIN14	(14u)
#define GPIO_PIN15	(15u)
/************************************************************
*				 PORTS										*
************************************************************/
#define GPIO_PORTA		(0u)
#define GPIO_PORTB		(1u)
#define GPIO_PORTC		(2u)
#define GPIO_PORTD		(3u)
#define GPIO_PORTE		(4u)
#define GPIO_PORTH		(5u)
/************************************************************
*				 PIN VALUES									*
************************************************************/
#define GPIO_PIN_HIGH		(1u)
#define GPIO_PIN_LOW		(0u)
/************************************************************
*				 Common Port Possible values				*
************************************************************/
#define GPIO_PORT_HIGH		(0xFFFFu)
#define GPIO_PORT_LOW		(0u)

/************************************************************
*				 Functions declarations						*
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
u8 GPIO_voidPinInit(const GPIO_PinCfg_t* Copy_pPinCfg_t);
/******************************************************************************/


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
u8 GPIO_u8SetPinValue(u8 Copy_port, u8 Copy_u8Pin, u8 Copy_u8Value);
/*******************************************************************************/


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
u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16Value);
/*******************************************************************************/


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
u8 GPIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);
/*******************************************************************************/


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
u8 GPIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
/*******************************************************************************/


/************************************************************
*				 	END OF FILE								*
************************************************************/

#endif
