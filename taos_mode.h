/*******************************************************************************
 *
 * taos_mode.h
 *
 * addresses the taos/led stack for biosentinel
 *
 * August 2015
 * A.Schooley
 *
 ******************************************************************************/

#ifndef TAOS_MODE_H_
#define TAOS_MODE_H_

#include "stdbool.h"

/*extern volatile unsigned char mode;
   extern volatile unsigned char S1buttonDebounce;
   extern volatile unsigned char S2buttonDebounce;
   extern Timer_B_initUpModeParam initUpParam_A0;
   extern volatile unsigned char stopWatchRunning;
   extern Calendar currentTime;
   extern volatile unsigned int counter;
   extern volatile int centisecond;*/

static const unsigned char taos_max_well_number     = 64;
static char const * const  taos_well_lookup_table[] =
{"1R ", "1G ", "1I ", "1X ",
 "2R ", "2G ", "2I ", "2X ",
 "3R ", "3G ", "3I ", "3X ",
 "4R ", "4G ", "4I ", "4X ",
 "5R ", "5G ", "5I ", "5X ",
 "6R ", "6G ", "6I ", "6X ",
 "7R ", "7G ", "7I ", "7X ",
 "8R ", "8G ", "8I ", "8X ",
 "9R ", "9G ", "9I ", "9X ",
 "10R", "10G", "10I", "10X",
 "11R", "11G", "11I", "11X",
 "12R", "12G", "12I", "12X",
 "13R", "13G", "13I", "13X",
 "14R", "14G", "14I", "14X",
 "15R", "15G", "15I", "15X",
 "16R", "16G", "16I", "16X"};

void taos_increment_well (void);
void taos_decrement_well (void);
unsigned char taos_get_current_well (void);
bool taos_set_current_well (unsigned char index);
void taos_output_enable (void);
void taos_output_disable (void);
void taos_mode_init (void);
void taos_mode (void);
char * taos_translate_well_index (unsigned char index);



#endif
