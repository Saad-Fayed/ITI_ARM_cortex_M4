/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : GPIO_program.c             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Function Implementation of GPIO Peripheral  */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

/*************************************************************************/
/***********************Functions' Implementation*************************/
/*************************************************************************/


void GPIO_voidInitOutputPin(u8 Copy_u8PinID, u8 Copy_u8PinType, u8 Copy_u8PinSpeed)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
			{
				/*Do Nothing*/
			}
			else
			{
				/*Set Direction of Pin to be Output using (Bit Masking)*/
				GPIOA->MODER &= (~(0b11 << (Local_u8PinID*2)));      //Clear Pin Bits
				GPIOA->MODER |= (0b01 << (Local_u8PinID*2)); 		//Set Pin to Output

				/*Set Speed of the Output pin using (Bit Masking)*/
				GPIOA->OSPEEDR &= (~(0b11 << (Local_u8PinID*2))) ;  		     //Clear Pin Bits
				GPIOA->OSPEEDR |= (Copy_u8PinSpeed << (Local_u8PinID*2)); 	 //Set Type as Configured

				/*Set Type of the Output pin using (Bit Masking)*/
				WRT_BIT(GPIOA->OTYPER,Local_u8PinID,Copy_u8PinType);		//Set Pin Type
			}
			break;

		case GPIO_PORTB:
			if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
				{
					/*Do Nothing*/
				}
				else
				{
					/*Set Direction of Pin to be Output using (Bit Masking)*/
					GPIOB->MODER &= (~(0b11 << (Local_u8PinID*2)));      //Clear Pin Bits
					GPIOB->MODER |= (0b01 << (Local_u8PinID*2)); 		//Set Pin to Output

					/*Set Speed of the Output pin using (Bit Masking)*/
					GPIOB->OSPEEDR &= (~(0b11 << (Local_u8PinID*2))) ;  		     //Clear Pin Bits
					GPIOB->OSPEEDR |= (Copy_u8PinSpeed << (Local_u8PinID*2)); 	 //Set Type as Configured

					/*Set Type of the Output pin using (Bit Masking)*/
					WRT_BIT(GPIOB->OTYPER,Local_u8PinID,Copy_u8PinType);		//Set Pin Type
				}
			break;

		case GPIO_PORTC:

			/*Set Direction of Pin to be Output using (Bit Masking)*/
			GPIOC->MODER &= (~(0b11 << (Local_u8PinID*2)));      //Clear Pin Bits
			GPIOC->MODER |= (0b01 << (Local_u8PinID*2)); 		//Set Pin to Output

			/*Set Speed of the Output pin using (Bit Masking)*/
			GPIOC->OSPEEDR &= (~(0b11 << (Local_u8PinID*2))) ;  		     //Clear Pin Bits
			GPIOC->OSPEEDR |= (Copy_u8PinSpeed << (Local_u8PinID*2)); 	 //Set Type as Configured

			/*Set Type of the Output pin using (Bit Masking)*/
			WRT_BIT(GPIOC->OTYPER,Local_u8PinID,Copy_u8PinType);		//Set Pin Type

			break;
	}
}


void GPIO_voidSetOutputPinValue(u8 Copy_u8PinID, u8 Copy_u8Value)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
				{
					/*Do Nothing*/
				}
				else
				{
					/*Set OutPut Pin Value using (Bit Masking)*/
					WRT_BIT(GPIOA->ODR , Local_u8PinID , Copy_u8Value );
				}
			break;
		case GPIO_PORTB:
			if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
				{
					/*Do Nothing*/
				}
				else
				{
					/*Set OutPut Pin Value using (Bit Masking)*/
					WRT_BIT(GPIOB->ODR , Local_u8PinID , Copy_u8Value );
				}
			break;
	case GPIO_PORTC:

			/*Set OutPut Pin Value using (Bit Masking)*/
			WRT_BIT(GPIOC->ODR , Local_u8PinID , Copy_u8Value );

			break;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PinID, u8 Copy_u8PullMode)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
				{
					/*Do Nothing*/
				}
				else
				{
					/*Set Direction of Pin to be Input using (Bit Masking)*/
					/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
					 * So The Mask Will Do the Job*/
					GPIOA->MODER &= (~(0b11 << (Local_u8PinID*2)));             //Clear Pin Bits

					/*Set Mode of Input Pin using (Bit Masking)*/
					GPIOA->PUPDR &= (~(0b11 << (Local_u8PinID*2))) ;  		   //Clear Pin Bits
					GPIOA->PUPDR |= (Copy_u8PullMode << (Local_u8PinID*2)); 	   //Set Type as Configured
				}
			break;
		case GPIO_PORTB:
			if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
				{
					/*Do Nothing*/
				}
				else
				{
					/*Set Direction of Pin to be Input using (Bit Masking)*/
					/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
					 * So The Mask Will Do the Job*/
					GPIOB->MODER &= (~(0b11 << (Local_u8PinID*2)));      	   //Clear Pin Bits

					/*Set Mode of Input Pin using (Bit Masking)*/
					GPIOB->PUPDR &= (~(0b11 << (Local_u8PinID*2))) ;  		   //Clear Pin Bits
					GPIOB->PUPDR |= (Copy_u8PullMode << (Local_u8PinID*2)); 	   //Set Type as Configured
				}
			break;
		case GPIO_PORTC:

			/*Set Direction of Pin to be Input using (Bit Masking)*/
			/*To Set Pin to Input Mode we Insert 00 in their Configuration Bits in MODE Register
			 * So The Mask Will Do the Job*/
			GPIOC->MODER &= (~(0b11 << (Local_u8PinID*2)));      	   //Clear Pin Bits

			/*Set Mode of Input Pin using (Bit Masking)*/
			GPIOC->PUPDR &= (~(0b11 << (Local_u8PinID*2))) ;  		   //Clear Pin Bits
			GPIOC->PUPDR |= (Copy_u8PullMode << (Local_u8PinID*2)); 	   //Set Type as Configured

			break;
	}
}

u8 GPIO_u8GetInputPinValue(u8 Copy_u8PinID)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;
	u8 Local_u8PinValue;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
				{
					/*Do Nothing*/
				}
				else
				{
					Local_u8PinValue = (GET_BIT(GPIOA->IDR,Local_u8PinID));
				}
			break;

		case GPIO_PORTB:
			if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
				{
					/*Do Nothing*/
				}
				else
				{
					Local_u8PinValue = (GET_BIT(GPIOB->IDR,Local_u8PinID));
				}

			break;
		case GPIO_PORTC:

			Local_u8PinValue = (GET_BIT(GPIOC->IDR,Local_u8PinID));

			break;
	}
	return Local_u8PinValue ;
}

void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PinID, u8 Copy_u8Value)
{
	u32 Local_u32RegisterValue = 0;
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
		{
			case GPIO_PORTA:
				if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
					{
						/*Do Nothing*/
					}
					else
					{
						switch (Copy_u8Value) //Switching over pin Value
						{
							/*Set Pin Value -> Access Bits 0~15*/
							case GPIO_OUTPUT_HIGH:
								Local_u32RegisterValue = (1 << Local_u8PinID);
								break;
							/*Reset Pin Value -> Access Bits 16~31*/
							case GPIO_OUTPUT_LOW:
								Local_u32RegisterValue = (1 << (Local_u8PinID+16));
								break;
						}
						GPIOA->BSRR = Local_u32RegisterValue;
					}
				break;

			case GPIO_PORTB:
				if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
					{
						/*Do Nothing*/
					}
					else
					{
						switch (Copy_u8Value) //Switching over pin Value
						{
							/*Set Pin Value -> Access Bits 0~15*/
							case GPIO_OUTPUT_HIGH:
								Local_u32RegisterValue = (1 << Local_u8PinID);
								break;
							/*Reset Pin Value -> Access Bits 16~31*/
							case GPIO_OUTPUT_LOW:
								Local_u32RegisterValue = (1 << (Local_u8PinID+16));
								break;
						}
						GPIOB->BSRR = Local_u32RegisterValue;
					}
						break;

			case GPIO_PORTC:
				switch (Copy_u8Value) //Switching over pin Value
				{
					/*Set Pin Value -> Access Bits 0~15*/
					case GPIO_OUTPUT_HIGH:
						Local_u32RegisterValue = (1 << Local_u8PinID);
						break;
					/*Reset Pin Value -> Access Bits 16~31*/
					case GPIO_OUTPUT_LOW:
						Local_u32RegisterValue = (1 << (Local_u8PinID+16));
						break;
				}
				GPIOC->BSRR = Local_u32RegisterValue;
				break;
		}
}

void GPIO_voidInitOutputPort(u8 Copy_u8PortID, u8 Copy_u8PortType, u8 Copy_u8PortSpeed)
{
	u8 Local_u8Iterator;
	switch(Copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
			{
				/*Set Direction of Pin to be Output using (Bit Masking)*/
				GPIOA->MODER &= (~(0b11 << (Local_u8Iterator*2)));      //Clear Pin Bits
				GPIOA->MODER |= (0b01 << (Local_u8Iterator*2)); 		//Set Pin to Output

				/*Set Speed of the Output pin using (Bit Masking)*/
				GPIOA->OSPEEDR &= (~(0b11 << (Local_u8Iterator*2))) ;  		     //Clear Pin Bits
				GPIOA->OSPEEDR |= (Copy_u8PortSpeed << (Local_u8Iterator*2)); 	 //Set Type as Configured

				/*Set Type of the Output pin using (Bit Masking)*/
				WRT_BIT(GPIOA->OTYPER,Local_u8Iterator,Copy_u8PortType);		//Set Pin Type
			}
			break;
		case GPIO_PORTB:
			for (Local_u8Iterator=8;Local_u8Iterator<16;Local_u8Iterator++)
			{
				/*Set Direction of Pin to be Output using (Bit Masking)*/
				GPIOB->MODER &= (~(0b11 << (Local_u8Iterator*2)));      //Clear Pin Bits
				GPIOB->MODER |= (0b01 << (Local_u8Iterator*2)); 		//Set Pin to Output

				/*Set Speed of the Output pin using (Bit Masking)*/
				GPIOB->OSPEEDR &= (~(0b11 << (Local_u8Iterator*2))) ;  		     //Clear Pin Bits
				GPIOB->OSPEEDR |= (Copy_u8PortSpeed << (Local_u8Iterator*2)); 	 //Set Type as Configured

				/*Set Type of the Output pin using (Bit Masking)*/
				WRT_BIT(GPIOB->OTYPER,Local_u8Iterator,Copy_u8PortType);		//Set Pin Type
			}
			break;
		case GPIO_PORTC:
			for (Local_u8Iterator=13;Local_u8Iterator<16;Local_u8Iterator++)
			{
				/*Set Direction of Pin to be Output using (Bit Masking)*/
				GPIOC->MODER &= (~(0b11 << (Local_u8Iterator*2)));      //Clear Pin Bits
				GPIOC->MODER |= (0b01 << (Local_u8Iterator*2)); 		//Set Pin to Output

				/*Set Speed of the Output pin using (Bit Masking)*/
				GPIOC->OSPEEDR &= (~(0b11 << (Local_u8Iterator*2))) ;  		     //Clear Pin Bits
				GPIOC->OSPEEDR |= (Copy_u8PortSpeed << (Local_u8Iterator*2)); 	 //Set Type as Configured

				/*Set Type of the Output pin using (Bit Masking)*/
				WRT_BIT(GPIOC->OTYPER,Local_u8Iterator,Copy_u8PortType);		//Set Pin Type
			}
			break;
	}
}

void GPIO_voidSetOutputPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortID) //Switching over Micro's Ports
	{
		case GPIO_PORTA:
			/*Set OutPut Pin Value using (Bit Wise Operations)*/
			GPIOA->ODR = (Copy_u8PortValue);
			break;
		case GPIO_PORTB:
			/*Set OutPut Pin Value using (Bit Wise Operations)*/
			GPIOB->ODR = (Copy_u8PortValue << 9);
			break;
	}
}

void GPIO_voidSetAlternativeFunction(u8 Copy_u8PinID, u8 Copy_u8AlternativeFunction)
{
	u8 Local_u8PortID;
	u8 Local_u8PinID;

	Local_u8PortID = Copy_u8PinID / 16;
	Local_u8PinID = Copy_u8PinID % 16;

	switch(Local_u8PortID) //Switching over Micro's Ports
		{
			case GPIO_PORTA:
				if(Local_u8PinID == 13 || Local_u8PinID == 14 || Local_u8PinID == 15)
					{
						/*Do Nothing*/
					}
					else
					{
						if (Local_u8PinID>=0 && Local_u8PinID<=7) //Check if the Pin in AFRL OR AFRH
						{
							/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
							GPIOA->AFRL &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
							GPIOA->AFRL |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
						}
						else
						{
							/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
							GPIOA->AFRH &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
							GPIOA->AFRH |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
						}
					}
				break;
			case GPIO_PORTB:
				if(Local_u8PinID == 2 || Local_u8PinID == 3 || Local_u8PinID == 4)
					{
						/*Do Nothing*/
					}
					else
					{
						if (Local_u8PinID>=0 && Local_u8PinID<=7) //Check if the Pin in AFRL OR AFRH
						{
							/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
							GPIOB->AFRL &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
							GPIOB->AFRL |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
						}
						else
						{
							/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
							GPIOB->AFRH &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
							GPIOB->AFRH |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
						}
					}
				break;
			case GPIO_PORTC:
				if (Local_u8PinID>=0 && Local_u8PinID<=7) //Check if the Pin in AFRL OR AFRH
				{
					/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
					GPIOC->AFRL &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
					GPIOC->AFRL |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
				}
				else
				{
					/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
					GPIOC->AFRH &= (~(0b1111 << (Local_u8PinID*4))); 					//Clear the 4 Bits Responsible for Configuration
					GPIOC->AFRH |= (Copy_u8AlternativeFunction << (Local_u8PinID*4));	//Set AF as Configured
				}
				break;
		}
}
