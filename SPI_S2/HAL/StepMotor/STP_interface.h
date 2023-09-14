/****************************************************/
/****************************************************/
/**********    Author : Ahmed Elnahass     **********/
/**********    Layer : HAL                **********/
/**********    SWC : STP                   **********/
/**********    Version : 1.00              **********/
/****************************************************/
/****************************************************/

#include "..\..\LIB\STD_TYPES.h"

#ifndef STP_INTERFACE_H_
#define STP_INTERFACE_H_

#define ClockWise 1
#define AntiClockWise 0

void STP_voidInit(void);

void STP_voidDirectionAngle(u8 Copy_u8Direction , u16 Copy_u8Angle);

void STP_voidMove(void);

void STP_voidStop(void);

#endif
