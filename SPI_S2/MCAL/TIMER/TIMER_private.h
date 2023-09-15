////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////



#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIMER0_SREG_REG  (*(volatile u8 *)(0x5F)) /*Global Status Reg*/
#define TIMER0_TIMSK_REG  (*(volatile u8 *)(0x59)) /*Timer interrupt control Reg*/
#define TIMER0_TCCR0_REG  (*(volatile u8 *)(0x53)) /*Register TCCR0 (Timer0 Control Reg)*/
#define TIMER0_TCNT0_REG  (*(volatile u8 *)(0x52)) /*Register TCNT0 (Timer 0 Reg)*/
#define TIMER0_OCR0_REG  (*(volatile u8 *)(0x5C)) /*Register OCR0  (Output compare 0 Reg)*/
#define TIMER0_TIFR_REG  (*(volatile u8 *)(0x58)) /*Register TIFR  (Flag Reg)*/

#define TIMER_NORMAL_MODE       0
#define TIMER_CTC_MODE          1
#define TIMER_FAST_PWM_MODE     2
#define TIMER_PHASE_CORCT_MODE  3

#define TIMER1_TCCR1A_REG                   *((volatile u8*)   0x4F)
#define TIMER1_TCCR1B_REG                   *((volatile u8*)   0x4E)
#define TIMER1_TCNT1_REG                   *((volatile u16*)  0x4C)
#define TIMER1_OCR1A_REG                   *((volatile u16*)  0x4A)
#define TIMER1_OCR1B_REG                   *((volatile u16*)  0x48)
#define TIMER1_ICR1_REG                    *((volatile u16*)  0x46)
#define TIMER1_TIFR_REG                   *((volatile u8*)   0x58)



#endif
