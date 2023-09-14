

#include "..\..\LIB\STD_TYPES.h"


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*3 func : INit , Send command , Sendcahr */

void LCD_voidInit(void);

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendChar(u8 Copy_u8Data);

void LCD_voidSendString(const char * Copy_u8Arr);

void LCD_voidSendNum(u32 Copy_u32Num);

void LCD_voidGoToXY(u8 Copy_u8Line , u8 Copy_u8Position);

void LCD_voidCLR(void) ;

void LCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8xPos , u8 Copy_u8YPos ) ;



#endif
