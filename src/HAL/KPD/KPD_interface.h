/************************************************************************/
/*Author      : Saad Mohamed Saad									    */
/*File Name   : KPD_interface.h                                         */
/*Layer       : HAL									 	        	    */
/*Description : This file contains Interfacing parameters of KPD module */
/*Date        : 18 May 2023                                             */
/************************************************************************/

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*	This Function Shall Initialize
 *  Row Pins as Input -> Pull-up Resistors
 *  Column Pins as Output -> Low*/
void KPD_voidInit(StrKPD_t * Copy_PStr_KPD);

/*This Function Shall Return the Value of the Pressed Key*/
u8 KPD_u8GetPressedKey(StrKPD_t * Copy_PStr_KPD);


#endif /* HAL_KPD_KPD_INTERFACE_H_ */
