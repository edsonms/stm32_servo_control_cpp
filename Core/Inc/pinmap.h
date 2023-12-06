#ifndef _PINMAP_H
#define _PINMAP_H

#include "stm32l4xx_hal.h"

typedef struct
{
    GPIO_TypeDef* port;
    uint16_t selectedPin;
}pinStruct_t;

#endif
