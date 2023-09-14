#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/UART/UART_Interface.h"



#include "../HAL/KEYPAD/KPD_interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/StepMotor/STP_interface.h"



void Emergeny(void);

int main()
{
	u8 Recieved ;
	u32 Read1 ;
	u16 Password = 1001 ;
	u16 User_Pass , Try_Again=0 ;
	u8 pass1 , pass2 , pass3 , pass4 ;
	STP_voidInit();
	KPD_voidInit();
	LCD_voidInit();
	//buzzer
	DIO_voidSetPinDirection(PORTD , PIN3 , OUTPUT);
	DIO_voidSetPinvalue(PORTD , PIN3 , LOW);
	//uart
	DIO_voidSetPinDirection(PORTD , PIN0 , INPUT);
	DIO_voidSetPinDirection(PORTD , PIN1 , OUTPUT);
	UART_voidInit();

	//light sensor
	ADC_voidInit();
	LED_voidInitOneLed(PORTA , PIN0 ) ;

	//tempsensor
	DIO_voidSetPinDirection(PORTA , PIN7 , OUTPUT);
	u32 Read2 ;
	u32 Temp ;

	//interrupt
	DIO_voidSetPinDirection(PORTD , PIN2 , INPUT) ;
	DIO_voidSetPinvalue(PORTD , PIN2 , HIGH);

            ///// GLOBAL interrupt *~*  *-*  *_* -_- .-.


	EXTI_voidEnable(INT0 , FALLING_EDGE);

	EXTI_voidSetCallBack_INT0(&Emergeny);

	jump :
	Try_Again++;
	if(Try_Again==1)
	{
		UART_voidSendData('a');
	}
	if(Try_Again==2)
	{
		UART_voidSendData('b');
	}
	if(Try_Again==3)
	{
		UART_voidSendData('c');
	}


	while(1)
	{
		LCD_voidCLR();
		LCD_voidSendString("Welcome");
		_delay_ms(1000);
		LCD_voidCLR();
		LCD_voidSendString("Enter password");
		_delay_ms(1000);
		LCD_voidGoToXY(1,0);
		while(1)
		{
			pass1 = KPD_u8GetPressedKey();

			if((pass1!=0xff))
			{
				LCD_voidSendChar('*');
				break ;
			}

		}
		while(1)
		{
			pass2 = KPD_u8GetPressedKey();

			if((pass2!=0xff))
			{
				LCD_voidSendChar('*');
				break ;
			}

		}
		while(1)
		{
			pass3 = KPD_u8GetPressedKey();

			if((pass3!=0xff))
			{
				LCD_voidSendChar('*');
				break ;
			}

		}
		while(1)
		{
			pass4 = KPD_u8GetPressedKey();

			if((pass4!=0xff))
			{
				LCD_voidSendChar('*');
				break ;
			}

		}

		User_Pass = (pass1*1000+pass2*100+pass3*10+pass4);  //1234
		if((User_Pass!=Password)&&(Try_Again<3))
		{
			LCD_voidCLR();
			LCD_voidSendString("Wrong Password");
			_delay_ms(1000);
			LCD_voidCLR();
			LCD_voidSendString("Try again");
			_delay_ms(1000);
			goto jump ;
		}




		else if((User_Pass!=Password)&&(Try_Again=3))
		{
			UART_voidSendData('d');
			LCD_voidCLR();
			LCD_voidSendString("NoMoreTries");
			_delay_ms(1000);
			LCD_voidCLR();
			LCD_voidSendString("Alerts On");
			DIO_voidSetPinvalue(PORTD , PIN3 , HIGH);

			_delay_ms(10000);
			break ;
		}

		else if(User_Pass==Password)
		{

			LCD_voidCLR();
			LCD_voidSendString("Hello user");
			_delay_ms(3000);
			LCD_voidCLR();
			UART_voidSendData('s');
			LCD_voidSendString("Door is opened");
			_delay_ms(3000);
			LCD_voidCLR();
			LCD_voidSendString("Light Sys ON");
			_delay_ms(3000);
			LCD_voidCLR();
			LCD_voidSendString("Temp Sys ON");
			_delay_ms(3000);
			LCD_voidCLR();
			LCD_voidSendString("Have a nice day");
			_delay_ms(1000);
			while(1)
			{


				Read1 = ADC_voidGetAnalogRead(ADC3);
				if(Read1>=2753)
				{
					_delay_ms(1000);
					DIO_voidSetPinDirection(PORTA,PIN0 , OUTPUT);
					DIO_voidSetPinvalue(PORTA , PIN0 , HIGH);
				}
				else
				{
					_delay_ms(1000);
					DIO_voidSetPinDirection(PORTA,PIN0 , OUTPUT);
					DIO_voidSetPinvalue(PORTA , PIN0 , LOW);
					STP_voidDirectionAngle(ClockWise , 120) ;
				}

				Read2 = ADC_voidGetAnalogRead(ADC2);
				Temp = Read2 / 10 ;
				if(Temp>30&&Temp<50)
				{
					LCD_voidSendCommand(0xC0);
					LCD_voidSendString("Temp = ");
                 LCD_voidSendNum(Temp);
					_delay_ms(1000);
					DIO_voidSetPinvalue(PORTA , PIN7 , HIGH);

				}
				else if (Temp<=30)
				{


					_delay_ms(1000);
					DIO_voidSetPinvalue(PORTA , PIN7 , LOW);

				}

				else if (Temp>=50)
								{
					DIO_voidSetPinvalue(PORTA , PIN7 , HIGH);
					DIO_voidSetPinvalue(PORTD , PIN3 , HIGH);
					UART_voidSendData('b');
					LCD_voidCLR();
									LCD_voidSendString("fire = ");
				LCD_voidSendNum(Temp);
									_delay_ms(1000);


								}

			}



		}






	}

	return 0 ;
}


void Emergeny(void)
{
	UART_voidSendData('d');
	DIO_voidSetPinvalue(PORTD , PIN3 , HIGH);
	_delay_ms(10000);


}

