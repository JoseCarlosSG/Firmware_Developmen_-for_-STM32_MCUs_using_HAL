#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_msp.h"
#include <string.h>

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
int main(void) {

  HAL_Init();
  /* Setup the system clock to 100 MHz */
  SystemClock_Config();
  /* Set tick interrupt priority*/
  HAL_InitTick(TICK_INT_PRIORITY);
  /* Setup led pin */
  GPIO_Config();
  /*Enable timer 1 on channel 1*/
  enable_tim1_ch1(&htim1);
    /*Enable timer 1 on channel 1*/
  enable_tim3_ch3(&htim3);
  // Iniciar PWM en TIM1_CH1 (PA8)
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  // Iniciar PWM en TIM3_CH3 (PB0)
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  
  while (1){
  /* Implementation here */
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

