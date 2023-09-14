


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"TIMER_config.h"
#include"TIMER_private.h"
#include"TIMER_interface.h"

void(*TIMER_GPF0)(void) = NULL ;
void(*TIMER_GPF1)(void) = NULL ;


void TIMER0_voidInit()
{
	#if(TIMER_MODE==TIMER_NORMAL_MODE)
	//normal mode
	CLR_BIT(TIMER0_TCCR0_REG , 6 );
	CLR_BIT(TIMER0_TCCR0_REG , 3 );
	#elif(TIMER_MODE==TIMER_CTC_MODE)
	//compare mode
	CLR_BIT(TIMER0_TCCR0_REG , 6 );
	SET_BIT(TIMER0_TCCR0_REG , 3 );
	#elif(TIMER_MODE==TIMER_FAST_PWM_MODE)
	//fast PWM
	SET_BIT(TIMER0_TCCR0_REG , 6 );
	SET_BIT(TIMER0_TCCR0_REG , 3 );
	//set on top clear on compare
	CLR_BIT(TIMER0_TCCR0_REG , 4 );
	SET_BIT(TIMER0_TCCR0_REG , 5 );
	#endif

	//prescaller division factor = 8
	CLR_BIT(TIMER0_TCCR0_REG , 2 );
	CLR_BIT(TIMER0_TCCR0_REG , 0 );
	SET_BIT(TIMER0_TCCR0_REG , 1 );

	//Enable Timer0 Interrupt PIE
	SET_BIT(TIMER0_TIMSK_REG , 0) ;

}

void TIMER0_voidSetCallBackT0Ovf(void(*LPF0)(void))
{
	TIMER_GPF0 = LPF0 ;
}


void TIMER0_voidSetPreloadValue(u8 Copy_PreloadValue)
{
	TIMER0_TCNT0_REG = Copy_PreloadValue ;
}

void TIMER0_voidSetCallBackT0CTC(void(*LPF1)(void))
{
	TIMER_GPF1 = LPF1 ;
}

void TIMER0_voidSetCompareMatchValue(u8 Copy_CompareMatchValue)
{
	TIMER0_OCR0_REG = Copy_CompareMatchValue ;
}



//ISR for T0OVF
void __vector_10(void)    __attribute__((signal));
void __vector_10(void)
{
	static u16 counter = 0 ;
	counter ++ ;
	//compare =200 ,, time = 1sec
	if(counter == 5000)
	{
		TIMER_GPF1();
		counter = 0 ;
	}

}
void __vector_11(void)    __attribute__((signal));
void __vector_11(void)
{
	static u16 counter = 0 ;
	counter ++ ;
	//overflow 1
	if(counter == 3907)
	{
		TIMER_GPF0();
		counter = 0 ;
		TIMER0_voidSetPreloadValue(192);
	}

}
void TIMER1_voidInit(void)
{

	//fast PWM
	CLR_BIT(TIMER1_TCCR1A_REG , 0 );
	SET_BIT(TIMER1_TCCR1A_REG , 1);
	SET_BIT(TIMER1_TCCR1B_REG , 3 );
	SET_BIT(TIMER1_TCCR1B_REG , 4);

	//set on top clear on compare
	CLR_BIT(TIMER1_TCCR1A_REG , 6 );
	SET_BIT(TIMER1_TCCR1A_REG , 7 );


	//prescaller division factor = 8
	CLR_BIT(TIMER1_TCCR1B_REG , 0 );
	SET_BIT(TIMER1_TCCR1B_REG , 1 );
	CLR_BIT(TIMER1_TCCR1B_REG , 2 );

	//Enable Timer0 Interrupt PIE
	//SET_BIT(TIMER1 , 0) ;

	//intilize value over flow value
	TIMER1_ICR1_REG = 19999 ;

	//intilize counter
	TIMER1_TCNT1_REG = 0 ;

}




void TIMER1_voidSetPinACompareMatch(u16 Copy_u16Value)
{
	TIMER1_OCR1A_REG = Copy_u16Value ;
}

void TIMERS_voidT1SetBusyWait(u32 Copy_u32MilliSeconds)
{
	u32 Local_u64SWCounter = 0 ;
	u32 Local_u64Iterator = 0 ;
	Local_u64SWCounter = (Copy_u32MilliSeconds*1000) / (250 );
	for(Local_u64Iterator = 0 ; Local_u64Iterator < Local_u64SWCounter ; Local_u64Iterator++)
	{
		while(GET_BIT(TIMER1_TIFR_REG , 1) == 0 );
		SET_BIT(TIMER1_TIFR_REG , 1);
	}
}


