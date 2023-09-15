////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////



#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR_REG   *((volatile u8*)0x55)
#define MCUCSR_REG  *((volatile u8*)0x54)
#define GICR_REG    *((volatile u8*)0x5B)
#define GIFR_REG    *((volatile u8*)0x5A)

#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10	 2
#define MCUCR_ISC11  3


#endif
