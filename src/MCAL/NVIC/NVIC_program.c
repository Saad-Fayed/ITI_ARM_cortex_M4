/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : NVIC_program.c             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Function Implementation of NVIC Peripheral  */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void NVIC_voidInit(void)
{
	/* Local Variable for the Value of AIRCR Register */
	u32 Local_u32RegisterValue;

	/* Set Configuration System SW Priority */
	Local_u32RegisterValue = VECT_KEY | (PRIORITY_CONFIG << 8);

	/* Assign the Value to AIRCR Register */
	SCB_AIRCR = Local_u32RegisterValue;
}

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptID)
{
	/* Calculating the Register where this Interrupt ID is Located */
	u8 Local_u8IntIDReg = Copy_u8InterruptID/32;

	/* Calculating the Bit where this Interrupt ID is Located */
	u8 Local_u8IntIDBit = Copy_u8InterruptID%32;

	/* This Function will Set ISE Register Where
	 * 1 ==> SET
	 * 0 ==> NoEffect */
	NVIC->ISER[Local_u8IntIDReg] = (1<<Local_u8IntIDBit);
}

void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptID)
{
	/* Calculating the Register where this Interrupt ID is Located */
	u8 Local_u8IntIDReg = Copy_u8InterruptID/32;

	/* Calculating the Bit where this Interrupt ID is Located */
	u8 Local_u8IntIDBit = Copy_u8InterruptID%32;

	/* This Function will Clear ICE Register Where
	 * 1 ==> Clear
	 * 0 ==> NoEffect */
	NVIC->ICER[Local_u8IntIDReg] = (1<<Local_u8IntIDBit);
}

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	/* Calculating the Register where this Interrupt ID is Located */
	u8 Local_u8IntIDReg = Copy_u8InterruptID/32;

	/* Calculating the Bit where this Interrupt ID is Located */
	u8 Local_u8IntIDBit = Copy_u8InterruptID%32;

	/* This Function will Set ISP Register Where
	 * 1 ==> SET
	 * 0 ==> NoEffect */
	NVIC->ISPR[Local_u8IntIDReg] = (1<<Local_u8IntIDBit);
}

void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	/* Calculating the Register where this Interrupt ID is Located */
	u8 Local_u8IntIDReg = Copy_u8InterruptID/32;

	/* Calculating the Bit where this Interrupt ID is Located */
	u8 Local_u8IntIDBit = Copy_u8InterruptID%32;

	/* This Function will Clear ICP Register Where
	 * 1 ==> Clear
	 * 0 ==> NoEffect */
	NVIC->ICPR[Local_u8IntIDReg] = (1<<Local_u8IntIDBit);
}

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8InterruptID)
{
	/* Calculating the Register where this Interrupt ID is Located */
	u8 Local_u8IntIDReg = Copy_u8InterruptID/32;

	/* Calculating the Bit where this Interrupt ID is Located */
	u8 Local_u8IntIDBit = Copy_u8InterruptID%32;

	/* Local Variable To Hold the Reading of the Flag */
	u8 Local_u8ActiveFlageReading;

	/* This Function Will Read IAB Register where
	 * 1 ==> Active
	 * 0 ==> Not-Active */
	Local_u8ActiveFlageReading = GET_BIT(Local_u8IntIDReg,Local_u8IntIDBit);

	/* Return the Reading of the Flag */
	return Local_u8ActiveFlageReading;
}

void NVIC_setSWPriority(u8 Copy_u8GroupPri,u8 Copy_u8SubPri ,u8 Copy_u8InterruptID)
{
	/* Setting Both Group and Sub into the High 4bits */
	NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri << (7 - PRIORITY_CONFIG));
	NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri << (PRIORITY_CONFIG - 3));

	/*#if (PRIORITY_CONFIG == GROUP_4_SUB_0)
		{
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri<<4);
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri<<0);
		}
	#elif (PRIORITY_CONFIG == GROUP_3_SUB_1)
		{
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri<<3);
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri<<1);
		}
	#elif (PRIORITY_CONFIG == GROUP_2_SUB_2)
		{
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri<<2);
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri<<2);
		}
	#elif (PRIORITY_CONFIG == GROUP_1_SUB_3)
		{
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri<<1);
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri<<3);
		}
	#elif (PRIORITY_CONFIG == GROUP_0_SUB_4)
		{
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8GroupPri<<0);
			NVIC->IPR[Copy_u8InterruptID] = (Copy_u8SubPri<<4);
		}
	#endif */
}
