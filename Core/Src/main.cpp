#include "servo.h"

int main (void)
{

  HAL_Init();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM4_CLK_ENABLE();

  pinStruct_t servoPin = {GPIOB,GPIO_PIN_8};
  Servo servo(servoPin,TIM4,GPIO_AF2_TIM4,TIM_CHANNEL_3);

  //Loop forever
  while(true)
  {
    //Do something
  }

}