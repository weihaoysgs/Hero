#ifndef __MATH2_H_
#define __MATH2_H_

#include "stm32f4xx.h"

void Int16_Constrain(int16_t* data, int16_t min_value, int16_t max_value);
int16_t Int16_Limit(int16_t data, int16_t min_value, int16_t max_value);

#endif // __MATH2_H_