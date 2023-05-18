/************************************************************************/
/*Author      : Saad Mohamed Saad									    */
/*File Name   : KPD_private.h                                           */
/*Layer       : HAL	    							 	        	    */
/*Description : This file contains private parameters of KPD module     */
/*Date        : 18 May 2023                                             */
/************************************************************************/

#ifndef HAL_KPD_KPD_PRIVATE_H_
#define HAL_KPD_KPD_PRIVATE_H_

/*************************************************************************/
/***************************Private Macros********************************/
/*************************************************************************/

/*	A structure of type StrKPD_t that contains
 *  the pins used for the keypad.*/
typedef struct
{
	u8 KPD_PIN_R1;
	u8 KPD_PIN_R2;
	u8 KPD_PIN_R3;
	u8 KPD_PIN_R4;
	u8 KPD_PIN_C1;
	u8 KPD_PIN_C2;
	u8 KPD_PIN_C3;
	u8 KPD_PIN_C4;
}StrKPD_t;

#endif /* HAL_KPD_KPD_PRIVATE_H_ */
