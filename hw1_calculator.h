#ifndef __HW1_CALCULATOR_H__
#define __HW1_CALCULATOR_H__

#define CAL_MAX_NUM 100

#include <stdlib.h>
#include "hw1_error.h"

/*
@brief: Calculator Struct
@param: int data
@parma: int count
@param: hw1_error_t error
*/
typedef struct hw1_calculator_s hw1_calculator_t;
struct hw1_calculator_s{
	int data;
	int count;
	hw1_error_t error;
};

// Operators
hw1_calculator_t* hw1_calculator_init();
void hw1_calculator_destroy( hw1_calculator_t *calculator);
int hw1_calculator_get_count( hw1_calculator_t *calculator);
int hw1_calculator_plus_count( hw1_calculator_t *calculator);
int hw1_calculator_minus_count( hw1_calculator_t *calculator);
int hw1_calculator_get_data( hw1_calculator_t *calculator);
int hw1_calculator_process_data( hw1_calculator_t *calculator, int data);

#endif

