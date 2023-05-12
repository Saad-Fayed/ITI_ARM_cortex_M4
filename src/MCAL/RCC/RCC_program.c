/*
 * RCC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: LENOVO
 */

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI

	SET_BIT(RCC->RCC_CR, 0); //Enable HSI Clock (16 MHZ)

	/*Select HSI as System Clock Source*/
	CLR_BIT(RCC->RCC_CFGR, 0);
	CLR_BIT(RCC->RCC_CFGR, 1);

#elif SYSTEM_CLK_SRC == HSE_RC

	SET_BIT(RCC->RCC_CR, 16); //Enable HSE Clock
	SET_BIT(RCC->RCC_CR, 18); //Select RC_External (ByPass Mode)

	/*Select HSE as System Clock Source*/
	SET_BIT(RCC->RCC_CFGR, 0);
	CLR_BIT(RCC->RCC_CFGR, 1);

#elif SYSTEM_CLK_SRC == HSE_CRYSTAL

	SET_BIT(RCC->RCC_CR, 16); //Enable HSE Clock
	CLR_BIT(RCC->RCC_CR, 18); //Select Crystal_External (ByPass Mode)

	/*Select HSE as System Clock Source*/
	SET_BIT(RCC->RCC_CFGR, 0);
	CLR_BIT(RCC->RCC_CFGR, 1);

#elif SYSTEM_CLK_SRC == PLL

//	SET_BIT(RCC->RCC_CR, 24); //Enable PLL Clock
//
//	/*Select HSE as System Clock Source*/
//	CLR_BIT(RCC->RCC_CFGR, 0);
//	SET_BIT(RCC->RCC_CFGR, 1);
//
//	/*Selecting PreScaler Value*/


#else
	#error("Wrong System Clock Configuration");
#endif
}

u8 RCC_u8EnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	u8 Local_Error_State = OK;


	switch(Copy_u8BusID)
	{

	case(RCC_AHB1):

		if(Copy_u8PeripheralID<0 || Copy_u8PeripheralID>22)
			Local_Error_State = Wrong_Peripheral_ID;
		else
			SET_BIT(RCC->RCC_AHB1ENR,Copy_u8PeripheralID);

		break;

	case(RCC_AHB2):

		Copy_u8PeripheralID -= 31;

		if(Copy_u8PeripheralID != 7)
			Local_Error_State = Wrong_Peripheral_ID;
		else
			SET_BIT(RCC->RCC_AHB2ENR,Copy_u8PeripheralID);

		break;

	case(RCC_APB1):

		Copy_u8PeripheralID -= 62;

		if(Copy_u8PeripheralID<0 || Copy_u8PeripheralID>28)
			Local_Error_State = Wrong_Peripheral_ID;
		else
			SET_BIT(RCC->RCC_APB1ENR,Copy_u8PeripheralID);

		break;

	case(RCC_APB2):

		Copy_u8PeripheralID -= 93;

		if(Copy_u8PeripheralID<0 || Copy_u8PeripheralID>18)
			Local_Error_State = Wrong_Peripheral_ID;
		else
		SET_BIT(RCC->RCC_APB2ENR,Copy_u8PeripheralID);

		break;

	default:

		Local_Error_State = Wrong_bus_ID;

		break;
	}
	return Local_Error_State;
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	switch(Copy_u8BusID)
	{
	case(RCC_AHB1):
		CLR_BIT(RCC->RCC_AHB1ENR,Copy_u8PeripheralID);
		break;
	case(RCC_AHB2):
		CLR_BIT(RCC->RCC_AHB2ENR,Copy_u8PeripheralID);
		break;
	case(RCC_APB1):
		CLR_BIT(RCC->RCC_APB1ENR,Copy_u8PeripheralID);
		break;
	case(RCC_APB2):
		CLR_BIT(RCC->RCC_APB2ENR,Copy_u8PeripheralID);
		break;
	/*Implement Error State Using Enum*/
	}
}
