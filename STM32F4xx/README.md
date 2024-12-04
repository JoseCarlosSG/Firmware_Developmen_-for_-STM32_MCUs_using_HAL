This file describe the required source files, directory structure, url to get source files, 
some file setting and important notes.  

@DIRECTORY CONTENTS AND SOURCE FILES

  @APPLICATION FILE DIRECTORY AND SETUP
  - Application/make			make file
  -Notes: If compiler request, define void _init() {} in your setup bussines code in order the link do not fail.
  
  @CMSIS FILE DIRECTORY AND SETUP
  
  - CMSIS/Inc/all_cmsis_header_files    cmsis header files
  - Set up: None
  - Source:
  https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Drivers/CMSIS/Core/Include
  
  @DEVICE FILES DIRECTORY AND SETUP							SETUP
  - Device/Inc/stm32f4xx.h		STM32F4xx MCU definitions			Uncomment target MCU definition
  - Device/Inc/stm32f411xe.h		STM32F411 Register definitions
  - Device/Src/system_stm32f4xx.c     	STM32F4xx system clock configuration file.	 
  - Device/Src/system_stm32f4xx.h     	STM32F4xx system clock header file.		Verify AHBPrescTable and APBPrescTable are defined as extern
  											Verify stm32f3xx_hal_rcc.c include system_stm32f3xx.h
  - Device/Src/startup_stm32f411xe.s	STM32F411 startup file.
  - Device/Src/stm32f4xx_it.c         	Interrupt handlers. 				Verify system interrupt are implemented
  - Device/Inc/stm32f4xx_it.h        	Interrupt handlers header file.			Verify system interrupt are defined
  - Device/Inc/STM32F411RETx_FLASH.ld	Linker script.
  
  
  - Source:
  This link contains system_stm32f4xx.h, stm32f4xx.h, stm32f411xe.h and others.
  https://github.com/STMicroelectronics/cmsis-device-f4/tree/cdbad761857acedcdd07ece7939b4cb209ed826a/Include

  This link contains the file stm32f4xx_hal_msp.c, stm32f4xx_it.c, system_stm32f4xx.c
  https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Projects/STM32F411RE-Nucleo/Templates/Src

  This link contains the file stm32f4xx_it.h
  https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Projects/STM32F411RE-Nucleo/Templates/Inc

  This link contains the linker file STM3F411RETX_FLASH.ld
  https://github.com/STMicroelectronics/STM32CubeF4/blob/master/Projects/STM32F411RE-Nucleo/Templates/STM32CubeIDE/STM32F411RETX_FLASH.ld

  This link contains startup_stm32f411xe.s.
  https://github.com/STMicroelectronics/cmsis-device-f4/tree/cdbad761857acedcdd07ece7939b4cb209ed826a/Source/Templates/gcc
  
  
  @HAL FILE DIRECTORY AND SETUP
  - HAL/Inc/all_hal_header_files    HAL header files.
  - HAL/Src/all_hal_source_files    HAL source files.
  
  -Setup:
  - HAL/Src/stm32f4xx_hal_msp.c   	HAL MSP module.
  - HAL/Inc/stm32f4xx_hal_msp.h   	HAL MSP header*
  - HAL/Inc/stm32f4xx_hal_conf.h  	HAL Configuration file.
  
  -Source:
  https://github.com/STMicroelectronics/stm32f4xx-hal-driver/tree/8f20a7dfd0b5902e1a5796be78ed2ceddd342085/Inc
  https://github.com/STMicroelectronics/stm32f4xx-hal-driver/tree/8f20a7dfd0b5902e1a5796be78ed2ceddd342085/Src


  
  @note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
  @note It is recommended SysTick time base is always set to 1 millisecond to have correct HAL operation.
