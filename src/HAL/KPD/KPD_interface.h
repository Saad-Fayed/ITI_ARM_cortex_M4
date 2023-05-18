/*
 * KPD_interface.h
 *
 *  Created on: May 18, 2023
 *      Author: LENOVO
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

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
