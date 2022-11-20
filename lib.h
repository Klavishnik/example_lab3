#pragma once

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

static char *ErrorNmes[] = {
    "Success",
    "Array size is negative or zero value",
    "Array is not empty",
    "Array is empty",
    "Index of array negative or more size of array"
};

enum Returns
{
        OK,
        SIZE_ERROR,
        ARRAY_NOT_EMPTY,
	ARRAY_EMPTY,
	INDEX_ERROR
};
//DESCRIPTION:
//Function allocates memory nd fill elements  of array from keyboard
//
//PARAMETRS:
//first arg - adress of array
//second - size of array
//
//RETURN VALUE:
//OK - fill succesfull
//SIZE_ERROR - size of array are negative of zero
//ARRAY_NOT_EMPTY - pointer to array is not NULL
int array_fill(int ** array, int size_array);

//DESCRIPTION:
//Function print message of exit status function 
//
//PARAMETRS:
//first arg - return code 
//
//RETURN VALUE:
//OK - fill succesfull
//SIZE_ERROR - size of array are negative of zero
int code_exit_print(int code);


//DESCRIPTION:
//Function pricnt values of array to stdout
//
//PARAMETRS:
//first arg - pointer to array
//second arg - size of array
//
//RETURN VALUE:
//OK - printf succesfull
//SIZE_ERROR - size of array are negative of zero
//ARRAY_EMPTY - pointer is EMPTY
int array_print(int * array, int size);


//DESCRIPTION:
//Function remove one element from array and move another element right of index to left. After that make realloc
//
//PARAMETRS:
//first arg - address  of array
//second arg - pointer size of array (after realloc  it will be -1)
//third arg - index element whick will be remove
//
//RETURN VALUE:
//OK - printf succesfull
//SIZE_ERROR - size of array are negative of zero
//ARRAY_EMPTY - pointer is EMPTY
//INDEX_ERROR - index is negitve of more than size
int array_remove(int ** array, int * size, int index);


#endif
