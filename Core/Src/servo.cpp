#include "servo.h"

Servo::Servo(pinStruct_t &servoPin,
    TIM_TypeDef* TIMx, 
    uint8_t gpioAFSelTIMx,
    uint8_t pwmChannel)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = servoPin.selectedPin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = 
    GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = gpioAFSelTIMx;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    //Timer Config    
    TIM_OC_InitTypeDef sConfigOC = {0};

    TIM_HandleTypeDef htim4;
    htim4.Instance = TIMx;
    htim4.Init.Prescaler = 10 - 1;
    htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim4.Init.Period = 32000 - 1;
    htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_PWM_Init(&htim4);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 2250;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, pwmChannel);

    HAL_TIM_PWM_Start(&htim4,pwmChannel);
}