#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_Interface.h"

#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/UART/UART_Interface.h"

#include "../HAL/StepMotor/STP_interface.h"


int main()
{

	DIO_voidSetPinDirection(PORTD , PIN0 , OUTPUT);
	DIO_voidSetPinDirection(PORTD , PIN1 , INPUT);
	u8 Recieved = 0 ;
	UART_voidInit();
	//servo
	DIO_voidSetPinDirection(PORTD ,PIN5 , OUTPUT);
	TIMER1_voidInit() ;


	//eeprom
	u8 Return_Data =3 ;
	TWI_voidInitMaster(0);
	Return_Data = EEPROM_u8ReadDataByte(5);
	EEPROM_voidSendDataByte(5,3);



	DIO_voidSetPortDirection(PORTA,0xff);
	DIO_voidSetPortvalue(PORTA,0X00);

	while(1)
	{
		UART_u8RecieveData(&Recieved);
		Return_Data = EEPROM_u8ReadDataByte(5);

		if(Recieved == 's')
		{
			TIMER1_voidSetPinACompareMatch(1999);
		}
		if(Recieved == 'a')
		{

			DIO_voidSetPinvalue(PORTA , PIN0 , HIGH);
			_delay_ms(20);
			DIO_voidSetPinvalue(PORTA , PIN0 , LOW);	_delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN0 , HIGH);	_delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN0 , LOW);	_delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN0 , HIGH);
		}
		if(Recieved == 'b')
		{
			EEPROM_voidSendDataByte(5,2);
			DIO_voidSetPinvalue(PORTA , PIN1 , HIGH);   _delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN1 , HIGH);	_delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN1 ,  LOW);	_delay_ms(100);
			DIO_voidSetPinvalue(PORTA , PIN1 , HIGH);

		}
		if(Recieved == 'c')
		{
			EEPROM_voidSendDataByte(5,1);

			DIO_voidSetPinvalue(PORTA , PIN2 , HIGH);   _delay_ms(20);
			DIO_voidSetPinvalue(PORTA , PIN2 , HIGH);	_delay_ms(20);
			DIO_voidSetPinvalue(PORTA , PIN2 , LOW);	_delay_ms(20);
			DIO_voidSetPinvalue(PORTA , PIN2 , HIGH);


		}
		if(Recieved == 'd')
		{

			EEPROM_voidSendDataByte(5,0);

			while(1){
						DIO_voidSetPinvalue(PORTA , PIN1, HIGH);
						DIO_voidSetPinvalue(PORTA , PIN2 , LOW);
						DIO_voidSetPinvalue(PORTA , PIN3 , LOW);	_delay_ms(100);

						DIO_voidSetPinvalue(PORTA , PIN1, LOW);
						DIO_voidSetPinvalue(PORTA , PIN2 , HIGH);
						DIO_voidSetPinvalue(PORTA , PIN3 , LOW);	_delay_ms(100);

						DIO_voidSetPinvalue(PORTA , PIN1, LOW);
						DIO_voidSetPinvalue(PORTA , PIN2 , LOW);
						DIO_voidSetPinvalue(PORTA , PIN3 , HIGH);	_delay_ms(100);


						DIO_voidSetPinvalue(PORTA , PIN1, LOW);
						DIO_voidSetPinvalue(PORTA , PIN2 , LOW);
						DIO_voidSetPinvalue(PORTA , PIN3 , LOW);    _delay_ms(100);


						DIO_voidSetPinvalue(PORTA , PIN1, HIGH);
						DIO_voidSetPinvalue(PORTA , PIN2 , HIGH);
						DIO_voidSetPinvalue(PORTA , PIN3 , HIGH);	_delay_ms(400);
		}
	}

}
}
