/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : NVIC_program.c             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Function Implementation of NVIC Peripheral  */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void EXTI_voidEnableInt(u8 Copy_u8IntID , void(*Copy_ptrToFunc)(void))
{
	SET_BIT(EXTI->IMR,Copy_u8IntID);
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

//void EXTI_voidSetLinePort(u8 Copy_u8IntID , u8 Copy_u8PortID)
//{
//
//}
