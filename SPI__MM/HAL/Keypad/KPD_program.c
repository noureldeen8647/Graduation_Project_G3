
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"KPD_config.h"
#include"KPD_private.h"
#include"KPD_interface.h"



void KPD_voidInit(void)
{
	/*rows input*/
	DIO_voidSetPinDirection(KPD_PORT , KPD_R1 , INPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_R2 , INPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_R3 , INPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_R4 , INPUT);


	/*columns pins*/
	DIO_voidSetPinDirection(KPD_PORT , KPD_C1 , OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_C2 , OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_C3 , OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT , KPD_C4 , OUTPUT);


	/*columns deactive , rows pullup */
	DIO_voidSetPortvalue(KPD_PORT , DIO_u8PORT_HIGH);

}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8Iterator1 , Local_u8Iterator2 ;
	u8 Local_Au8ColsArr[4]={KPD_C1,KPD_C2,KPD_C3,KPD_C4};
	u8 Local_Au8RowsArr[4]={KPD_R1,KPD_R2,KPD_R3,KPD_R4};
	u8 Local_PinValue ;
	u8 Local_PressedKey = 0xff ;
	u8 Local_u8Flag =0 ;

	for(Local_u8Iterator1=0 ; Local_u8Iterator1<4 ;Local_u8Iterator1++)
	{
		//Activate colmn
		DIO_voidSetPinvalue(KPD_PORT , Local_Au8ColsArr[Local_u8Iterator1] , LOW);

		for(Local_u8Iterator2=0;Local_u8Iterator2<4;Local_u8Iterator2 ++)
		{
			//debouncing
			_delay_ms(5);

			Local_PinValue = DIO_u8GetPinvalue(KPD_PORT,Local_Au8RowsArr[Local_u8Iterator2]);

			if(Local_PinValue==0)
			{
				Local_PinValue = DIO_u8GetPinvalue(KPD_PORT,Local_Au8RowsArr[Local_u8Iterator2]);

				while(Local_PinValue==0)
				{
					Local_PinValue = DIO_u8GetPinvalue(KPD_PORT,Local_Au8RowsArr[Local_u8Iterator2]);
				}
				//Safety debouncing


				Local_PressedKey = KeyPadArr[Local_u8Iterator2][Local_u8Iterator1];
				Local_u8Flag = 1 ;
				break ;
			}

		}
		//deactivate colmn
		DIO_voidSetPinvalue(KPD_PORT , Local_Au8ColsArr[Local_u8Iterator1] , HIGH);
		if(Local_u8Flag==1)
		{
			break ;
		}
	}
	return Local_PressedKey ;
}

