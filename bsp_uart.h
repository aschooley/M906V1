#ifndef BSP_UART_H
#define BSP_UART_H

/**
 * @file bsp_uart.h
 * @brief
 * @details
 * @copyright COPYRIGHT NOTICE: (c) 2016 NASA Ames Research Center
 * @note ROM: BioSentinel Bio Payload
 * @note Processor: MSP430FR6989
 * @note Compiler: MSP-430 TI 4.4.5
 * $Id$
 */

// Application header files
// Internal library header files
// Third-party library header files
// Standard library header files
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Public macro definitions
// *****************************************************************************

// *****************************************************************************
// Public data type definitions (enum, struct, typedef, union)
// *****************************************************************************

// *****************************************************************************
// Public constant definitions
// *****************************************************************************

// *****************************************************************************
// Public function prototypes
// *****************************************************************************


int cout_data_channel (const char * _ptr);

/**
 * Return how many bytes are in a message if a complete message hase been
 * recieved on the trace port.
 */
uint8_t trace_msg_recieved (void);

bool read_trace_msg (char * buffer, uint8_t buff_sz);

// *****************************************************************************
// Public inline function definitions
// *****************************************************************************

#ifdef __cplusplus
}
#endif

#endif // BSP_UART_H
