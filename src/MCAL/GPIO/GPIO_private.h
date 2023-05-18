/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : GPIO_private.h             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains private parameters of GPIO Peripheral       */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_START_ADDRESS (0x40020000)
#define GPIOB_START_ADDRESS (0x40020400)
#define GPIOC_START_ADDRESS (0x40020800)

typedef struct
{
	volatile u32 MODER  ; //This REGister is to Set Mode For any pins.
	volatile u32 OTYPER ; //This Register is to set the type of output pins.
	volatile u32 OSPEEDR; //This Register is to set the speed of the output pins.
	volatile u32 PUPDR  ; //This Register is to select whether pull up or pull down input pins.
	volatile u32 IDR    ; //This Register is to get the value of input pins.
	volatile u32 ODR    ; //This Register is to set the value of output pins.
	volatile u32 BSRR   ; //This Register is to Set the Value of output pins in Atomic Access
	volatile u32 LCKR   ; //This Register is to Lock Configuration of GPIO registers
	volatile u32 AFRL   ; //This Register is to configure alternate function For Pins 0~7
	volatile u32 AFRH   ; //This Register is to configure alternate function For Pins 8~15
}GPIO_REG_t;

/*Pointer to Struct*/
#define GPIOA ((volatile GPIO_REG_t *)GPIOA_START_ADDRESS)
#define GPIOB ((volatile GPIO_REG_t *)GPIOB_START_ADDRESS)
#define GPIOC ((volatile GPIO_REG_t *)GPIOC_START_ADDRESS)

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
