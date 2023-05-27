/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : EXTI_program.c             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Function Implementation of EXTI Peripheral  */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*************************************************************************/
/***************************Global Variables******************************/
/*************************************************************************/

/* Array of global pointers to functions to set call back of EXTI sources */
void (*Global_PtrToFunc_EXTI[16])(void) = {NULL};

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void EXTI_voidEnableInt(u8 Copy_u8IntID , void(*Copy_ptrToFunc)(void))
{
	/*Set call back function*/
	if(Copy_ptrToFunc != NULL)
	{
		Global_PtrToFunc_EXTI[Copy_u8IntID] = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}

	/*Enable interrupt*/
	SET_BIT(EXTI->IMR , Copy_u8IntID);
}

void EXTI_voidDisableInt(u8 Copy_u8IntID)
{
	CLR_BIT(EXTI->IMR,Copy_u8IntID);
}

void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal,u8 Copy_u8IntID)
{
	switch(Copy_u8SenseSignal)
	{
		case FALLING_EDGE:
			CLR_BIT(EXTI->FTSR , Copy_u8IntID);
			SET_BIT(EXTI->RTSR , Copy_u8IntID);
			break;
		case RISING_EDGE:
			CLR_BIT(EXTI->RTSR , Copy_u8IntID);
			SET_BIT(EXTI->FTSR , Copy_u8IntID);
			break;
		case ON_CHANGE:
			SET_BIT(EXTI->RTSR , Copy_u8IntID);
			SET_BIT(EXTI->FTSR , Copy_u8IntID);
			break;
	}
}

void EXTI_voidSetLinePort(u8 Copy_u8IntID , u8 Copy_u8PortID)
{
	/* Through System Configurations Register */

	/*1)Clear target bits to set the new configurations (bit masking)*/
	SYSCFG->EXTICR[Copy_u8IntID/4] &= ~(0b1111 << ((Copy_u8IntID % 4)*4)) ;

	/*2)Set the new configurations*/
	SYSCFG->EXTICR[Copy_u8IntID/4] |= Copy_u8PortID <<((Copy_u8IntID % 4)*4) ;
}

static void EXTI_voidClearPendingFlag(u8 Copy_u8IntId)
{
	/*clear the interrupt flag after executing the interrupt ISR*/
	SET_BIT(EXTI->PR , Copy_u8IntId);
}

/*************************************************************************/
/**************************ISRs' Implementation***************************/
/*************************************************************************/

/* ISR for external interrupt 0 */
void EXTI0_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[0]();
	EXTI_voidClearPendingFlag(EXTI_LINE0);
}

/* ISR for external interrupt 1 */
void EXTI1_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[1]();
	EXTI_voidClearPendingFlag(EXTI_LINE1);
}
