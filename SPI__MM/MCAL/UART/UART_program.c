

#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include <util/delay.h>

#include "..\../MCAL/DIO/DIO_Interface.h"

#include"UART_config.h"
#include"UART_private.h"
#include"UART_interface.h"

void UART_voidInit(void)
{
	//Select UCSRA
	SET_BIT(UART_UCSRC_REG , 7) ;

	//selsect Asynch(baud rate)
	CLR_BIT(UART_UCSRC_REG , 6) ;

	//parity disable(error)
	CLR_BIT(UART_UCSRC_REG , 4);
	CLR_BIT(UART_UCSRC_REG , 5);

	//Stop bit 1 Or 2 bits
	CLR_BIT(UART_UCSRC_REG , 3);

	//Charctar Size 8 bits
	SET_BIT(UART_UCSRC_REG , 2);
	SET_BIT(UART_UCSRC_REG , 1);
	CLR_BIT(UART_UCSRB_REG , 2); //B

	//select Baud rate reg
	CLR_BIT(UART_UCSRC_REG , 7) ;
	//Select Baud Rate
	UART_UBRRH_REG = (u8)(BAUD_RATE>>8);
	UART_UBRRL_REG = (u8)(BAUD_RATE);

	//Enable RX & TX
	SET_BIT(UART_UCSRB_REG , 3); //B
	SET_BIT(UART_UCSRB_REG , 4); //B

}

void UART_voidSendData(u8 Copy_u8Data)
{
	//polling
	while(GET_BIT(UART_UCSRA_REG , 5)==0);

	//when flag = 1
	UART_UDR_REG = Copy_u8Data ;

	//clear flag
	SET_BIT(UART_UCSRA_REG , 6) ;
}

void UART_u8RecieveData(u8 *Copy_pu8Data)
{
	//polling
	while(GET_BIT(UART_UCSRA_REG , 7)==0);

	//when flag = 1
	*Copy_pu8Data = UART_UDR_REG ;

}





