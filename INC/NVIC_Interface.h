/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		NVIC					************************/
/***************	@TITLE:		NVIC_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
/************************************************************
*				 	File Guards								*
************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/************************************************************
*				 Functions declarations						*
************************************************************/
/*********************************************************
 *	Function Name:	NVIC_u8EnableInterrupt
 *
 *	Description:	The function enable interrupt for the giver IRQn
 *
 *	Parameters:		1) Copy_u8IRQ -> Hold the IRQ number
 *
 *	Return:			1) Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 NVIC_u8EnableInterrupt(u8 Copy_u8IRQ);
/*************************************************************/



/*********************************************************
 *	Function Name:	NVIC_u8SetPendingFlag
 *
 *	Description:	The function Sets the pending status of the giver IRQ number
 *
*	Parameters:		1) Copy_u8IRQ -> Hold the IRQ number
 *
 *	Return:			1) Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 NVIC_u8SetPendingFlag(u8 Copy_u8IRQ);
/*************************************************************/


/*********************************************************
 *	Function Name:	NVIC_u8ConfigGroupSubBits
 *
 *	Description:	The function splits the PRI_n fields in the Interrupt Priority Registers into separate group priority and subpriority fields
 *
 *	Parameters:		1) Copy_u8GroupPriorityBits -> the number of bits assigned to the Group priority (the rest of the 4 bits assigned to the sub priority)
 *
 *	Return:			1) Local_u8ErrorState -> Error state
 *
 ********************************************************/
u8 NVIC_u8ConfigGroupSubBits(u8 Copy_u8GroupPriorityBits);
/*************************************************************/




/*********************************************************
 *	Function Name:	NVIC_u8SetIRQPiriority
 *
 *	Description:	The function set the group priority and sub priority of a given IRQ number
 *
 *	Parameters:		1) Copy_u8IRQNum			-> Interrupt request number number
 *					2) Copy_u8GroupPiriority	-> Group priority
 *					3) Copy_u8SubPiriority		-> sub priority
 *
 *	Return:			1) Local_u8ErrorState       -> Error state
 *
 ********************************************************/
u8 NVIC_u8SetIRQPiriority(u8 Copy_u8IRQNum, u8 Copy_u8GroupPiriority, u8 Copy_u8SubPiriority);
/*************************************************************/


/************************************************************
*				 	END OF FILE								*
************************************************************/
#endif /* NVIC_INTERFACE_H_ */

