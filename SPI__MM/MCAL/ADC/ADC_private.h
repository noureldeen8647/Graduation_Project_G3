
////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ACSR_REG        *((volatile u8*)0x28)

#define ADMUX_REG       *((volatile u8*)0x27)
/*ADMUX Reg*/
#define ADMUX_MUX0      0
#define ADMUX_MUX1      1
#define ADMUX_MUX2		2
#define ADMUX_MUX3		3
#define ADMUX_MUX4		4
#define ADMUX_ADLAR		5
#define ADMUX_REFS0		6
#define ADMUX_REFS1		7


#define ADCSRA_REG      *((volatile u8*)0x26)
/*ADCSRA Reg*/
#define ADCSRA_ADPS0    0
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS2	2
#define ADCSRA_ADIE 	3
#define ADCSRA_ADIF		4
#define ADCSRA_ADATE	5
#define ADCSRA_ADSC		6
#define ADCSRA_ADEN		7

#define ADCH_REG        *((volatile u8*)0x25)

#define ADCL_REG        *((volatile u8*)0x24)


/*ADC Input CLK Prescaler*/
#define ADC_PRESCALER_2		    	1
#define ADC_PRESCALER_4			    2
#define ADC_PRESCALER_8			    3
#define ADC_PRESCALER_16			4
#define ADC_PRESCALER_32			5
#define ADC_PRESCALER_64			6
#define ADC_PRESCALER_128			7


#endif
