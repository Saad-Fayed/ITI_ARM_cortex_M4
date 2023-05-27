/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : STK_private.h             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains private parameters of STK Peripheral        */
/*Date        : 26 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

/*************************************************************************/
/*****************************Private Macros******************************/
/*************************************************************************/

#define SINGLE    0
#define PERIODIC  1

typedef struct
{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
}STK_REG_t;

#define STK ((STK_REG_t *)(0xE000E010))


#endif /* MCAL_STK_STK_PRIVATE_H_ */
