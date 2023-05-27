/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : LEDMTRX_program.c             	                               */
/*Layer       : HAL		    						  		                   */
/*Description : This file contains Function Implementation of LEDMTRX Module   */
/*Date        : 27 May 2023                                                    */
/*******************************************************************************/

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"
#include "LEDMTRX_interface.h"

/* Local Array to Iterate over LED Matrix Rows */
u8 Local_u8RowsArray[ROW_NUM] = {ROW0,ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7};

/* Local Array to Iterate over LED Matrix Columns */
u8 Local_u8ColsArray[COL_NUM] = {COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7};

void LEDMTRX_voidInit(void)
{
	/* Local Iterator to Loop over row and columns */
	u8 Local_u8Iterator = 0;

	/* Set all Row's and Column's Pins to be (o/p, pushpull, lowSpeed) */
	for(Local_u8Iterator = 0 ; Local_u8Iterator < ROW_NUM ; Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8RowsArray[Local_u8Iterator], GPIO_PUSH_PULL, GPIO_LOW_SPEED);
	}
	for(Local_u8Iterator = 0 ; Local_u8Iterator < COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8ColsArray[Local_u8Iterator], GPIO_PUSH_PULL, GPIO_LOW_SPEED);
	}

	/* Set all Columns to be Initially HIGH (Deactivate Columns)*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator < COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8Iterator], GPIO_OUTPUT_HIGH);
	}

	/* Set all Rows to be Initially LOW (Turn LEDs Off)*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator < ROW_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8Iterator], GPIO_OUTPUT_LOW);
	}
}

void LEDMTRX_voidTrunOff(void)
{
	/* Local Iterator to Loop over row and columns */
	u8 Local_u8Iterator = 0;

	/* Set all Columns to be Initially HIGH (Deactivate Columns)*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator < COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8Iterator], GPIO_OUTPUT_HIGH);
	}

	/* Set all Rows to be Initially LOW (Turn LEDs Off)*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator < COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8Iterator], GPIO_OUTPUT_LOW);
	}
}

void LEDMTRX_voidDisplayPattern(u8 Copy_u8PatternArray[], u32 Copy_u32TimeMilliSec)
{
	/* Local Iterator */
	u32 Local_u8LoopIterator ;
	/* Local Iterator to Loop over columns */
	u8 Local_u8ColIterator = 0;

	/* Local Iterator to Loop over rows */
	u8 Local_u8RowIterator = 0;
	/* Loop For Displaying Pattern for Period Of Time */
	for(Local_u8LoopIterator = 0 ; Local_u8LoopIterator < (Copy_u32TimeMilliSec/25) ; Local_u8LoopIterator++)
	{
		/* Loop Over Columns to activate one by one*/
		for(Local_u8ColIterator = 0 ; Local_u8ColIterator < COL_NUM ; Local_u8ColIterator++)
		{
			/* Activate The Current Column -> Set the Pin Value to Low */
			GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8ColIterator], GPIO_OUTPUT_LOW);

			/* Loop Over all Rows to set the Corresponding Value -> Either (1-0) From the Pattern Array Index*/
			for(Local_u8RowIterator = 0 ; Local_u8RowIterator < ROW_NUM ; Local_u8RowIterator++)
			{
				/* Set the Value of the Row to be the Corresponding bit of the row
				 * to the Corresponding Pattern Index for the Activated Column */
				GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8RowIterator], (GET_BIT(Copy_u8PatternArray[Local_u8ColIterator],Local_u8RowIterator)));
			}

			/* Set Delay = 2.5 MilliSecond Between Every Column Activation */
			STK_voidDelaySync(2500);

			/* Reset the LED Matrix before Activating the New Column */
			LEDMTRX_voidTrunOff();
		}
	}
}

