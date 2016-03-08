/**
 * @file drv_logger.c
 * @brief
 * @details
 * @copyright COPYRIGHT NOTICE: (c) 2016 NASA Ames Research Center
 * @note ROM: BioSentinel Bio Payload
 * @note Processor: MSP430FR6989
 * @note Compiler: MSP-430 TI 4.4.5
 * $Id$
 */

#include "drv_logger.h"
// Application header files
#include "bsp_pins_conf.h"
#include "bsp_pins.h"
#include "bsp_pins_types.h"
#include "util_log.h"
#include "drv_ds3234.h"
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
void get_time (char * const buffer, const uint8_t buff_sz);

void error_logger_log (const char * msg);

void trace_logger_log (const char * msg);

void info_logger_log (const char * msg);

void init_uart (void);
// *****************************************************************************
// Private inline function definitions
// *****************************************************************************

// *****************************************************************************
// Public function bodies
// *****************************************************************************

void logger_init(void)
{
    init_uart();
    util_log_init(TRACE, "Optics_Reader", error_logger_log, info_logger_log,
                  trace_logger_log, get_time);
}

// *****************************************************************************
// Private function bodies
// *****************************************************************************

void get_time(char * const buffer, const uint8_t buff_sz)
{
    rtc_t current_time = drv_rtc_read_time_date();

    snprintf(buffer, buff_sz, "20%02d%02d%02d %02d:%02d:%02d",
             current_time.year,
             current_time.month,
             current_time.day,
             current_time.hour,
             current_time.minute,
             current_time.second);
}
void error_logger_log (const char * msg)
{
    fputs("%s", msg);
}
void trace_logger_log (const char * msg)
{
    fputs(msg, 0);
}
void info_logger_log (const char * msg)
{
    fputs(msg, 0);
    cout_data_channel(msg);

}



// *****************************************************************************
// Interrupt Service Routine bodies
// *****************************************************************************
