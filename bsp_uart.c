/**
 * @file bsp_uart.c
 * @brief
 * @details
 * @copyright COPYRIGHT NOTICE: (c) 2016 NASA Ames Research Center
 * @note ROM: BioSentinel Bio Payload
 * @note Processor: MSP430FR6989
 * @note Compiler: MSP-430 TI 4.4.5
 * $Id$
 */

#include "bsp_uart.h"
// Application header files
// Internal library header files
// Third-party library header files
#include <driverlib.h>
// Standard library header files
#include <stdio.h>
#include <string.h>

// *****************************************************************************
// Private macro definitions 
// *****************************************************************************

// *****************************************************************************
// Private data type definitions (enum, struct, typedef, union)
// *****************************************************************************

// *****************************************************************************
// Private static constant definitions
// *****************************************************************************

// *****************************************************************************
// Private static data definitions
// *****************************************************************************

// *****************************************************************************
// Private static function and ISR prototypes
// *****************************************************************************

// *****************************************************************************
// Private inline function definitions
// *****************************************************************************

// *****************************************************************************
// Public function bodies
// *****************************************************************************

void init_uart(void)
{
	EUSCI_A_UART_initParam uart_a1_param={
			EUSCI_A_UART_CLOCKSOURCE_ACLK,
			3,
			0,
			146,
			EUSCI_A_UART_NO_PARITY,
			EUSCI_A_UART_LSB_FIRST,
			EUSCI_A_UART_ONE_STOP_BIT,
			EUSCI_A_UART_MODE,
			EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
	};

	EUSCI_A_UART_initParam uart_a0_param={
			EUSCI_A_UART_CLOCKSOURCE_ACLK,
			3,
			0,
			146,
			EUSCI_A_UART_NO_PARITY,
			EUSCI_A_UART_LSB_FIRST,
			EUSCI_A_UART_ONE_STOP_BIT,
			EUSCI_A_UART_MODE,
			EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
	};
/*
	GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN5);
	GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN4);
	GPIO_setAsOutputPin(GPIO_PORT_P3,GPIO_PIN4);

	GPIO_setAsPeripheralModuleFunctionInputPin(
			GPIO_PORT_P3,
			GPIO_PIN5,
			GPIO_PRIMARY_MODULE_FUNCTION
			);
	GPIO_setAsPeripheralModuleFunctionOutputPin(
			GPIO_PORT_P3,
			GPIO_PIN4,
			GPIO_PRIMARY_MODULE_FUNCTION
			);
*/
	EUSCI_A_UART_init(EUSCI_A1_BASE,&uart_a1_param);
	EUSCI_A_UART_enable(EUSCI_A1_BASE);


	EUSCI_A_UART_init(EUSCI_A0_BASE,&uart_a0_param);
	EUSCI_A_UART_enable(EUSCI_A0_BASE);

}

int cout_data_channel(const char *_ptr)
{
	// Vars to iterate over the string
	uint16_t i, len;

	// Get the length of the string
	len = strlen(_ptr);

	// Loop over each byte of the string
	for(i=0 ; i<len ; i++)
	{
		// Wait for the peripherial to be available
		while (!EUSCI_A_UART_getInterruptStatus(EUSCI_A0_BASE,EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG));//while(!(UCA1IFG&UCTXIFG));
		// Stuff byte into the tx reg
		EUSCI_A_UART_transmitData(EUSCI_A0_BASE,_ptr[i]);//UCA1TXBUF = (unsigned char) _ptr[i];
	}

	// Return the number of bytes sent
	return len;
}


// *****************************************************************************
// Private function bodies
// *****************************************************************************

int fputc(int _c, register FILE *_fp)
{
	// Wait for peripherial to be available
	while (!EUSCI_A_UART_getInterruptStatus(EUSCI_A1_BASE,EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG));//while(!(UCA1IFG&UCTXIFG));
	// Stuff byte into tx reg
	EUSCI_A_UART_transmitData(EUSCI_A1_BASE,_c);//UCA1TXBUF = (unsigned char) _c;
	// Return tx'd byte, for giggles I suppose
	return((unsigned char)_c);
}

int fputs(const char *_ptr, register FILE *_fp)
{
	// Vars to iterate over the string
	uint16_t i, len;

	// Get the length of the string
	len = strlen(_ptr);

	// Loop over each byte of the string
	for(i=0 ; i<len ; i++)
	{
		// Wait for the peripherial to be available
		while (!EUSCI_A_UART_getInterruptStatus(EUSCI_A1_BASE,EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG));//while(!(UCA1IFG&UCTXIFG));
		// Stuff byte into the tx reg
		EUSCI_A_UART_transmitData(EUSCI_A1_BASE,_ptr[i]);//UCA1TXBUF = (unsigned char) _ptr[i];
	}

	// Return the number of bytes sent
	return len;
}

// *****************************************************************************
// Interrupt Service Routine bodies
// *****************************************************************************
