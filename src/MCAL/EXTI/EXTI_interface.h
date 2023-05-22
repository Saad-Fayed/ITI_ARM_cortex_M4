/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : EXTI_interface.h             	                               */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Interfacing parameters of EXTI Peripheral   */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/
#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

/* 16 Macros For EXTI Lines */

/* Macros For Sense Signals */
#define FALLING_EDGE	1
#define RISING_EDGE		2
#define ON_CHANGE		3

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/* This Function is Used to Enable EXTI */
void EXTI_voidEnableInt(u8 Copy_u8IntID , void(*Copy_ptrToFunc)(void));

/* This Function is Used to Disable EXTI */
void EXTI_voidDisableInt(u8 Copy_u8IntID);

/* This Function Shall Set Sense Signal */
void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8IntID);

/*  */
//void EXTI_voidSetLinePort(u8 Copy_u8IntID , u8 Copy_u8PortID);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
