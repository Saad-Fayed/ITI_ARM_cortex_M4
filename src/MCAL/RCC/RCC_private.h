/************************************************************************/
/*Author      : Saad Mohamed										    */
/*File Name   : RCC_private.h                                           */
/*Layer       : MCAL								 	        	    */
/*Description : This file contains private parameters of RCC module     */
/*Date        : 5 May 2023                                              */
/************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*************************************************************************/
/*******************Configuration Macros Definitions**********************/
/*************************************************************************/

/*    System Clock Configurations    */
#define	HSI        	1
#define	HSE_RC      2
#define	HSE_CRYSTAL 3
#define	PLL         4

/*    Error States     */
typedef enum
{
	OK,
	Wrong_bus_ID,
	Wrong_Peripheral_ID
}Error_State_e;

/*    RCC Registers    */

typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RCC_RESERVED1;
	volatile u32 RCC_RESERVED2;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_RESERVED3;
	volatile u32 RCC_RESERVED4;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RCC_RESERVED5;
	volatile u32 RCC_RESERVED6;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_RESERVED7;
	volatile u32 RCC_RESERVED8;
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 RCC_RESERVED9;
	volatile u32 RCC_RESERVED10;
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 RCC_RESERVED11;
	volatile u32 RCC_RESERVED12;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC_RESERVED13;
	volatile u32 RCC_RESERVED14;
	volatile u32 RCC_SSRCG;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 RCC_RESERVED15;
	volatile u32 RCC_DCKCFGR;
} RCC_RegDef_t;

#define RCC  ((volatile RCC_RegDef_t *)0x40023800)


#endif
