/************************************************************************/
/*Author      : Saad Mohamed Saad									    */
/*File Name   : SSD_interface.h                                         */
/*Layer       : HAL									 	        	    */
/*Description : This file contains Interfacing parameters of SSD module */
/*Date        : 18 May 2023                                             */
/************************************************************************/

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

/*	This Function Shall initializes the pins connected to the SSD segments and
 *  the control pin that selects the type of the SSD.*/
void SSD_voidInit(StrSSD_t * Copy_PStr_SSD);

/*	This Function Shall Turn On the SSD by setting the control pin to the appropriate
 *  value depending on the type of the SSD.*/
void SSD_voidTurnOn(StrSSD_t * Copy_PStr_SSD);

/*	This Function Shall Turn Off the SSD  by setting the control pin to the opposite value
 *  of what was set in SSD_void TurnOn.*/
void SSD_voidTurnOff(StrSSD_t * Copy_PStr_SSD);

/*	This Function Shall display a given number on the SSD by setting the appropriate values
 *  on the pins connected to the SSD segments. The function takes into account the type of
 *  the SSD and adjusts the displayed number accordingly.*/
void SSD_voidDisplayNumber(StrSSD_t * Copy_PStr_SSD,u8 Copy_u8Number);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
