/*
 * GPIO_private.h
 *
 *  Created on: May 11, 2023
 *      Author: LENOVO
 */

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
}GPIO_REG_t;

/*Pointer to Struct*/
#define GPIOA ((volatile GPIO_REG_t *)GPIOA_START_ADDRESS)
#define GPIOB ((volatile GPIO_REG_t *)GPIOB_START_ADDRESS)
#define GPIOC ((volatile GPIO_REG_t *)GPIOC_START_ADDRESS)

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
