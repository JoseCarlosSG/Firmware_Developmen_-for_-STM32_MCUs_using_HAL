#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_msp.h"
#include <stdio.h>
#include <string.h>

UART_HandleTypeDef huart2;
int main(void) {

  HAL_Init();
  /* Configure the system clock to 64 MHz */
  SystemClock_Config();
  /*Setting up tick variable*/
  HAL_InitTick(TICK_INT_PRIORITY);
  
  UART_Init(&huart2);
  
  //char loop_message[] = "This is a test message.\n";
  char message[50]; // Buffer para almacenar la cadena
  float number = 123.456; // Número de punto flotante a enviar
  while (1) {
      HAL_Delay(1000);
      // Convierte el número de punto flotante en una cadena
      snprintf(message, sizeof(message), "Number: %.2f\n", number);

      // Envía el mensaje por UART
      HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), HAL_MAX_DELAY);
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

