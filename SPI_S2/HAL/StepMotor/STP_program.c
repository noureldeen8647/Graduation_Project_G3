/****************************************************/
/****************************************************/
/**********    Author : Ahmed Elnahass     **********/
/**********    Layer : HAL                **********/
/**********    SWC : STP                   **********/
/**********    Version : 1.00              **********/
/****************************************************/
/****************************************************/


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"STP_config.h"
#include"STP_private.h"
#include"STP_interface.h"


void STP_voidInit(void)
{

	DIO_voidSetPinDirection(STP_PORT , STP_C1 , OUTPUT) ;
	DIO_voidSetPinDirection(STP_PORT , STP_C2 , OUTPUT) ;
	DIO_voidSetPinDirection(STP_PORT , STP_C3 , OUTPUT) ;
	DIO_voidSetPinDirection(STP_PORT , STP_C4 , OUTPUT) ;

	DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
}

void STP_voidDirectionAngle(u8 Copy_u8Direction , u16 Copy_u8Angle)
{
	u32 Local_STPSteps ;
	Local_STPSteps = Copy_u8Angle * 512 /360 ;

	switch(Copy_u8Direction)
	{
		case ClockWise :
			for(u32 i =0 ; i<Local_STPSteps;i++)
			{
				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,LOW);
				_delay_ms(10);

			}
			break ;
		case AntiClockWise :
			for(u8 i =0 ; i<Local_STPSteps;i++)
			{
				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,LOW);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);

				DIO_voidSetPinvalue(STP_PORT , STP_C1 ,LOW);
				DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
				DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
				_delay_ms(10);
			}
			break;
		default :
			break ;
	}

}

void STP_voidMove(void)
{
	while(1)
	{
			DIO_voidSetPinvalue(STP_PORT , STP_C1 ,LOW);
			DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
			_delay_ms(10);

			DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C2 ,LOW);
			DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
			_delay_ms(10);

			DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C3 ,LOW);
			DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
			_delay_ms(10);

			DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
			DIO_voidSetPinvalue(STP_PORT , STP_C4 ,LOW);
			_delay_ms(10);
	}
}

void STP_voidStop(void)
{
	DIO_voidSetPinvalue(STP_PORT , STP_C1 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C2 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C3 ,HIGH);
	DIO_voidSetPinvalue(STP_PORT , STP_C4 ,HIGH);
	_delay_ms(10);

}



