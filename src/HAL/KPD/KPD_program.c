/*******************************************************************************/
/*Author      : Saad Mohamed Saad					 				           */
/*File Name   : KPD_program.c             	                                   */
/*Layer       : HAL		    						  		                   */
/*Description : This file contains Function Implementation of KPD Module	   */
/*Date        : 18 May 2023                                                    */
/*******************************************************************************/


#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "KPD_Private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

/*	This function initializes the keypad pins by configuring the rows as input pins
 *  with pull-up resistors and the columns as output pins with low-speed push-pull mode.
 *  The function also sets the initial value of the column pins to HIGH.*/
void KPD_voidInit(StrKPD_t * Copy_PStr_KPD)
{
	/* Initialize rows as input pins with pull-up resistors */
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R1,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R2,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R3,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R4,GPIO_INPUT_PULL_UP);

	/* Initialize columns as output pins with low-speed push-pull mode */
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	/* Set value of column pins to HIGH */
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C1,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C2,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C3,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C4,GPIO_OUTPUT_HIGH);
}

/*	This function scans a 4x4 matrix keypad connected to the micro-controller and returns
 *  the value of the pressed key based on a pre-defined mapping.
 *  The function uses a row-column scanning technique to detect the pressed key.
 *  The keypad consists of 4 rows and 4 columns, and each key on the keypad is associated
 *  with a unique row-column combination.
 *  The function initializes the keypad pins and then scans each column of the keypad.
 *  If a key is pressed, the function waits until the key is released before returning
 *  the corresponding value. If no key is pressed, the function returns 255.*/
u8 KPD_u8GetPressedKey(StrKPD_t * Copy_PStr_KPD)
{
	u8 Col_u8_Iterator;
	u8 Row_u8_Iterator;
	u8 Pressed_Key_Value = 255;

	/* Loop through each column of the keypad */
	for(Col_u8_Iterator = 0 ; Col_u8_Iterator < 4 ; Col_u8_Iterator++)
	{
		/* Set the current column pin to LOW */
		if (Col_u8_Iterator == 0 )
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C1,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 1)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C2,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 2)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C3,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 3)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C4,GPIO_OUTPUT_LOW);

		/* Check each row of the keypad for a pressed key */
		if ((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R1)) == 0)
		{
			Pressed_Key_Value = KPD_u8_KeyMapping[0][Col_u8_Iterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R1)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R2)) == 0)
		{
			Pressed_Key_Value = KPD_u8_KeyMapping[1][Col_u8_Iterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R2)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R3)) == 0)
		{
			Pressed_Key_Value = KPD_u8_KeyMapping[2][Col_u8_Iterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R3)) == 0);
		}
		else if ((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R4)) == 0)
		{
			Pressed_Key_Value = KPD_u8_KeyMapping[3][Col_u8_Iterator - 0];
			while((GPIO_u8GetInputPinValue(Copy_PStr_KPD->KPD_PIN_R4)) == 0);
		}
		else
		{
			/*Do Nothing*/
		}

		/* Set the current column pin back to HIGH */
		if (Col_u8_Iterator == 0 )
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C1,GPIO_OUTPUT_HIGH);
		else if (Col_u8_Iterator == 1)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C2,GPIO_OUTPUT_HIGH);
		else if (Col_u8_Iterator == 2)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C3,GPIO_OUTPUT_HIGH);
		else if (Col_u8_Iterator == 3)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C4,GPIO_OUTPUT_HIGH);
	}
	return Pressed_Key_Value;
}
