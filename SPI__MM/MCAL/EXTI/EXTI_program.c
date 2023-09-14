


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include"EXTI_config.h"
#include"EXTI_private.h"
#include"EXTI_interface.h"

void(*GpF1)(void) = NULL ;
void(*GpF2)(void) = NULL ;
void(*GpF3)(void) = NULL ;

void EXTI_voidInit(void)
{
 	#if INT_ENABLE == INT0
		SET_BIT(GICR_REG,6);
	#elif INT_ENABLE == INT1
		SET_BIT(GICR_REG,7);
	#elif INT_ENABLE == INT0
		SET_BIT(GICR_REG,5);
	#endif

	#if INT_ENABLE == INT0
		/*DIo*/
		DIO_voidSetPinDirection(PORTD , PIN2 ,INPUT);
		#if INT_SENSE_CONTROL == FALLING_EDGE
			DIO_voidSetPinvalue(PORTD,PIN2,HIGH);
			/*falling edge*/
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			CLR_BIT(MCUCR_REG,MCUCR_ISC00);
		#elif INT_SENSE_CONTROL == RISING_EDGE
			/*RISING edge*/
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
		#elif INT_SENSE_CONTROL == LOWLEVEL_EDGE
			/*level edge*/
			CLR_BIT(MCUCR_REG,MCUCR_ISC01);
			CLR_BIT(MCUCR_REG,MCUCR_ISC00);
		#elif INT_SENSE_CONTROL == ONCHANGE_EDGE
			/*Onchange edge*/
			CLR_BIT(MCUCR_REG,MCUCR_ISC01);
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
		#endif
	#elif INT_ENABLE == INT1
		DIO_voidSetPinDirection(PORTD , PIN3 ,INPUT);
		#if INT_SENSE_CONTROL == FALLING_EDGE
			DIO_voidSetPinvalue(PORTD,PIN2,HIGH);
			/*falling edge*/
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			CLR_BIT(MCUCR_REG,MCUCR_ISC10);

		#elif INT_SENSE_CONTROL == RISING_EDGE
			/*RISING edge*/
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
		#elif INT_SENSE_CONTROL == LOWLEVEL_EDGE
			/*level edge*/
			CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			CLR_BIT(MCUCR_REG,MCUCR_ISC10);
		#else INT_SENSE_CONTROL == ONCHANGE_EDGE
			/*Onchange edge*/
			CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
		#endif
	#elif INT_ENABLE == INT2
		DIO_voidSetPinDirection(PORTB , PIN2 ,INPUT);
		#if INT_SENSE_CONTROL == FALLING_EDGE
			DIO_voidSetPinvalue(PORTB,PIN2,HIGH);
			/*falling edge*/
			SET_BIT(MCUCR_REG,6);
		#elif INT_SENSE_CONTROL == RISING_EDGE
			/*RISING edge*/
			CLR_BIT(MCUCR_REG,6);
		#endif
	#endif
}

void EXTI_voidEnable(u8 Copy_u8IntNo , u8 Copy_u8Sensecontrol)
{
	switch(Copy_u8IntNo)
	{
		case INT0:
			SET_BIT(GICR_REG,6);
			switch(Copy_u8Sensecontrol)
			{
				case FALLING_EDGE :
					SET_BIT(MCUCR_REG,1);
					CLR_BIT(MCUCR_REG,0);
					break ;
				case RISING_EDGE:
					SET_BIT(MCUCR_REG,1);
					SET_BIT(MCUCR_REG,0);
					break ;
				case LOWLEVEL_EDGE :
					CLR_BIT(MCUCR_REG,1);
					CLR_BIT(MCUCR_REG,0);
					break ;
				case ONCHANGE_EDGE :
					CLR_BIT(MCUCR_REG,1);
					SET_BIT(MCUCR_REG,0);
					break ;
				default:
					break;
			}
			break ;
		case INT1:
			SET_BIT(GICR_REG,7);
			switch(Copy_u8Sensecontrol)
			{
				case FALLING_EDGE :
					SET_BIT(MCUCR_REG,3);
					CLR_BIT(MCUCR_REG,2);
					break ;
				case RISING_EDGE:
					SET_BIT(MCUCR_REG,3);
					SET_BIT(MCUCR_REG,2);
					break ;
				case LOWLEVEL_EDGE :
					CLR_BIT(MCUCR_REG,3);
					CLR_BIT(MCUCR_REG,2);
					break ;
				case ONCHANGE_EDGE :
					CLR_BIT(MCUCR_REG,3);
					SET_BIT(MCUCR_REG,2);
					break ;
				default:
					break;
			}
			break ;
		case INT2:
			SET_BIT(GICR_REG,5);
			switch(Copy_u8Sensecontrol)
			{
				case FALLING_EDGE :
					CLR_BIT(MCUCSR_REG,6);
					break ;
				case RISING_EDGE:
					SET_BIT(MCUCSR_REG,6);
					break ;
				default:
					break;
			}
			break ;
		default:
			break ;
	}

}

void EXTI_voidDisable(u8 Copy_u8IntNo)
{
	switch(Copy_u8IntNo)
	{
		case INT0 :
			CLR_BIT(GICR_REG,6);
			break;
		case INT1 :
			CLR_BIT(GICR_REG,7);
			break;
		case INT2 :
			CLR_BIT(GICR_REG,5);
			break;
		default   :
			break ;

	}



}

void EXTI_voidSetCallBack_INT0(void(*LPF1)(void))
{
	GpF1 = LPF1 ;
}

void EXTI_voidSetCallBack_INT1(void(*LPF2)(void))
{
	GpF2 = LPF2 ;
}

void EXTI_voidSetCallBack_INT2(void(*LPF3)(void))
{
	GpF3 = LPF3 ;
}




void __vector_1(void)
{
	if(GpF1!=NULL)
	{
		GpF1();
	}
}

void __vector_2(void)
{
	if(GpF2!=NULL)
	{
		GpF2();
	}
}

void __vector_3(void)
{
	if(GpF3!=NULL)
	{
		GpF3();
	}
}


