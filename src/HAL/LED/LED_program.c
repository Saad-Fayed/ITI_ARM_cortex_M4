/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : LED_program.c             	                                   */
/*Layer       : HAL		    						  		                   */
/*Description : This file contains Function Implementation of LED Module	   */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "LED_interface.h"
/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/

void LED_voidInit(u8 Copy_u8PinID)
{
	/*This Function is to Initialize Desired pin to Push_Pull, Low Speed, Output Pin*/
	GPIO_voidInitOutputPin(Copy_u8PinID,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
}


void LED_voidTurnOn(u8 Copy_u8PinID)
{
	/*This Function is to Set the Pin Value to High*/
	GPIO_voidSetOutputPinValue(Copy_u8PinID,GPIO_OUTPUT_HIGH);
}

void LED_voidTurnOff(u8 Copy_u8PinID)
{
	/*This Function is to Set the Pin Value to Low*/
	GPIO_voidSetOutputPinValue(Copy_u8PinID,GPIO_OUTPUT_LOW);
}

void LED_voidToggle(u8 Copy_u8PinID)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	/* Extract the port ID and pin ID from the input pin ID */
	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	/* This Function Shall Toggle LED */
	TGL_BIT(Local_u8PortID,Local_u8PinID);
}
