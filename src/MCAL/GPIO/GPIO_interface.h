/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

/*Microcontroller's Ports*/
#define GPIO_PORTA	1
#define GPIO_PORTB	2
#define GPIO_PORTC	3

/*Output Pin Modes*/
#define GPIO_PUSH_PULL	0
#define GPIO_OPEN_DRAIN 1

/*Output Pin Speed*/
#define GPIO_LOW_SPEED			0
#define GPIO_MED_SPEED			1
#define GPIO_HIGH_SPEED		    2
#define GPIO_VERY_HIGH_SPEED	3

/*Output Pin Value*/
#define GPIO_OUTPUT_HIGH	1
#define GPIO_OUTPUT_LOW		0

/*Input Pin Modes*/
#define GPIO_INPUT_FLOAT		0
#define GPIO_INPUT_PULL_UP		1
#define GPIO_INPUT_PULL_DOWN	2

/*Port's Pins*/
#define GPIO_PIN0 	0
#define GPIO_PIN1 	1
#define GPIO_PIN2 	2
#define GPIO_PIN3 	3
#define GPIO_PIN4 	4
#define GPIO_PIN5 	5
#define GPIO_PIN6 	6
#define GPIO_PIN7 	7
#define GPIO_PIN8 	8
#define GPIO_PIN9 	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*This Function is to Initialize any pin to be an output Pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinType, u8 Copy_u8PinSpeed);

/*This Function is to Initialize any pin to be an input Pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PullMode);

/*This Functions is to Set the Pin Output Value[HIGH-LOW]*/
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);

/*This Function Shall Return the input Pin Value*/
u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
