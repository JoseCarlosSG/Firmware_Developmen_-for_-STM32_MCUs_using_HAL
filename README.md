
---

# Project Documentation

This file describes the required source files, directory structure, URLs to obtain source files, specific configurations, and important notes.

---

## Directory Contents and Source Files

### Application File Directory and Setup
- **File:** `Application/make`  
  - **Description:** Makefile.  
  - **Note:** If the compiler requests it, define the function `void _init() {}` in your code to avoid linker errors.

---

### CMSIS File Directory and Setup
- **Directory:** `CMSIS/Inc/`  
  - **Content:** CMSIS header files.  
  - **Setup:** None.  
  - **Source:**  
    [CMSIS Core Include](https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Drivers/CMSIS/Core/Include)

---

### Device Files Directory and Setup

| File                                | Description                                      | Setup                                                                 |
|-------------------------------------|--------------------------------------------------|-----------------------------------------------------------------------|
| `Device/Inc/stm32f4xx.h`            | STM32F4xx MCU definitions.                      | Uncomment target MCU definition.                                     |
| `Device/Inc/stm32f411xe.h`          | STM32F411 register definitions.                 | None.                                                                 |
| `Device/Src/system_stm32f4xx.c`     | STM32F4xx system clock configuration file.      | None.                                                                 |
| `Device/Src/system_stm32f4xx.h`     | System clock header file.                       | Verify that `AHBPrescTable` and `APBPrescTable` are defined as `extern`. Ensure `stm32f3xx_hal_rcc.c` includes `system_stm32f3xx.h`. |
| `Device/Src/startup_stm32f411xe.s`  | STM32F411 startup file.                         | None.                                                                 |
| `Device/Src/stm32f4xx_it.c`         | Interrupt handlers.                             | Verify that system interrupts are implemented.                        |
| `Device/Inc/stm32f4xx_it.h`         | Interrupt handler header file.                  | Verify that system interrupts are defined.                            |
| `Device/Inc/STM32F411RETx_FLASH.ld` | Linker script.                                  | None.                                                                 |

- **Sources:**
  - [CMSIS Device Include Files](https://github.com/STMicroelectronics/cmsis-device-f4/tree/cdbad761857acedcdd07ece7939b4cb209ed826a/Include)
  - [Template Source Files](https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Projects/STM32F411RE-Nucleo/Templates/Src)
  - [Template Header Files](https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Projects/STM32F411RE-Nucleo/Templates/Inc)
  - [Linker File](https://github.com/STMicroelectronics/STM32CubeF4/blob/master/Projects/STM32F411RE-Nucleo/Templates/STM32CubeIDE/STM32F411RETX_FLASH.ld)
  - [Startup File](https://github.com/STMicroelectronics/cmsis-device-f4/tree/cdbad761857acedcdd07ece7939b4cb209ed826a/Source/Templates/gcc)

---

### HAL File Directory and Setup
- **Directories:**
  - `HAL/Inc/`: HAL header files.  
  - `HAL/Src/`: HAL source files.

- **Setup:**
  - `HAL/Src/stm32f4xx_hal_msp.c`: HAL MSP module.
  - `HAL/Inc/stm32f4xx_hal_msp.h`: HAL MSP header.
  - `HAL/Inc/stm32f4xx_hal_conf.h`: HAL configuration file.

- **Sources:**
  - [HAL Driver Include Files](https://github.com/STMicroelectronics/stm32f4xx-hal-driver/tree/8f20a7dfd0b5902e1a5796be78ed2ceddd342085/Inc)
  - [HAL Driver Source Files](https://github.com/STMicroelectronics/stm32f4xx-hal-driver/tree/8f20a7dfd0b5902e1a5796be78ed2ceddd342085/Src)

---

## Important Notes

- **Usage of HAL_Delay():**  
  Be cautious when using `HAL_Delay()` as this function provides accurate delays in milliseconds based on a variable incremented in the `SysTick` interrupt. If called from a peripheral ISR process, the `SysTick` interrupt must have higher priority (numerically lower) than the peripheral interrupt.  
  - To change the priority of the `SysTick` interrupt, use the function `HAL_NVIC_SetPriority()`.

- **SysTick Time Base:**  
  It is recommended that the SysTick time base is always set to 1 millisecond to ensure correct HAL operation.

---

This version is now in English and properly formatted for use in a `README.md` file on GitHub. Let me know if you'd like any further adjustments!
