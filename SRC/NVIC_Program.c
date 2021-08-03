/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		NVIC					************************/
/***************	@TITLE:		NVIC_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/************************************************************
*				 	Header Files Inclusion					*
************************************************************/
#include "Std_Types.h"
#include "STM32F401XX.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"

/************************************************************
*				 	Global variables						*
************************************************************/
static u8 NVIC_u8GroupPiriorityBits = DEFAULT_GROUP_PIRIORITY_BITS;  /*DEFAULT_GROUP_PIRIORITY_BITS = 4*/

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
u8 NVIC_u8EnableInterrupt(u8 Copy_u8IRQ) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8IRQ > IRQ_MAX) {
		Local_u8ErrorState = NOK;
	}
	else {
		u8 Local_u8RegisterNum = (Copy_u8IRQ / 32);
		u8 Local_u8BitNum = (Copy_u8IRQ % 32);
		NVIC->ISER[Local_u8RegisterNum] = (1 << Local_u8BitNum);
	}
	return Local_u8ErrorState;
}
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
u8 NVIC_u8SetPendingFlag(u8 Copy_u8IRQ) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8IRQ > IRQ_MAX) {
		Local_u8ErrorState = NOK;
	}
	else {
		u8 Local_u8RegisterNum = (Copy_u8IRQ / 32);
		u8 Local_u8BitNum = (Copy_u8IRQ % 32);
		NVIC->ISPR[Local_u8RegisterNum] = (1 << Local_u8BitNum);
	}
	return Local_u8ErrorState;
}
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
u8 NVIC_u8ConfigGroupSubBits(u8 Copy_u8GroupPriorityBits) {
	u8 Local_u8ErrorState = OK;
	u32 Local_u32AIRCR = (u32)(VECTKEY << 16u);  /*Bits 31:16 must be 0x5FA otherwise the write is ignored*/
	if (Copy_u8GroupPriorityBits > 4) {
		Local_u8ErrorState = NOK;
	}
	else {
		/*Set the NVIC_u8GroupPiriorityBits global variable*/
		NVIC_u8GroupPiriorityBits = Copy_u8GroupPriorityBits;

		/*Set the PRIGROUP in the SCB->AIRCR register*/
		switch (Copy_u8GroupPriorityBits) {
			case 4:	/*Set the PRIGROUP field to zero*/
					break;
			default:
					/*Set the PRIGROUP field*/
					Local_u32AIRCR |= ( (4 + (3 - Copy_u8GroupPriorityBits)) << PRIGROUP_MASK ); /*PRIGROUP_MASK = 8*/
					break;
		}

	SCB->AIRCR = Local_u32AIRCR;

	}

	return Local_u8ErrorState;
}
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
u8 NVIC_u8SetIRQPiriority(u8 Copy_u8IRQNum, u8 Copy_u8GroupPiriority, u8 Copy_u8SubPiriority) {
	u8 Local_u8ErrorState = OK;
	u8 Local_u8PRIGROUP = 0;

	switch (NVIC_u8GroupPiriorityBits) {	/*NVIC_u8GroupPiriorityBits is a global variable hold the configuration of the group/sub priority bits*/
		case 0:								/*NVIC_u8GroupPiriorityBits is by default = 4 (4 bits for GP and 0 bits for SP )*/
				Local_u8PRIGROUP = (Copy_u8SubPiriority & 0xF);
				break;
		case 1:
				Local_u8PRIGROUP = ((Copy_u8GroupPiriority & 0x1) << 3) | (Copy_u8SubPiriority & 0x7);
				break;
		case 2:
				Local_u8PRIGROUP = ((Copy_u8GroupPiriority & 0x3) << 2) | (Copy_u8SubPiriority & 0x3);
				break;
		case 3:
				Local_u8PRIGROUP = ((Copy_u8GroupPiriority & 0x7) << 1) | (Copy_u8SubPiriority & 0x1);
				break;
		case 4:
				Local_u8PRIGROUP = (Copy_u8GroupPiriority & 0xF);
				break;
		default:
				Local_u8ErrorState = NOK;
				break;
	}

	NVIC->IPR[Copy_u8IRQNum] &= IPR_MASK;
	NVIC->IPR[Copy_u8IRQNum] |= (Local_u8PRIGROUP << 4);

	return Local_u8ErrorState;
}
/*************************************************************/


/************************************************************
*				 	END OF FILE								*
************************************************************/




