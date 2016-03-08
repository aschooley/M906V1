/**
 * @file main.c
 * @brief Contains the entry point for the software.
 * @details
 * @copyright COPYRIGHT NOTICE: (c) 2016 NASA Ames Research Center
 * @note ROM: BioSentinel Bio Payload
 * @note Processor: MSP430FR6989
 * @note Compiler: MSP-430 TI 4.4.5
 * $Id$
 */

#include "main.h"
// Application header files
#include "bsp_pins.h"
#include "bsp_pins_conf.h"
#include "bsp_pins_types.h"
#include "drv_logger.h"
#include "util_log.h"
#include "drv_ds3234.h"
#include "bsp_uart.h"
// Internal library header files
#include "ow/ownet.h"
#include "ow/mbnv.h"
// Third-party library header files
#include <msp430.h>
#include <driverlib.h>
// Standard library header files
#include <stdbool.h>
#include <stdint.h>

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


/*
 * Clock System Initialization
 */
void Init_Clock()
{
	 // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
	    GPIO_setAsPeripheralModuleFunctionInputPin(
	           GPIO_PORT_PJ,
	           GPIO_PIN4 + GPIO_PIN5,
	           GPIO_PRIMARY_MODULE_FUNCTION
	           );

    // Set DCO frequency to default 8MHz
    //CS_setDCOFreq(CS_DCORSEL_0, CS_DCOFSEL_6);

    // Configure MCLK and SMCLK to 8MHz
    //CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    //CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_MCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);

    // Intializes the XT1 crystal oscillator
    CS_turnOnLFXT(CS_LFXT_DRIVE_3);
}
// *****************************************************************************
// Public function bodies
// *****************************************************************************
/** A 1-wire ID is an array of 8 bytes. */
typedef uint8_t one_wire_id_t[8];
size_t abs_1_wire_find_devices(one_wire_id_t FamilySN[],
                               const size_t max_device_count)
{
	int portnum = owAcquire(0,"");;
	int NumDevices = 0;
	do
   {
	  // perform the search
	  if (!owNext(portnum,TRUE, FALSE))
		 break;

	  owSerialNum(portnum,FamilySN[NumDevices], TRUE);
	  NumDevices++;
   }
   while (NumDevices < (max_device_count - 1));
	return NumDevices;

}
static void report_1_wire_devices(void)
{
    static const size_t MAX_ID_COUNT = 16;
    one_wire_id_t       FamilySN[MAX_ID_COUNT];
    const size_t        count = abs_1_wire_find_devices(FamilySN, MAX_ID_COUNT);

    logf(INFO, "%u 1-wire device(s) found", count);
    size_t i;

    for (i = 0; i < count; i++)
    {
        // 8 bytes yields 16 hex digits, plus a NULL terminator
        char    hex_id[17] = "";
        uint8_t b;

        for (b = 0; b < 8; b++)
        {
            // 1 byte yields 2 hex digits, plus a NULL terminator
            char hex_byte[3];
            // Write the byte as a hex digit
            //lint -e{534} Return value is not needed
            sprintf(hex_byte, "%02X", FamilySN[i][b]);
            strncat(hex_id, hex_byte, 2);
        }
        //logf(INFO, "1-wire device %u: %s", i, hex_id);
        static const uint8_t eeprom_buff_sz = 20;
        char eeprom_buff[eeprom_buff_sz];
        readNV(0,0,FamilySN[i],0,0,eeprom_buff,1);
        const  uint8_t record_sz = eeprom_buff[0]>eeprom_buff_sz ? eeprom_buff_sz : eeprom_buff[0];

        readNV(0,0,FamilySN[i],1,1,eeprom_buff,record_sz);

        eeprom_buff[record_sz]=0;
        bsp_pin_digital_write(&pins.uart_1w_sd_sel,LOW);
        logf(INFO, "1-wire device %u: %s : %s", i, eeprom_buff, hex_id);
        bsp_pin_digital_write(&pins.uart_1w_sd_sel,HIGH);
    }

    bsp_pin_digital_write(&pins.uart_1w_sd_sel,LOW);
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    __enable_interrupt();

    Init_Clock();
    logger_init();

    bsp_pins_initalize();


    	drv_rtc_init();
      //day(1-31), month(1-12), year(0-99), hour(0-23), minute(0-59), second(0-59)
    	//rtc_ds3234_t set_time = {4,3,16,1,30,00};
      //drv_rtc_set_time_date(set_time);

    	bsp_pin_digital_write(&pins.sd_pwr_en, ENABLED);
    	bsp_pin_digital_write(&pins.logger_rst, DISABLED);
    	bsp_pin_digital_write(&pins.uart_1w_sd_sel, LOW);

    	while(pins.power_down.enabled_state == bsp_pin_digital_read(&pins.power_down));


        log(TRACE,"initalized");


        report_1_wire_devices();

#if 0
		#define MAXDEVICES 10
        struct
		{
        	int portnum;
        	int NumDevices;
        	uint8_t AllSN[MAXDEVICES][8];
		}ow;
		ow.portnum = owAcquire(0,"");
        ow.NumDevices = 0;
	   do
	   {
		  // perform the search
		  if (!owNext(ow.portnum,TRUE, FALSE))
			 break;

		  owSerialNum(ow.portnum,ow.AllSN[ow.NumDevices], TRUE);
		  ow.NumDevices++;
	   }
	   while (ow.NumDevices < (MAXDEVICES - 1));

#endif


    for(;;) {
        volatile uint32_t i;            // volatile to prevent optimization
        static uint32_t loop_counter = 0;
        if(pins.power_down.enabled_state == bsp_pin_digital_read(&pins.power_down))
        {
        	bsp_pin_digital_write(&pins.led_power_en, DISABLED);
        }
        else
        {
        	bsp_pin_digital_write(&pins.led_power_en, ENABLED);
        }
        trace("loop counter",loop_counter++);
        cout_data_channel("out data /r/n");

        bsp_pin_digital_toggle(&pins.led_1);

        i = 1000000;                          // SW Delay
        do i--;
        while(i != 0);
    }

    return 0;
}

// *****************************************************************************
// Private function bodies
// *****************************************************************************

// *****************************************************************************
// Interrupt Service Routine bodies
// *****************************************************************************
