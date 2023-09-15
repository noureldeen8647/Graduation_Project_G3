////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

#include"DIO_config.h"
#include"DIO_private.h"
#include"DIO_interface.h"




void DIO_voidSetPinvalue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Direction )
{
	if(Copy_u8PortId>PORTD || Copy_u8PinId>PIN7)
	{
		//do nothing
	}
	else
	{
		switch(Copy_u8Direction)
		{
			case LOW  : switch(Copy_u8PortId)
						{
							case PORTA :
										CLR_BIT(PORTA_REG,Copy_u8PinId);
										break ;
							case PORTB :
										CLR_BIT(PORTB_REG,Copy_u8PinId);
										break ;
							case PORTC :
										CLR_BIT(PORTC_REG,Copy_u8PinId);
										break ;
							case PORTD :
										CLR_BIT(PORTD_REG,Copy_u8PinId);
										break ;
							default :
										break ;
						}
						break ;
			case HIGH  : switch(Copy_u8PortId)
						{
							case PORTA :
										SET_BIT(PORTA_REG,Copy_u8PinId);
										break ;
							case PORTB :
										SET_BIT(PORTB_REG,Copy_u8PinId);
										break ;
							case PORTC :
										SET_BIT(PORTC_REG,Copy_u8PinId);
										break ;
							case PORTD :
										SET_BIT(PORTD_REG,Copy_u8PinId);
										break ;
							default :
										break ;
						}
						break ;

			default :
				break ;
		}
	}
}
void DIO_voidSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Direction )
{
	if(Copy_u8PortId>PORTD || Copy_u8PinId>PIN7)
		{
			//do nothing
		}
		else
		{
			switch(Copy_u8Direction)
			{
				case INPUT  : switch(Copy_u8PortId)
							{
								case PORTA :
											CLR_BIT(DDRA_REG,Copy_u8PinId);
											break ;
								case PORTB :
											CLR_BIT(DDRB_REG,Copy_u8PinId);
											break ;
								case PORTC :
											CLR_BIT(DDRC_REG,Copy_u8PinId);
											break ;
								case PORTD :
											CLR_BIT(DDRD_REG,Copy_u8PinId);
											break ;
								default :
											break ;
							}
							break ;
				case OUTPUT  : switch(Copy_u8PortId)
							{
								case PORTA :
											SET_BIT(DDRA_REG,Copy_u8PinId);
											break ;
								case PORTB :
											SET_BIT(DDRB_REG,Copy_u8PinId);
											break ;
								case PORTC :
											SET_BIT(DDRC_REG,Copy_u8PinId);
											break ;
								case PORTD :
											SET_BIT(DDRD_REG,Copy_u8PinId);
											break ;
								default :
											break ;
							}
							break ;

					default :
							break ;
			}
		}
}


u8 DIO_u8GetPinvalue(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	u8 Local_u8Variable ;
	switch(Copy_u8PortId)
	{
		case PORTA : Local_u8Variable=GET_BIT(PINA_REG , Copy_u8PinId) ;
			break ;
		case PORTB : Local_u8Variable=GET_BIT(PINB_REG , Copy_u8PinId) ;
			break ;
		case PORTC : Local_u8Variable=GET_BIT(PINC_REG , Copy_u8PinId) ;
			break ;
		case PORTD : Local_u8Variable=GET_BIT(PIND_REG , Copy_u8PinId) ;
			break ;
		default :
			break ;

	}
	return Local_u8Variable ;
}

void DIO_voidSetPortvalue(u8 Copy_u8PortId , u8 Copy_u8Direction )
{
	if(Copy_u8PortId>PORTD)
	{
		//do nothing
	}
	else
	{
		switch(Copy_u8PortId)
		{
			case PORTA :PORTA_REG = Copy_u8Direction ;
						break ;
			case PORTB :
						PORTB_REG = Copy_u8Direction ;
						break ;
			case PORTC :
						PORTC_REG = Copy_u8Direction ;
						break ;
			case PORTD :
						PORTD_REG = Copy_u8Direction ;
						break ;
			default :
						break ;

		}
	}

}
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction )
{
	if(Copy_u8PortId>PORTD)
	{
		//do nothing
	}
	else
	{
		switch(Copy_u8PortId)
		{
			case PORTA :DDRA_REG = Copy_u8Direction ;
						break ;
			case PORTB :
						DDRB_REG = Copy_u8Direction ;
						break ;
			case PORTC :
						DDRC_REG = Copy_u8Direction ;
						break ;
			case PORTD :
						DDRD_REG = Copy_u8Direction ;
						break ;
			default :
						break ;

		}
	}

}u8 DIO_u8GetPortvalue(u8 Copy_u8PortId)
{
	u8 Local_u8Variable ;
	switch(Copy_u8PortId)
	{
		case PORTA : Local_u8Variable=PINA_REG ;
			break ;
		case PORTB : Local_u8Variable=PINB_REG ;
			break ;
		case PORTC : Local_u8Variable=PINC_REG ;
			break ;
		case PORTD : Local_u8Variable=PIND_REG ;
			break ;
		default :
			break ;

	}
	return Local_u8Variable ;
}
