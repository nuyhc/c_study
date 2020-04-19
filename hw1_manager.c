#include "hw1_manager.h"

/*
@brief: Manager init, allocate Mem
*/
hw1_manager_t* hw1_manager_init(){
	hw1_manager_t *manager = ( hw1_manager_t*)malloc( sizeof( hw1_manager_t));
	manager->name = NULL;
	manager->calculator = hw1_calculator_init();
	if( manager->calculator == NULL){
		return NULL;
	}
	return manager;
}

/*
@brief: Destroy Manager, returning Mem
@param: hw1_manager_t* manager
*/
void hw1_manager_destroy( hw1_manager_t *manager){
	if( manager){
		if( manager->calculator){
			hw1_calculator_destroy( manager->calculator);
		}
		free( manager);
	}
}

/*
@brief: Set Manager's Name
@param: hw1_manager_t* manager
@param: char* name
@return: char* name
@return: NULL
*/
char* hw1_manager_set_name( hw1_manager_t *manager, char *name){
	if( manager){
		memcpy( manager->name, name, strlen(name));
		return manager->name;
	}
	else{
		printf("(hw1_manager) { Fail to set name, manager is NULL }\n");
		return NULL;
	}
}

/*
@brief: Make a Calculator do work
@param: hw1_manager_t* manager
@param: int data
*/
void hw1_manager_process_data( hw1_manager_t *manager, int data){
	int rv;
	rv = hw1_calculator_process_data( manager->calculator, data);
	if( rv < 0){
		printf("(hw1_manager) { rv = %d }\n", rv);
	}
}

