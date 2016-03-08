#ifndef DRV_SD3234_H
#define DRV_SD3234_H

/**
 * @file drv_ds3234.h
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

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Public macro definitions
// *****************************************************************************

// *****************************************************************************
// Public data type definitions (enum, struct, typedef, union)
// *****************************************************************************

typedef struct
{
	/// day(1-31)
	uint8_t day;

	/// month(1-12)
	uint8_t month;

	/// year(0-99)
	uint8_t year;

	/// hour(0-23)
	uint8_t hour;

	/// minute(0-59)
	uint8_t minute;

	/// second(0-59)
	uint8_t second;

	/// time zone
	char zone[4];
}rtc_t, *rtc_t_ptr;

// *****************************************************************************
// Public constant definitions
// *****************************************************************************

// *****************************************************************************
// Public function prototypes
// *****************************************************************************

void drv_rtc_init(void);
void drv_rtc_set_time_date(rtc_t set_time);
rtc_t drv_rtc_read_time_date(void);
// *****************************************************************************
// Public inline function definitions
// *****************************************************************************

#ifdef __cplusplus
}
#endif

#endif // DRV_SD3234_H
