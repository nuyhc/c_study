#ifndef __HW1_ERROR_H__
#define __HW1_ERROR_H__

#include <stdio.h>

typedef enum hw1_error_s hw1_error_t;
enum hw1_error_s{
	DATA_LESS = -4,
	COUNT_ZERO,
	COUNT_FULL,
	OBJ_NULL
};

#endif

