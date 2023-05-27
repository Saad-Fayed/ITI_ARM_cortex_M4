/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : NVIC_config.h             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains Configuration Parameters of NVIC Peripheral */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_NVIC_NVIC_CONFIG_H_
#define MCAL_NVIC_NVIC_CONFIG_H_

/* This Conf. Parameter Is used to Set SW Priority */
/*	GROUP_4_SUB_0 (Nesting Level Up to 16)
	GROUP_3_SUB_1
	GROUP_2_SUB_2
	GROUP_1_SUB_3
	GROUP_0_SUB_4 (No Nesting Supported) */
#define PRIORITY_CONFIG GROUP_0_SUB_4

#endif /* MCAL_NVIC_NVIC_CONFIG_H_ */
