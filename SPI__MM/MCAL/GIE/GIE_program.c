


#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"GIE_config.h"
#include"GIE_private.h"
#include"GIE_interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , 7);

}

void GIE_voidDisable(void)
{

	CLR_BIT(SREG , 7);

}





