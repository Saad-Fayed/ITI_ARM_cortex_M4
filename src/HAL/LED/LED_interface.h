/*
 * LED_interface.h
 *
 *  Created on: May 17, 2023
 *      Author: LENOVO
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*This Function Shall Initialize the LED*/
void LED_voidInit(u8 Copy_u8PinID);

/*This Function Shall Turn ON led*/
void LED_voidTurnOn(u8 Copy_u8PinID);

/*This Function Shall Turn OFF led*/
void LED_voidTurnOff(u8 Copy_u8PinID);

/*This Function Shall Toggle led*/
void LED_voidToggle(u8 Copy_u8PinID);

#endif /* HAL_LED_LED_INTERFACE_H_ */
