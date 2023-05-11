/*
 * GPIO_program.c
 *
 *  Created on: May 11, 2023
 *      Author: LENOVO
 */

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/


void GPIO_voidInitOutputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinType, u8 Copy_u8PinSpeed)
{
	switch(Copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:

			/*Set Direction of Pin to be Output using (Bit Masking)*/
			GPIOA->MODER &= (~(0b11 << (Copy_u8PinID*2)));      //Clear Pin Bits
			GPIOA->MODER |= (0b01 << (Copy_u8PinID*2)); 		//Set Pin to Output

			/*Set Speed of the Output pin using (Bit Masking)*/
			GPIOA->OSPEEDR &= (~(0b11 << (Copy_u8PinID*2))) ;  		     //Clear Pin Bits
			GPIOA->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID*2)); 	 //Set Type as Configured

			/*Set Type of the Output pin using (Bit Masking)*/
			WRT_BIT(GPIOA->OTYPER,Copy_u8PinID,Copy_u8PinType);		//Set Pin Type

			break;

		case GPIO_PORTB:

			/*Set Direction of Pin to be Output using (Bit Masking)*/
			GPIOB->MODER &= (~(0b11 << (Copy_u8PinID*2)));      //Clear Pin Bits
			GPIOB->MODER |= (0b01 << (Copy_u8PinID*2)); 		//Set Pin to Output

			/*Set Speed of the Output pin using (Bit Masking)*/
			GPIOB->OSPEEDR &= (~(0b11 << (Copy_u8PinID*2))) ;  		     //Clear Pin Bits
			GPIOB->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID*2)); 	 //Set Type as Configured

			/*Set Type of the Output pin using (Bit Masking)*/
			WRT_BIT(GPIOB->OTYPER,Copy_u8PinID,Copy_u8PinType);		//Set Pin Type

			break;

		case GPIO_PORTC:

			/*Set Direction of Pin to be Output using (Bit Masking)*/
			GPIOC->MODER &= (~(0b11 << (Copy_u8PinID*2)));      //Clear Pin Bits
			GPIOC->MODER |= (0b01 << (Copy_u8PinID*2)); 		//Set Pin to Output

			/*Set Speed of the Output pin using (Bit Masking)*/
			GPIOC->OSPEEDR &= (~(0b11 << (Copy_u8PinID*2))) ;  		     //Clear Pin Bits
			GPIOC->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID*2)); 	 //Set Type as Configured

			/*Set Type of the Output pin using (Bit Masking)*/
			WRT_BIT(GPIOC->OTYPER,Copy_u8PinID,Copy_u8PinType);		//Set Pin Type

			break;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PullMode)
{
//	switch(Copy_u8PortID) //Switching over Micro's Ports
//	{
//		case GPIO_PORTA:
//
//			/*Set Direction of Pin to be Input using (Bit Masking)*/
//			GPIOA->MODER &= (~(0b11 << (Copy_u8PinID*2)));      //Clear Pin Bits
//			GPIOA->MODER |= (0b00 << (Copy_u8PinID*2)); 		//Set Pin to Input
//
//			/*Set Mode of Input Pin using (Bit Masking)*/
//			GPIOA->PUPDR &= (~(0b11 << (Copy_u8PinID*2))) ;  		     //Clear Pin Bits
//			GPIOA->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID*2)); 	 //Set Type as Configured
//
//			/*Set Type of the Output pin using (Bit Masking)*/
//			WRT_BIT(GPIOA->OTYPER,Copy_u8PinID,Copy_u8PinType);		//Set Pin Type
//
//			break;
//	}
}

void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	switch(Copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:

			/*Set OutPut Pin Vlaue using (Bit Masking)*/
			WRT_BIT(GPIOA->ODR , Copy_u8PinID , Copy_u8Value );

			break;
	case GPIO_PORTB:

			/*Set OutPut Pin Vlaue using (Bit Masking)*/
			WRT_BIT(GPIOB->ODR , Copy_u8PinID , Copy_u8Value );

			break;
	case GPIO_PORTC:

			/*Set OutPut Pin Vlaue using (Bit Masking)*/
			WRT_BIT(GPIOC->ODR , Copy_u8PinID , Copy_u8Value );

			break;
	}
}

u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 x=5;
	return x;
}
