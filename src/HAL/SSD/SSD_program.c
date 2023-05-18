/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : SSD_program.c             	                                   */
/*Layer       : HAL		    						  		                   */
/*Description : This file contains Function Implementation of SSD Module	   */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SSD_private.h"
#include "SSD_interface.h"

void SSD_voidInit(StrSSD_t * Copy_PStr_SSD)
{
	/* Initialize the pins connected to the SSD segments as output pins with low speed
	 * and push-pull configuration */
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_A_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_B_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_C_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_D_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_E_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_F_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Led_G_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_SSD->SSD_Control_Pin,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
}

void SSD_voidTurnOn(StrSSD_t * Copy_PStr_SSD)
{
	/* Set the control pin to the appropriate value depending on the type of the SSD */
	if(Copy_PStr_SSD->SSD_Type == COMMON_CATHOD_SSD) // Common Ground
	{
		GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Control_Pin,GPIO_OUTPUT_LOW);
	}
	else if(Copy_PStr_SSD->SSD_Type == COMMON_ANODE_SSD) // Common VCC
	{
		GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Control_Pin,GPIO_OUTPUT_HIGH);
	}
}

void SSD_voidTurnOff(StrSSD_t * Copy_PStr_SSD)
{
	/* Set the control pin to the opposite value of what was set in SSD_voidTurnOn
	 *  to turn off the SSD */
	if(Copy_PStr_SSD->SSD_Type == COMMON_CATHOD_SSD) // Common VCC
	{
		GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Control_Pin,GPIO_OUTPUT_HIGH);
	}
	else if(Copy_PStr_SSD->SSD_Type == COMMON_ANODE_SSD) // Common Ground
	{
		GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Control_Pin,GPIO_OUTPUT_LOW);
	}
}

void SSD_voidDisplayNumber(StrSSD_t * Copy_PStr_SSD,u8 Copy_u8Number)
{
	u8 Local_u8Number = 0 ;

	/* Determine the number to be displayed on the SSD based on its type */
	if(Copy_PStr_SSD->SSD_Type == COMMON_CATHOD_SSD) // Common VCC
	{
		Local_u8Number = Copy_u8Number;
	}
	else if(Copy_PStr_SSD->SSD_Type == COMMON_ANODE_SSD) // Common Ground
	{
		Local_u8Number = (~ Copy_u8Number);
	}

	/* Set the appropriate values on the pins connected to the SSD segments
	 * based on the number to be displayed */
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_A_Pin , ((Local_u8Number >> 0) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_B_Pin , ((Local_u8Number >> 1) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_C_Pin , ((Local_u8Number >> 2) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_D_Pin , ((Local_u8Number >> 3) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_E_Pin , ((Local_u8Number >> 4) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_F_Pin , ((Local_u8Number >> 5) & 1));
	GPIO_voidSetOutputPinValue(Copy_PStr_SSD->SSD_Led_G_Pin , ((Local_u8Number >> 6) & 1));
}
