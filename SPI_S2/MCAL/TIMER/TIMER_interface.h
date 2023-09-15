////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void TIMER0_voidInit();

void TIMER0_voidSetPreloadValue(u8 Copy_PreloadValue) ;

void TIMER0_voidSetCallBackT0Ovf(void(*LPF)(void)) ;

void TIMER0_voidSetCompareMatchValue(u8 Copy_PreloadValue);

void TIMER0_voidSetCallBackT0CTC(void(*LPF1)(void)) ;

//Timer 1

void TIMER1_voidInit(void);

void TIMER1_voidSetPinACompareMatch(u16 Copy_u16Value);

void TIMERS_voidT1SetBusyWait(u32 Copy_u32MilliSeconds) ;


#endif
