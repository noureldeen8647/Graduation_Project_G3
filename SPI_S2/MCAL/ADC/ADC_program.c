
////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"ADC_config.h"
#include"ADC_private.h"
#include"ADC_interface.h"

void(*ADC_GPF)(void) = NULL ;
u32 ADC_u32ADCDigitalValue ;
u32 ADC_u32ADCAnalogValue ;
u8 ADC_Flag = 0 ;

void ADC_voidInit(void)
{
	//select ref voltage = AVCC
	SET_BIT(ADMUX_REG , ADMUX_REFS0);
	CLR_BIT(ADMUX_REG , ADMUX_REFS1);
	//right adjust
	CLR_BIT(ADMUX_REG , ADMUX_ADLAR);
	//ADC Enable
	SET_BIT(ADCSRA_REG , ADCSRA_ADEN);
	//Disable Auto Trigger
	CLR_BIT(ADCSRA_REG , ADCSRA_ADATE);
	//Disable PIE for ADC
	CLR_BIT(ADCSRA_REG , ADCSRA_ADIF);
	//prescaler 64
	SET_BIT(ADCSRA_REG , ADCSRA_ADPS2);
	SET_BIT(ADCSRA_REG , ADCSRA_ADPS1);
	CLR_BIT(ADCSRA_REG , ADCSRA_ADPS0);
	//ADCSRA_REG &= 0b11111000
	//ADCSRA_REG |= ADC_PRESCALLER

}

u32 ADC_voidGetAnalogRead(u8 Copy_Channel)
{
	u32 Local_u32ADCDigitalValue ;
	u32 Local_u32ADCAnalogValue ;

	//clear Mux from 0 to 4 (reg&0b11100000)
	ADMUX_REG &= 0b11100000 ;
	//reg or with copy_channel
	ADMUX_REG |= Copy_Channel ;
	//start conversion
	SET_BIT(ADCSRA_REG , ADCSRA_ADSC);
	//polling flag
	while(GET_BIT(ADCSRA_REG , ADCSRA_ADIF)==0);
	//clear flag
	SET_BIT(ADCSRA_REG,ADCSRA_ADIF);
	//get reading right adjust
	Local_u32ADCDigitalValue = ADCL_REG + (ADCH_REG << 8) ;

	Local_u32ADCAnalogValue = (Local_u32ADCDigitalValue * 5000) / 1024 ;


	return Local_u32ADCAnalogValue ;
}

u32 ADC_voidGetAnalogReadAsynch(u8 Copy_Channel , void(*Copy_pvCallBackFunc)(void))
{
	if((ADC_Flag==1) ||(Copy_pvCallBackFunc==  NULL) )
	{
		return 0 ;
	}
	else
	{
		ADC_Flag = 1 ; //busy
		//clear Mux from 0 to 4 (reg&0b11100000)
		ADMUX_REG &= 0b11100000 ;
		//reg or with copy_channel
		ADMUX_REG |= Copy_Channel ;
		//set call back func
		ADC_GPF = Copy_pvCallBackFunc ;
		//start conversion
		SET_BIT(ADCSRA_REG , ADCSRA_ADSC);
		//Interrupt flag
		SET_BIT(ADCSRA_REG , ADCSRA_ADIE) ;

		return ADC_u32ADCAnalogValue ;
	}
}


void __vector_16(void)
{
	//get reading right adjust
	ADC_u32ADCDigitalValue = ADCL_REG + (ADCH_REG << 8) ;
	ADC_u32ADCAnalogValue = (ADC_u32ADCDigitalValue * 5000) / 1024 ;

	ADC_Flag = 0 ; //not busy

	ADC_GPF() ; //call back function

	//clear intuurrupt
	CLR_BIT(ADCSRA_REG , ADCSRA_ADIE) ;


}
