/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		LIB						************************/
/***************	SWC:			STM32F401xx devices	************************/
/***************	@TITLE:		STM32F401xx.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef STM32F401xx_H_
#define STM32F401xx_H_

/************************************************************
*				Memories base addresses		       			*
************************************************************/
#define FLASH_BASE_ADDRESS			0X80000000UL
#define SRAM						0x20000000UL
#define ROM							0x1FFF0000UL
/************************************************************
*					RCC base addresses						*
************************************************************/
#define RCC_BASE_ADDRESS			0x40023800UL

/************************************************************
*		AHB1 Peripheral base addresses						*
************************************************************/
#define GPIOA_BASE_ADDRESS			0x40020000UL
#define GPIOB_BASE_ADDRESS			0x40020400UL
#define GPIOC_BASE_ADDRESS			0x40020800UL
#define GPIOD_BASE_ADDRESS			0x40020C00UL
#define GPIOE_BASE_ADDRESS			0x40021000UL
#define GPIOH_BASE_ADDRESS			0x40021C00UL
/************************************************************
*		APB1 Peripheral base addresses						*
************************************************************/
#define I2C3_BASE_ADDRESS				0x40005C00UL
#define I2C2_BASE_ADDRESS				0x40005800UL
#define I2C1_BASE_ADDRESS				0x40005400UL
#define SPI3_BASE_ADDRESS				0x40003C00UL
#define SPI2_BASE_ADDRESS				0x40003800UL
#define USART2_BASE_ADDRESS				0x40004400UL
/************************************************************
*		APB2 Peripheral base addresses						*
************************************************************/
#define SPI4_BASE_ADDRESS				0x40013400UL
#define SPI1_BASE_ADDRESS				0x40013000UL
#define USART6_BASE_ADDRESS				0x40011400UL
#define USART1_BASE_ADDRESS				0x40011000UL
#define EXTI_BASE_ADDRESS				0x40013C00UL
#define SYSCFG_BASE_ADDRESS				0x40013800UL



/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/****************************** Core peripherals************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/

/************************************************************
*		SysTick Register definition structure				*
************************************************************/
typedef	struct	{
	volatile u32		CTRL;
	volatile u32		LOAD;
	volatile u32		VAL;
	volatile u32		CALIB;
} STK_RegDef_t;
/************************************************************
*		SysTick Peripheral definitions						*
************************************************************/
#define STK_BASE_ADDRESS				0xE000E010UL
#define STK								((STK_RegDef_t*)STK_BASE_ADDRESS)




/************************************************************
*		NVIC Register definition structure				*
************************************************************/
typedef	struct	{
	volatile u32		ISER[8];
	volatile u32		Reserved1[24];
	volatile u32		ICER[8];
	volatile u32		Reserved2[24];
	volatile u32		ISPR[8];
	volatile u32		Reserved3[24];
	volatile u32		ICPR[8];
	volatile u32		Reserved4[24];
	volatile u32		IAPR[8];
	volatile u32		Reserved5[56];
	volatile u8			IPR[240];

} NVIC_RegDef_t;
/************************************************************
*					NVIC Peripheral definitions				*
************************************************************/
#define NVIC_BASE_ADDRESS				0xE000E100UL
#define NVIC							((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)



/************************************************************
*		SCB Register definition structure				*
************************************************************/
typedef struct
{
	volatile u32		CPUID;				//CPUID base register
	volatile u32 		ICSR;				//Interrupt control and state register
	volatile u32 		VTOR;				//Vector table offset register
	volatile u32 		AIRCR;				//Application interrupt and reset control register
	volatile u32 		SCR;				//System control register
	volatile u32 		CCR;				//Configuration and control register
	volatile u32 		SHPR[3];			//System handler priority registers
	volatile u32 		SHCSR;				//System handler control and state register
	volatile u32 		CFSR;				//Configurable fault status register
	volatile u32 		HFSR;				//Hard fault status register
	volatile u32 		Reserved;
	volatile u32 		MMAR;				//Memory management fault address register
	volatile u32 		BFAR;				//Bus fault address register
	volatile u32 		AFSR;				//Auxiliary fault status register
}SCB_RegDef_t;
/************************************************************
*					SCB Peripheral definitions				*
************************************************************/
#define SCB_BASE_ADDRESS                0xE000ED00UL
#define  SCB              				((SCB_RegDef_t*)SCB_BASE_ADDRESS)


/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/****************************** MCU peripherals************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/

/************************************************************
*		EXTI Register definition structure					*
************************************************************/
typedef struct	{
	volatile u32	IMR; 	/*Interrupt mask register*/
	volatile u32	EMR;
	volatile u32	RTSR;	/*Rising trigger selection register*/
	volatile u32	FTSR;	/*Falling trigger selection register*/
	volatile u32	SWIER;
	volatile u32	PR;		/*Pending register*/
}EXTI_RegDef_t;

/************************************************************
*					EXTI Peripheral definitions				*
************************************************************/
#define EXTI_BASE_ADDRESS                0x40013C00UL
#define  EXTI              				((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)



/************************************************************
*		SYSCFG Register definition structure				*
************************************************************/
typedef struct	{
	volatile u32	MEMRMP;
	volatile u32	PMC;
	volatile u32	EXTICR[4];		/*external interrupt configuration registers array*/
	volatile u32	CMPCR;
}SYSCFG_RegDef_t;

/************************************************************
*					EXTI Peripheral definitions				*
************************************************************/
#define SYSCFG_BASE_ADDRESS				0x40013800UL
#define  SYSCFG              			((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)




/************************************************************
*		RCC Register definition structure					*
************************************************************/
typedef struct	{
	volatile u32	CR;
	volatile u32	PLLCFGR;
	volatile u32	CFGR;
	volatile u32	CIR;
	volatile u32	AHB1RSTR;
	volatile u32	AHB2RSTR;
	volatile u32	RESERVED1[2];
	volatile u32	APB1RSTR;
	volatile u32	APB2RSTR;
	volatile u32	RESERVED2[2];
	volatile u32	AHB1ENR;
	volatile u32	AHB2ENR;
	volatile u32	RESERVED3[2];
	volatile u32	APB1ENR;
	volatile u32	APB2ENR;
	volatile u32	RESERVED4[2];
	volatile u32	AHB1LPENR;
	volatile u32	AHB2LPENR;
	volatile u32	RESERVED5[2];
	volatile u32	APB1LPENR;
	volatile u32	APB2LPENR;
	volatile u32	RESERVED6[2];
	volatile u32	BDCR;
	volatile u32	CSR;
	volatile u32	RESERVED7[2];
	volatile u32	SSCGR;
	volatile u32	PLLI2SCFGR;
	volatile u32	RESERVED8;
	volatile u32 	DCKCFGR;
} RCC_RegDef_t;
/************************************************************
*		RCC Peripheral definitions						 	*
************************************************************/
#define RCC		((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/************************************************************
*		GPIO Register definition structure					*
************************************************************/
typedef struct 	{
	volatile u32	MODER;		/*GPIO port mode register*/
	volatile u32	OTYPER;		/*GPIO port output type register*/
	volatile u32	OSPEEDR;	/*GPIO port output speed register*/
	volatile u32	PUPDR;		/*GPIO port pull-up/pull-down register*/
	volatile u32	IDR;		/*GPIO port input data register*/
	volatile u32	ODR;		/*GPIO port output data register*/
	volatile u32	BSRR;		/*GPIO port bit set/reset register*/
	volatile u32	LCKR;		/*GPIO port configuration lock register*/
	volatile u32 	AFR[2];		/*GPIO alternate function register*/
}	GPIO_RegDef_t;
/************************************************************
*		GPIO Peripheral definitions						 	*
************************************************************/

#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB		((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC		((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD		((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE		((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOH		((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

//#define _BASE_ADDRESS								UL
/************************************************************
*			END OF FILE				     					*
************************************************************/
#endif
