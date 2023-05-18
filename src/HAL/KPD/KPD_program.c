/*
 * KPD_program.c
 *
 *  Created on: May 18, 2023
 *      Author: LENOVO
 */


#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "KPD_Private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

void KPD_voidInit(StrKPD_t * Copy_PStr_KPD)
{
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R1,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R2,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R3,GPIO_INPUT_PULL_UP);
	GPIO_voidInitInputPin(Copy_PStr_KPD->KPD_PIN_R4,GPIO_INPUT_PULL_UP);

	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	GPIO_voidInitOutputPin(Copy_PStr_KPD->KPD_PIN_C4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C1,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C2,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C3,GPIO_OUTPUT_HIGH);
	GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C4,GPIO_OUTPUT_HIGH);
}

u8 KPD_u8GetPressedKey(StrKPD_t * Copy_PStr_KPD)
{
	u8 Col_u8_Iterator;
	u8 Row_u8_Iterator;
	u8 Pressed_Key_Value = 255;

	for(Col_u8_Iterator = 0 ; Col_u8_Iterator < 4 ; Col_u8_Iterator++)
	{
		if (Col_u8_Iterator == 0 )
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C1,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 1)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C2,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 2)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C3,GPIO_OUTPUT_LOW);
		else if (Col_u8_Iterator == 3)
			GPIO_voidSetOutputPinValue(Copy_PStr_KPD->KPD_PIN_C4,GPIO_OUTPUT_LOW);


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
