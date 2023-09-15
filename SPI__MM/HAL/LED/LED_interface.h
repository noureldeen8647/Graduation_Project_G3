////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////

#include "..\..\LIB\STD_TYPES.h"


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define ON   1
#define OFF   0

void LED_voidInitOneLed(u8 Copy_u8PortId,u8 Copy_u8PinId);

void LED_voidInitLedString(u8 Copy_u8PortId);

void LED_voidLedOnOff(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8State);

void LED_voidLedStringOnOff(u8 Copy_u8PortId,u8 Copy_u8Value);


#endif
