#pragma once

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

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
//first arg - return code (see Returns enum)
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


//DESCRIPTION:
//Function add new element to end of array
//It make realloc and change size to +1
//
//PARAMETRS:
//first arg - address  of array
//second arg - pointer size of array (after realloc  it will be +1)
//third arg - value whick will be writed to end of array
//
//RETURN VALUE:
//OK - printf succesfull
//SIZE_ERROR - size of array are negative of zero
int array_push(int ** array, int * size, int element);


//DESCRIPTION:
//for every element of array - make num to max (exmaple 123 -> 321)
//if old value of element and new match -> remove from first array and enter to new
//else - update new_value at orig array
//
//PARAMETRS:
//first arg - address  of array1
//second arg - pointer size of array1 (it will be decrease)
//third arg -  addres of array2
//fourth arg - pointer to size of aary2 (it will be increase)
//RETURN VALUE:
//OK - printf succesfull
//SIZE_ERROR - size of array1 are negative of zero
//ARRAY_NOT_EMPTY - second array not empty (may be thaths not error?)
//ARRAY_EMPTY - array1 is empty

int main_task(int ** arr_in, int * arr_in_size, int ** arr_out, int * arr_out_size);

#endif
