#pragma once

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

static char *ErrorNmes[] = {
    "Success",
    "Array size is negative or zero value",
    "Array is not empty",
    "Array is empty"
};

enum Returns
{
        OK,
        SIZE_ERROR,
        ARRAY_NOT_EMPTY,
	ARRAY_EMPTY
};
//DESCRIPTION:
//Function allocates memory nd fill elements  of array from keyboard
//
//PARAMETRS:
//first arg - adress of array
//second - size of array
//
//RETURN VALUE:
//0 - fill succesfull
//1 - array is empty
//2 - size of array are negative of zero
int array_fill(int ** array, int size_array);

//DESCRIPTION:
//Function print message of exit status function 
//
//PARAMETRS:
//first arg - return code 
//
//RETURN VALUE:
//0 - fill succesfull
//1 - size of array are negative of zero
int code_exit_print(int code);


//DESCRIPTION:
//Function pricnt values of array to stdout
//
//PARAMETRS:
//first arg - pointer to array
//second arg - size of array
//
//RETURN VALUE:
//0 - printf succesfull
//1 - size of array are negative of zero
//3 - pointer is EMPTY
int array_print(int * array, int size);


#endif
