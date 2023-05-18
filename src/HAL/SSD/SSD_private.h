/************************************************************************/
/*Author      : Saad Mohamed Saad									    */
/*File Name   : SSD_private.h                                           */
/*Layer       : HAL	    							 	        	    */
/*Description : This file contains private parameters of SSD module     */
/*Date        : 18 May 2023                                             */
/************************************************************************/

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
