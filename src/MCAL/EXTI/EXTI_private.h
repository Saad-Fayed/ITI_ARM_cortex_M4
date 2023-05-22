/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : EXTI_private.h             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains private parameters of EXTI Peripheral       */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/*************************************************************************/
/*****************************Private Macros******************************/
/*************************************************************************/

/* Base Addresses For NVIC Registers */
#define EXTI_BASE_ADDRESS (0x40013C00)

typedef struct
{
	volatile u32 IMR;	//Interrupt mask register. Used For
	volatile u32 EMR;	//Event mask register. Used For
	volatile u32 RTSR;  //Rising trigger selection register. Used For
	volatile u32 FTSR;  //Falling trigger selection register. Used For
	volatile u32 SWIER; //Software interrupt event register. Used For
	volatile u32 PR;	//Pending register. Used For
}EXTI_REG_t;

/* Pointer to STRUCT */
#define EXTI  ((volatile EXTI_REG_t *)EXTI_BASE_ADDRESS)



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
