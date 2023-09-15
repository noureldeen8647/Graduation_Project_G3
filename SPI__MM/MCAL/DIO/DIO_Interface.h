////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORTA        0
#define PORTB        1
#define PORTC        2
#define PORTD        3

#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7

#define HIGH         1
#define LOW          0

#define OUTPUT       1
#define INPUT        0

#define DIO_u8PORT_OUTPUT     0xff
#define DIO_u8PORT_INPUT      0x00


#define DIO_u8PORT_HIGH       0xff
#define DIO_u8PORT_LOW        0x00

void DIO_voidSetPinvalue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Value );
void DIO_voidSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8Direction );
u8 DIO_u8GetPinvalue(u8 Copy_u8PortId ,u8 Copy_u8PinId);

void DIO_voidSetPortvalue(u8 Copy_u8PortId , u8 Copy_u8Value );
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction );
u8 DIO_u8GetPortvalue(u8 Copy_u8PortId);


#endif
