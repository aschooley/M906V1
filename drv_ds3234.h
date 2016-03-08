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

/**
 * Real time clock structure.  Holds info read and written to the ds3234 device.
 */
typedef struct
{
	/// year(0-99)
	uint8_t year;

	/// month(1-12)
	uint8_t month;

	/// day(1-31)
	uint8_t day;

	/// hour(0-23)
	uint8_t hour;

	/// minute(0-59)
	uint8_t minute;

	/// second(0-59)
	uint8_t second;

}rtc_t, *rtc_t_ptr;

// *****************************************************************************
// Public constant definitions
// *****************************************************************************

// *****************************************************************************
// Public function prototypes
// *****************************************************************************

/**
 * Setup the RTC chip.  SPI settings are hardcoded for the M906 board.  Will
 * send the configuration commands to the RTC chip.
 */
void drv_rtc_init(void);

/**
 * Set the date and time on the chip.
 * @param[in] set_time structure that contains the date and time info.
 */
void drv_rtc_set_time_date(rtc_t * set_time);

/**
 * Read out the date and time from the RTC chip.
 * @return structure that contains the date and time info.
 */
rtc_t drv_rtc_read_time_date(void);

/**
 * Unpack a rtc struct into a BCD encoded array.
 * @param[in] structure to convert.
 * @param[out] array to put the values into.
 * @retval[true] array size was large enough, conversion done.
 * @retfal[false] array size was not sufficient, conversion aborted.
 */
bool drv_rtc_convert_struct_to_array(rtc_t * structure, uint8_t * bcd_array, uint8_t array_sz);

/**
 * Unpack a BCD encoded array into a rtc struct.
 * @param[in] array to convert.
 * @param[out] structure to put the converted values into.
 */
void drv_rtc_convert_array_to_struct(uint8_t * bcd_array, rtc_t * structure);

// *****************************************************************************
// Public inline function definitions
// *****************************************************************************

#ifdef __cplusplus
}
#endif

#endif // DRV_SD3234_H
