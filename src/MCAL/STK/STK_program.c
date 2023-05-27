/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : STK_program.c             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Function Implementation of STK Peripheral   */
/*Date        : 26 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/*************************************************************************/
/***************************Global Variables******************************/
/*************************************************************************/

/* Global pointer to function to set call back of SYSTICK*/
void (*Global_PtrToFunc)(void) = NULL ;

u8 Global_u8AsyncRepitition = SINGLE ;

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void STK_voidInit(void)
{
	/*Disable Interrupt , clock source = AHB/8 */
	/*System clock = HSI -> tick time = 0.5 microsecond*/
	STK->CTRL = 0 ;

	/*Reset LOAD and VAL registers*/
	STK->LOAD = 0 ;
	STK->VAL  = 0 ;

}

void STK_voidDelaySync(u32 Copy_u32Delay_us)
{
	/*(1)Disable interrupt*/
	CLR_BIT(STK->CTRL , 1 ) ;

	/*(2)Set lOAD register value to get the target delay*/
	STK->LOAD = (Copy_u32Delay_us*2) ;

	/*(3)Run systick*/
	SET_BIT(STK->CTRL , 0) ;

	/*(4)Polling till the end of target time*/
	/*(5)Clear flag*/
	while((GET_BIT(STK->CTRL,16))==0);

	/*(6)Stop timer*/
	CLR_BIT(STK->CTRL , 0) ;

	/*(7)Reset LOAD and VAL registers*/
	STK->LOAD = 0 ;
	STK->VAL  = 0 ;
}

void STK_voidDelayAsyncSingle(u32 Copy_u32Delay_us , void(*Copy_ptrToFunc)(void))
{
	/*Set global flag value*/
	Global_u8AsyncRepitition = SINGLE ;

	/*(1)Enable interrupt*/
	SET_BIT(STK->CTRL , 1 ) ;

	/*(2)Set lOAD register value to get the target delay*/
	STK->LOAD = Copy_u32Delay_us / 2 ;

	/*Reset value register*/
	STK->VAL = 0 ;

	/*(3)Set call back*/
	if(Copy_ptrToFunc != NULL)
	{
		Global_PtrToFunc = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}

	/*(4)Run systick*/
	SET_BIT(STK->CTRL , 0) ;
}


void STK_voidDelayAsyncPeriodic(u32 Copy_u32Delay_us , void(*Copy_ptrToFunc)(void))
{
	/*Set global flag value*/
	Global_u8AsyncRepitition = PERIODIC ;

	/*(1)Enable interrupt*/
	SET_BIT(STK->CTRL , 1 ) ;

	/*(2)Set lOAD register value to get the target delay*/
	STK->LOAD = Copy_u32Delay_us / 2 ;

	/*Reset value register*/
	STK->VAL = 0 ;

	/*(3)Set call back*/
	if(Copy_ptrToFunc != NULL)
	{
		Global_PtrToFunc = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}

	/*(4)Run systick*/
	SET_BIT(STK->CTRL , 0) ;
}

u32 STK_u32GetRemainingTime(void)
{
	return STK->VAL ;
}

u32 STK_u32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL) ;
}


/*************************************************************************/
/*************************Systick Implementation**************************/
/*************************************************************************/

/*systick ISR*/
void Systick_Handler(void)
{
	switch(Global_u8AsyncRepitition)
	{
		case SINGLE :

			/*Calling application function*/
			Global_PtrToFunc();

			/*Stop counting*/
			CLR_BIT(STK->CTRL , 0);

			break ;

		case PERIODIC :

			/*Calling application function*/
			Global_PtrToFunc();

			break ;
	}
}


