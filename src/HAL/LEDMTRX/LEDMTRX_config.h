/******************************************************************************/
/*Author      : Saad Mohamed Saad									          */
/*File Name   : LEDMTRX_Config.h                                              */
/*Layer       : HAL								 	        	              */
/*Description : This file contains Configuration parameters of LEDMTRX module */
/*Date        : 27 May 2023                                                   */
/******************************************************************************/


#ifndef HAL_LEDMTRX_LEDMTRX_CONFIG_H_
#define HAL_LEDMTRX_LEDMTRX_CONFIG_H_

/*************************************************************************/
/***********************Configuration Parameters**************************/
/*************************************************************************/

/* LED Matrix Size */
#define COL_NUM		8
#define ROW_NUM		8

/*  */
#define COL0	GPIO_PIN_A0
#define COL1	GPIO_PIN_A1
#define COL2	GPIO_PIN_A2
#define COL3	GPIO_PIN_A3
#define COL4	GPIO_PIN_A4
#define COL5	GPIO_PIN_A5
#define COL6	GPIO_PIN_A6
#define COL7	GPIO_PIN_A7

#define ROW0	GPIO_PIN_B0
#define ROW1	GPIO_PIN_B1
#define ROW2	GPIO_PIN_B5
#define ROW3	GPIO_PIN_B6
#define ROW4	GPIO_PIN_B7
#define ROW5	GPIO_PIN_B8
#define ROW6	GPIO_PIN_B9
#define ROW7	GPIO_PIN_B10

#endif /* HAL_LEDMTRX_LEDMTRX_CONFIG_H_ */
