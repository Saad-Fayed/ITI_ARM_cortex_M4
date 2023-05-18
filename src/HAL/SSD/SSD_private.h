/*
 * SSD_private.h
 *
 *  Created on: May 17, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_

/*************************************************************************/
/***************************Private Macros********************************/
/*************************************************************************/

#define COMMON_CATHOD_SSD   1
#define COMMON_ANODE_SSD    2

typedef struct
{
	u8 SSD_Led_A_Pin;
	u8 SSD_Led_B_Pin;
	u8 SSD_Led_C_Pin;
	u8 SSD_Led_D_Pin;
	u8 SSD_Led_E_Pin;
	u8 SSD_Led_F_Pin;
	u8 SSD_Led_G_Pin;
	u8 SSD_Control_Pin;
	u8 SSD_Type;
}StrSSD_t;




#endif /* HAL_SSD_SSD_PRIVATE_H_ */
