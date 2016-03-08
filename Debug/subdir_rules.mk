################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
bsp_pins.obj: ../bsp_pins.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="bsp_pins.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

bsp_pins_conf.obj: ../bsp_pins_conf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="bsp_pins_conf.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

bsp_uart.obj: ../bsp_uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="bsp_uart.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

drv_ds3234.obj: ../drv_ds3234.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="drv_ds3234.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

drv_logger.obj: ../drv_logger.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="drv_logger.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ow_lnk.obj: ../ow_lnk.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="ow_lnk.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

util_log.obj: ../util_log.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/developer/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/developer/workspace_v6_0/M906V1/driverlib/MSP430FR5xx_6xx" --include_path="/home/developer/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.7/include" --advice:power="all" --advice:hw_config=all -g --define=__MSP430FR6989__ --display_error_number --diag_warning=225 --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="util_log.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


