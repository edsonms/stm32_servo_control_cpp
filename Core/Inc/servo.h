#ifndef _SERVO_H
#define _SERVO_H

#include "pinmap.h"

class Servo
{
    private:

    public:
        Servo(pinStruct_t &servoPin,
            TIM_TypeDef* TIMx, 
            uint8_t gpioAFSelTIMx,
            uint8_t pwmChannel); //Constructor
};

#endif
