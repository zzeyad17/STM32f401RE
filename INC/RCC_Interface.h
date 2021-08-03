/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		RCC						************************/
/***************	@TITLE:		RCC_Interface.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
/************************************************************
*				 	File Guards								*
************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/************************************************************
*				 	AHB1 PERIPHERALS						*
************************************************************/
#define RCC_AHB1_GPIOA        (0u)
#define RCC_AHB1_GPIOB        (1u)
#define RCC_AHB1_GPIOC        (2u)
#define RCC_AHB1_GPIOD		  (3u)
#define RCC_AHB1_GPIOE        (4u)
#define RCC_AHB1_GPIOH        (7u)
#define RCC_AHB1_CRC          (12u)
#define RCC_AHB1_DMA1         (21u)
#define RCC_AHB1_DMA2         (22u)
/************************************************************
*				 	AHB2 PERIPHERALS						*
************************************************************/
#define RCC_AHB2_OTGFS        (7u)
/************************************************************
*				 	APB1 PERIPHERALS						*
************************************************************/
#define RCC_APB1_TIMER2       	(0u)
#define RCC_APB1_TIMER3       	(1u)
#define RCC_APB1_TIMER4       	(2u)
#define RCC_APB1_TIMER5			(3u)
#define RCC_APB1_WWDG        	(11u)
#define RCC_APB1_SPI2        	(14u)
#define RCC_APB1_SPI3         	(15u)
#define RCC_APB1_USART2       	(17u)
#define RCC_APB1_I2C1         	(21u)
#define RCC_APB1_I2C2         	(22u)
#define RCC_APB1_I2C3         	(23u)
#define RCC_APB1_PWR			(28u)
/************************************************************
*				 	APB2 PERIPHERALS						*
************************************************************/
#define RCC_APB2_TIMER1       	(0u)
#define RCC_APB2_USART1       	(4u)
#define RCC_APB2_USART6      	(5u)
#define RCC_APB2_ADC1			(8u)
#define RCC_APB2_SDIO        	(11u)
#define RCC_APB2_SPI1        	(12u)
#define RCC_APB2_SPI4        	(13u)
#define RCC_APB2_SYSCFG       	(14u)
#define RCC_APB2_TIMER9       	(16u)
#define RCC_APB2_TIMER10      	(17u)
#define RCC_APB2_TIMER11      	(18u)
/************************************************************
*				 	Clock state 							*
************************************************************/
#define RCC_ENABLE_CLOCK	(1u)
#define RCC_DISABLE_CLOCK	(0u)
/************************************************************
*				 Functions declarations						*
************************************************************/
u8 RCC_voidAHB1SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State);
u8 RCC_voidAHB2SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State);
u8 RCC_voidAPB1SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State);
u8 RCC_voidAPB2SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State);
u8 RCC_voidAHB2SetPClock(u8 Copy_u8Peripheral, u8 Copy_u8State);

/************************************************************
*				 	END OF FILE								*
************************************************************/
#endif /* RCC_INTERFACE_H_ */
