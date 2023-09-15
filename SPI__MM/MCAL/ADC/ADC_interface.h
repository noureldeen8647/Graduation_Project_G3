////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*ADC Channels*/
#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7


void ADC_voidInit(void);

u32 ADC_voidGetAnalogRead(u8 Copy_Channel);

u32 ADC_voidGetAnalogReadAsynch(u8 Copy_Channel , void(*Copy_pvCallBackFunc)(void)) ;

void __vector_16(void) __attribute__((signal)) ;

#endif
