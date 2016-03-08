/**
 * @file drv_ds3234.c
 * @brief
 * @details
 * @copyright COPYRIGHT NOTICE: (c) 2016 NASA Ames Research Center
 * @note ROM: BioSentinel Bio Payload
 * @note Processor: MSP430FR6989
 * @note Compiler: MSP-430 TI 4.4.5
 * $Id$
 */

#include "drv_ds3234.h"
// Application header files
#include "bsp_pins.h"
#include "bsp_pins_conf.h"
// Internal library header files
// Third-party library header files
#include <driverlib.h>
// Standard library header files
#include <stdint.h>
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




void drv_rtc_init(void){



	EUSCI_B_SPI_initMasterParam spi_b0_param = { 	EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
													8000000,
													8000000,
													EUSCI_B_SPI_MSB_FIRST,
													EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,
													EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW,
													EUSCI_B_SPI_3PIN
												};


	 EUSCI_B_SPI_initMaster(EUSCI_B0_BASE, &spi_b0_param);
	 EUSCI_B_SPI_enable(EUSCI_B0_BASE);
	  //pinMode(cs,OUTPUT); // chip select
	  // start the SPI library:
	  //SPI.begin();
	  //SPI.setBitOrder(MSBFIRST);
	  //SPI.setDataMode(SPI_MODE1); // both mode 1 & 3 should work
	  //set control register
	  //digitalWrite(cs, LOW);
	 bsp_pin_digital_write(&pins.rtc_cs,ENABLED);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
	 EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,0x8E);
	  //SPI.transfer(0x8E);
	  //SPI.transfer(0x60); //60= disable Osciallator and Battery SQ wave @1hz, temp compensation, Alarms disabled

		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
	 EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,0x60);
	  //digitalWrite(cs, HIGH);

	 bsp_pin_digital_write(&pins.rtc_cs,DISABLED);

	 //delay(10);
}

void drv_rtc_set_time_date(rtc_t set_time){
	uint8_t TimeDate [7]={set_time.second,
						  set_time.minute,
						  set_time.hour,
						  0,
						  set_time.day,
						  set_time.month,
						  set_time.year};
	//uint8_t TimeDate [7]={s,mi,h,0,d,mo,y};
	uint8_t i;
	for(i=0; i<=6;i++){
		if(i==3)
			i++;
		int b= TimeDate[i]/10;
		int a= TimeDate[i]-b*10;
		if(i==2){
			if (b==2)
				b=0b00000010;
			else if (b==1)
				b=0b00000001;
		}
		TimeDate[i]= a+(b<<4);

		//digitalWrite(cs, LOW);
		bsp_pin_digital_write(&pins.rtc_cs,ENABLED);
		//SPI.transfer(i+0x80);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
		EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,i+0x80);
		//SPI.transfer(TimeDate[i]);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
		EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,TimeDate[i]);
		//digitalWrite(cs, HIGH);
		bsp_pin_digital_write(&pins.rtc_cs,DISABLED);
  }
}
//=====================================
rtc_t drv_rtc_read_time_date(void){
	char temp[50];
	int TimeDate [7]; //second,minute,hour,null,day,month,year
	uint8_t i;
	for( i=0; i<=6;i++){
		if(i==3)
			i++;
		//digitalWrite(cs, LOW);
		bsp_pin_digital_write(&pins.rtc_cs,ENABLED);
		//SPI.transfer(i+0x00);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
		EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,i+0x00);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
		EUSCI_B_SPI_transmitData(EUSCI_B0_BASE ,0x00);
		while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE));
		unsigned int n = EUSCI_B_SPI_receiveData(EUSCI_B0_BASE);
		//digitalWrite(cs, HIGH);
		bsp_pin_digital_write(&pins.rtc_cs,DISABLED);
		int a=n & 0b00001111;
		if(i==2){
			int b=(n & 0b00110000)>>4; //24 hour mode
			if(b==0b00000010)
				b=20;
			else if(b==0b00000001)
				b=10;
			TimeDate[i]=a+b;
		}
		else if(i==4){
			int b=(n & 0b00110000)>>4;
			TimeDate[i]=a+b*10;
		}
		else if(i==5){
			int b=(n & 0b00010000)>>4;
			TimeDate[i]=a+b*10;
		}
		else if(i==6){
			int b=(n & 0b11110000)>>4;
			TimeDate[i]=a+b*10;
		}
		else{
			int b=(n & 0b01110000)>>4;
			TimeDate[i]=a+b*10;
			}
	}
	rtc_t current_time;
	current_time.second = TimeDate[0];
	current_time.minute = TimeDate[1];
	current_time.hour   = TimeDate[2];
	current_time.day    = TimeDate[4];
	current_time.month  = TimeDate[5];
	current_time.year   = TimeDate[6];
	//sprintf(&temp,"%u/%u/%u %u:%u:%u",TimeDate[4],TimeDate[5],TimeDate[6],TimeDate[2],TimeDate[1],TimeDate[0]);
//	strcat(temp,TimeDate[4]);
//	strcat(temp,"/") ;
//	strcat(temp,TimeDate[5]);
//	strcat(temp,"/") ;
//	strcat(temp,TimeDate[6]);
//	strcat(temp,"     ") ;
//	strcat(temp,TimeDate[2]);
//	strcat(temp,":") ;
//	strcat(temp,TimeDate[1]);
//	strcat(temp,":") ;
//	strcat(temp,TimeDate[0]);

//	temp.concat(TimeDate[4]);
//	temp.concat("/") ;
//	temp.concat(TimeDate[5]);
//	temp.concat("/") ;
//	temp.concat(TimeDate[6]);
//	temp.concat("     ") ;
//	temp.concat(TimeDate[2]);
//	temp.concat(":") ;
//	temp.concat(TimeDate[1]);
//	temp.concat(":") ;
//	temp.concat(TimeDate[0]);
  return(current_time);
}
// *****************************************************************************
// Private function bodies
// *****************************************************************************

// *****************************************************************************
// Interrupt Service Routine bodies
// *****************************************************************************
