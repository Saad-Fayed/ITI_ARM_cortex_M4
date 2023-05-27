/****************************************************************************/
/*Author      : Saad Mohamed Saad									        */
/*File Name   : LEDMTRX_interface.h                                         */
/*Layer       : HAL									 	        	        */
/*Description : This file contains Interfacing parameters of LEDMTRX module */
/*Date        : 27 May 2023                                                 */
/****************************************************************************/


#ifndef HAL_LEDMTRX_LEDMTRX_INTERFACE_H_
#define HAL_LEDMTRX_LEDMTRX_INTERFACE_H_

/* This Function Shall Initialize The LED Matrix */
void LEDMTRX_voidInit(void);

/* This Function is to Display a Specific Pattern Over LED Matrix */
void LEDMTRX_voidDisplayPattern(u8 Copy_u8PatternArray[], u32 Copy_u8TimeMilliSec);

/* This Function is to Deactivate All Columns and Turn LEDs off */
void LEDMTRX_voidTrunOff(void);

#endif /* HAL_LEDMTRX_LEDMTRX_INTERFACE_H_ */
