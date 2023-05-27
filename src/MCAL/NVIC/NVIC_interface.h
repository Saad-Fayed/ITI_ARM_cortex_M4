/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : NVIC_interface.h             	                               */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Interfacing parameters of NVIC Peripheral   */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/* This Function will Initialize NVIC, Sets SW Priority Configurations */
void NVIC_voidInit(void);

/* This Function Shall Enable the interrupt specified by the given ID in the NVIC module */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptID);

/* This Function Shall Disable the interrupt specified by the given ID in the NVIC module */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptID);

/* This Function Shall Set the pending flag for the interrupt
 * specified by the given ID in the NVIC module */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptID);

/* This Function Shall Clear the pending flag for the interrupt
 * specified by the given ID in the NVIC module */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptID);

/* This Function Shall Return the Reading of the active flag for the interrupt
 * specified by the given ID in the NVIC module */
u8 NVIC_u8ReadActiveFlag(u8 Copy_u8InterruptID);

void NVIC_voidSetSWPriority(u8 Copy_u8GroupPri,u8 Copy_u8SubPri ,u8 Copy_u8InterruptID);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
