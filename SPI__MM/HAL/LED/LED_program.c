////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"LED_interface.h"



void LED_voidInitOneLed(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	DIO_voidSetPinDirection(Copy_u8PortId ,Copy_u8PinId , OUTPUT) ;
}

void LED_voidInitLedString(u8 Copy_u8PortId)
{
	DIO_voidSetPortDirection(Copy_u8PortId , DIO_u8PORT_OUTPUT);
}

void LED_voidLedOnOff(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case ON  :	DIO_voidSetPinvalue(Copy_u8PortId ,Copy_u8PinId , HIGH) ; break ;
		case OFF :	DIO_voidSetPinvalue(Copy_u8PortId ,Copy_u8PinId , LOW ) ; break ;
		default  :
			break ;
	}
}
void LED_voidLedStringOnOff(u8 Copy_u8PortId,u8 Copy_u8Value)
{

	DIO_voidSetPortvalue(Copy_u8PortId , Copy_u8Value) ;

}



