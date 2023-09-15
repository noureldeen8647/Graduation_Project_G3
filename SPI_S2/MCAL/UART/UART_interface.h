////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);

void UART_voidSendData(u8 Copy_u8Data);

void UART_u8RecieveData(u8 *Copy_pu8Data);

#endif
