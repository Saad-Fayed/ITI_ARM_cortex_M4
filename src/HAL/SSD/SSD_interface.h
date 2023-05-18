/*
 * SSD_interface.h
 *
 *  Created on: May 17, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

#define SSD_NUM_0  0b0111111
#define SSD_NUM_1  0b0000110
#define SSD_NUM_2  0b1011011
#define SSD_NUM_3  0b1001111
#define SSD_NUM_4  0b1100110
#define SSD_NUM_5  0b1101101
#define SSD_NUM_6  0b1111101
#define SSD_NUM_7  0b0000111
#define SSD_NUM_8  0b1111111
#define SSD_NUM_9  0b1101111

/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*This Function Shall Initialize All SSD Pins as OutPut*/
void SSD_voidInit(StrSSD_t * Copy_PStr_SSD);

/*This Function Shall Turn On the SSD Activate Control Common Pin*/
void SSD_voidTurnOn(StrSSD_t * Copy_PStr_SSD);

/*This Function Shall Turn Off the SSD Deactivate Control Common Pin*/
void SSD_voidTurnOff(StrSSD_t * Copy_PStr_SSD);

/*This Function Shall Display A Number on the SSD*/
void SSD_voidDisplayNumber(StrSSD_t * Copy_PStr_SSD,u8 Copy_u8Number);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
