

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"LCD_config.h"
#include"LCD_private.h"
#include"LCD_interface.h"

void LCD_voidInit(void)
{
	/*config LCD control pins*/
	DIO_voidSetPinDirection(LCD_CR , RS_PIN , OUTPUT) ; //rs output
	DIO_voidSetPinDirection(LCD_CR , RW_PIN , OUTPUT) ; //rw output
	DIO_voidSetPinDirection(LCD_CR , E_PIN , OUTPUT) ; //E output

	/*Direction of data pins*/
	DIO_voidSetPortDirection(LCD_DR , DIO_u8PORT_OUTPUT);

	/*delay 50 ms*/
	_delay_ms(50);

	/*Send Function Set instruction*/
	LCD_voidSendCommand(0b00111000);
	_delay_ms(2);
	/*clear display inst*/
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	/*display*/
	LCD_voidSendCommand(0b00001100);
	_delay_ms(2);
	/*entry mode*/
	LCD_voidSendCommand(0b00000110);
	_delay_ms(2);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*rs = 0 to send*/
	DIO_voidSetPinvalue(LCD_CR , RS_PIN , LOW);

	/*rw = 0*/
	DIO_voidSetPinvalue(LCD_CR , RW_PIN , LOW);

	/*send coomand*/
	DIO_voidSetPortvalue(LCD_DR , Copy_u8Command) ;

	/*falling edge pin E */
	DIO_voidSetPinvalue(LCD_CR , E_PIN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinvalue(LCD_CR , E_PIN , LOW);

}

void LCD_voidSendChar(u8 Copy_u8Data)
{
	/*rs = 1 to send*/
	DIO_voidSetPinvalue(LCD_CR , RS_PIN , HIGH);

	/*rw = 0*/
	DIO_voidSetPinvalue(LCD_CR , RW_PIN , LOW);

	/*send coomand*/
	DIO_voidSetPortvalue(LCD_DR , Copy_u8Data) ;

	/*falling edge pin E */
	DIO_voidSetPinvalue(LCD_CR , E_PIN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinvalue(LCD_CR , E_PIN , LOW);

}

void LCD_voidSendString(const char* Copy_u8Arr)
{
	u8 i=0 ;
	while(Copy_u8Arr[i]!='\0')
	{
		LCD_voidSendChar(Copy_u8Arr[i]);
		i++;
	}

}

void LCD_voidSendNum(u32 Copy_u32Num)
{
	u32 Local_u32Number = 1 ;
	if(Copy_u32Num==0)
	{
		LCD_voidSendChar(0+'0');
	}
	else
	{
		while(Copy_u32Num!=0)
		{
			Local_u32Number = (Local_u32Number*10) + (Copy_u32Num %10) ;
			Copy_u32Num /= 10 ;
		}
		while(Local_u32Number != 1)
		{
			LCD_voidSendChar('0'+(Local_u32Number % 10));
			Local_u32Number = Local_u32Number / 10 ;
		}
	}
}
void LCD_voidGoToXY(u8 Copy_u8Line , u8 Copy_u8Position)
{
	switch(Copy_u8Line)
	{
		case 0 : LCD_voidSendCommand(0x80+Copy_u8Position); break ;
		case 1 : LCD_voidSendCommand(0xC0+Copy_u8Position); break ;
		default: break;
	}
}
void LCD_voidCLR(void)
{
	/*clear the LCD*/
	LCD_voidSendCommand(0b00000001);
}

void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8xPos , u8 Copy_u8YPos )
{
	u8 Local_u8CGRAMAddress = 0 , Local_u8Iterator ;

	/*calculate the CGRAM Address*/
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;

	/*sending CGRam address and  setting bit 6 */
	LCD_voidSendCommand(Local_u8CGRAMAddress + 64) ;

	/*wrte the pattern into CG ram*/
	for(Local_u8Iterator=0 ; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		LCD_voidSendChar(Copy_pu8Pattern[Local_u8Iterator]) ;
	}

	/*Go bach to the DDRAM to display the pattern*/
	LCD_voidGoToXY(Copy_u8xPos , Copy_u8YPos) ;

	/*Display the pattern writen in CGRAm*/
	LCD_voidSendChar(Copy_u8PatternNumber) ;

}






