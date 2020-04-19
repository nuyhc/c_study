#include "hw1_calculator.h"

/*
@brief: Calculator init, allocate Mem
*/
hw1_calculator_t* hw1_calculator_init(){
	hw1_calculator_t *calculator = ( hw1_calculator_t*)malloc( sizeof( hw1_calculator_t*));
	calculator->data = 0;
	calculator->count = 0;
	return calculator;
}

/*
@brief: Destroy Calculator, returning Mem
@param: hw_calculator_t* calculator
*/
void hw1_calculator_destroy( hw1_calculator_t *calculator){
	if( calculator){
		free( calculator);
	}
}

/*
@brief: Get Calculator's count #
@param: hw1_calculator_t* calculator
@return: enum error
*/
int hw1_calculator_get_count( hw1_calculator_t *calculator){
	if( calculator){
		return calculator->count;
	}
	else{
		printf("(hw1_calculator) { Fail to get count, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}

/*
@brief: Plus Calculator's count #
@param: hw1_calculator_t* calculator
@return: int count
@return: enum error
*/
int hw1_calculator_plus_count( hw1_calculator_t *calculator){
	if( calculator){
		if( hw1_calculator_get_count( calculator) > CAL_MAX_NUM){
			printf("(hw1_calculator) { Fail to plus count, count is MAX value }\n");
			calculator->error = COUNT_FULL;
			return calculator->error;
		}
		else{
			return ++( calculator->count);
		}
	}
	else{
		printf("(hw1_calculator) { Fail to plus count, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}

/*
@brief: Minus Calculator's count #
@param: hw1_calculator_t* calculator
@return: int count
@return: enum error
*/
int hw1_calculator_minus_count( hw1_calculator_t *calculator){
	if( calculator){
		if( hw1_calculator_get_count( calculator) == 0){
			printf("(hw1_calculator) { Fail to minus count, calculator is 0 }\n");
			calculator->error = COUNT_ZERO;
			return calculator->error;
		}
		else{
			return --( calculator->count);
		}
	}
	else{
		printf("(hw1_calculator) { Fail to minus count, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}

/*
@brief: Get Calculator's data
@param: hw1_calculator_t* calculator
@return int data
@return enum error
*/
int hw1_calculator_get_data( hw1_calculator_t *calculator){
	if( calculator){
		return calculator->data;
	}
	else{
		printf("(hw1_calculator) { Fail to get data, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}
}

/*
@brief: Processing Calculator's data
@param: hw1_calculator_t* calculator
@param: int data
@return: int data
@return: enum error
*/
int hw1_calculator_process_data( hw1_calculator_t *calculator, int data){
	if( calculator){
		int rv, temp_data;

		temp_data = hw1_calculator_get_data( calculator);
		if( temp_data < 0){
			printf("(hw1_calculator) { rv = %d }\n", rv);
			return calculator->error;
		}
		else if( temp_data > data){
			printf("(hw1_calculator) { Fail to process data }\n");
			printf("(hw1_calculator) { Received data is less than saved data }\n");
			calculator->error = DATA_LESS;
			return calculator->error;
		}

		rv = hw1_calculator_plus_count( calculator);
		if( rv < 0){
			printf("(hw1_calculator) { rv = %d }\n", rv);
			return calculator->error;
		}
		
		(calculator->data) += data;
		printf("\n(hw1_calculator) [ Success to process data, saved data : %d ]\n\n", calculator->data);
		return calculator->data;
	}
	else{
		printf("(hw1_calculator) { Fail to process data, calculator is NULL }\n");
		calculator->error = OBJ_NULL;
		return calculator->error;
	}

}

