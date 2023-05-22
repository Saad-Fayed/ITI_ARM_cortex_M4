/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : NVIC_private.h             	                                   */
/*Layer       : MCAL		    						  		               */
/*Description : This file contains private parameters of NVIC Peripheral       */
/*Date        : 22 May 2023                                                    */
/*******************************************************************************/

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

/*************************************************************************/
/*****************************Private Macros******************************/
/*************************************************************************/

/* Macros for Configuring SW Priority Groups and Subs */
#define GROUP_4_SUB_0	3	// Support 16 Groups and 0 Subs (Nesting Level Up to 16)
#define GROUP_3_SUB_1	4	// Support  8 Groups and 2 Subs
#define GROUP_2_SUB_2	5	// Support  4 Groups and 4 Subs
#define GROUP_1_SUB_3	6	// Support  2 Groups and 8 Subs
#define GROUP_0_SUB_4	7	// Support  0 Groups and 16 Subs (No Nesting Supported)

/* This Key is used to Activate Writing on the SCB_AIRCR Register
 * After Writing the Key will be Flipped to (0xFA05) To Prevent
 * Noise or Mistaken Writing on this Register */
#define VECT_KEY (0x05FA0000)

/* Base Addresses For NVIC Registers */
#define NVIC_BASE_ADDRESS (0xE000E100)
#define SCB_AIRCR_BASE_ADDRESS (0xE000D0C)

typedef struct
{
	volatile u32 ISER[8];		// Interrupt Set Enable Registers. Used to enable specific interrupts.
	volatile u32 RESERVED1[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ICER[8];       // Interrupt Clear Enable Registers. Used to disable specific interrupts.
	volatile u32 RESERVED2[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ISPR[8];       // Interrupt Set Pending Registers. Used to Fire interrupts Instantly for Testing Purposes.
	volatile u32 RESERVED3[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ICPR[8];       // Interrupt Clear Pending Registers. Used to clear interrupts Instantly for Testing Purposes.
	volatile u32 RESERVED4[24]; // 24 32-bit registers reserved for future use.
	volatile u32 IABR[8];       // Interrupt Active Bit Registers. Used to read the active status of specific interrupts.
	volatile u32 RESERVED5[56]; // 56 32-bit registers reserved for future use.
	volatile u8 IPR[240];       /* Interrupt Priority Registers. Used to set the priority level of specific interrupts.
								 * this 240 Array of u8 is instead Array of 8 u32 as Each U8
								 * Is used to Control a Specific Interrupt */
}NVIC_REG_t;

/* Pointer to STRUCT */
#define NVIC  ((volatile NVIC_REG_t *)NVIC_BASE_ADDRESS)

/* Application interrupt and reset control register
 * This Register Located in System Code Block Peripheral.
 * Used to configure How to Divide SoftWare Priority Between Group and Sub  */
#define SCB_AIRCR  (*(volatile u32 *)SCB_AIRCR_BASE_ADDRESS)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
