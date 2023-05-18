/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : GPIO_interface.h             	                               */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Interfacing parameters of GPIO Peripheral   */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

/*Microcontroller's Ports*/
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2

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

/*Alternative Function Moods*/
#define GPIO_AF0   0000
#define GPIO_AF1   0001
#define GPIO_AF2   0010
#define GPIO_AF3   0011
#define GPIO_AF4   0100
#define GPIO_AF5   0101
#define GPIO_AF6   0110
#define GPIO_AF7   0111
#define GPIO_AF8   1000
#define GPIO_AF9   1001
#define GPIO_AF10  1010
#define GPIO_AF11  1011
#define GPIO_AF12  1100
#define GPIO_AF13  1101
#define GPIO_AF14  1110
#define GPIO_AF15  1111

/*Port's Pins*/
/*  Port A  */
#define GPIO_PIN_A0 	0
#define GPIO_PIN_A1 	1
#define GPIO_PIN_A2 	2
#define GPIO_PIN_A3 	3
#define GPIO_PIN_A4 	4
#define GPIO_PIN_A5 	5
#define GPIO_PIN_A6 	6
#define GPIO_PIN_A7 	7
#define GPIO_PIN_A8 	8
#define GPIO_PIN_A9 	9
#define GPIO_PIN_A10	10
#define GPIO_PIN_A11	11
#define GPIO_PIN_A12	12
//#define GPIO_PIN_A13	13
//#define GPIO_PIN_A14	14
//#define GPIO_PIN_A15	15

/*  Port B  */
#define GPIO_PIN_B0 	16
#define GPIO_PIN_B1 	17
//#define GPIO_PIN_B2 	18
//#define GPIO_PIN_B3 	19
//#define GPIO_PIN_B4 	20
#define GPIO_PIN_B5 	21
#define GPIO_PIN_B6 	22
#define GPIO_PIN_B7 	23
#define GPIO_PIN_B8 	24
#define GPIO_PIN_B9 	25
#define GPIO_PIN_B10	26
#define GPIO_PIN_B11	27
#define GPIO_PIN_B12	28
#define GPIO_PIN_B13	29
#define GPIO_PIN_B14	30
#define GPIO_PIN_B15	31

/*  Port C  */
//#define GPIO_PIN_C0 	32
//#define GPIO_PIN_C1 	33
//#define GPIO_PIN_C2 	34
//#define GPIO_PIN_C3 	35
//#define GPIO_PIN_C4 	36
//#define GPIO_PIN_C5 	37
//#define GPIO_PIN_C6 	38
//#define GPIO_PIN_C7 	39
//#define GPIO_PIN_C8 	40
//#define GPIO_PIN_C9 	41
//#define GPIO_PIN_C10	42
//#define GPIO_PIN_C11	43
//#define GPIO_PIN_C12	44
#define GPIO_PIN_C13	45
#define GPIO_PIN_C14	46
#define GPIO_PIN_C15	47

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*This Function is to Initialize any pin to be an output Pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PinID, u8 Copy_u8PinType, u8 Copy_u8PinSpeed);

/*This Function is to Initialize any pin to be an input Pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PinID, u8 Copy_u8PullMode);

/*This Functions is to Set the Pin Output Value [HIGH-LOW]*/
void GPIO_voidSetOutputPinValue(u8 Copy_u8PinID, u8 Copy_u8Value);

/*This Function Shall Return the input Pin Value*/
u8 GPIO_u8GetInputPinValue(u8 Copy_u8PinID);

/*This Functions is to Set the Pin Output Value[HIGH-LOW] Atomically*/
void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PinID, u8 Copy_u8Value);

/*This Function is to Initialize any port to be Output Port
 * PortA pins 0~7
 * PortB pins 8~15
 * PortC pins 13~15*/
void GPIO_voidInitOutputPort(u8 Copy_u8PortID, u8 Copy_u8PortType, u8 Copy_u8PortSpeed);

/*This Function is to Set the Port Output Value [HIGH-LOW]*/
void GPIO_voidSetOutputPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);

/*This Function Shall Set Pins to an Alternative Function*/
void GPIO_voidSetAlternativeFunction(u8 Copy_u8PinID, u8 Copy_u8AlternativeFunction);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
