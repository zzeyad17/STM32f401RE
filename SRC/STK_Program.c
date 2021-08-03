/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		STK						************************/
/***************	@TITLE:		STK_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/************************************************************
*				 	Header Files Inclusion					*
************************************************************/
#include "Std_Types.h"
#include "STM32F401XX.h"
#include "STK_Interface.h"
#include "STK_Private.h"
/************************************************************
*				 	STK Delay MS							*
************************************************************/
/*********************************************************
 *	Function Name:  STK_voidDelayMS
 *
 *	Description: The function create delay for a given period of time (time in ms)
 *	Note:		 The function assume that the AHB1 CLK is 16MHz
 *
 *	Parameters: Copy_u16DelayMS, the delay time in ms
 *
 *	Return: void
 *
 ********************************************************/
void STK_voidDelayMS(u16 Copy_u16DelayMS) {
	u32 Local_u32LoadValue = Copy_u16DelayMS * 2000UL;
	/*Set the load value*/
	STK->LOAD = Local_u32LoadValue;
	/*Clear the Counter Register*/
	STK->VAL = 0;
	/*Set the clock source to AHB/8*/
	STK->CTRL &= ~(1 << CTRL_CLKSOURCE);
	/*Enable the STK*/
	STK->CTRL |= (1 << CTRL_ENABLE);
	/*Poll on the COUNTFLAG until the Timer finish counting */
	while ( ((STK->CTRL >> CTRL_COUNTFLAG) & 1) == 0 );
	/*Disable the STK*/
	STK->CTRL &= ~(1 << CTRL_ENABLE);
}

