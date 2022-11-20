
#include "lib.h"


static char *ErrorNmes[] = {
    "Success",
    "Array size is negative or zero value",
    "Array is not empty",
    "Array is empty",
    "Index of array negative or more size of array"
};


//------------------private functions-----------------------------//
int max_module(int input)
{
	int out = 0;
	int local_max = 0;
	int copy_input = input;
	if (input <= 0)
		return -1;
	for(int i = 9; i > 0; i--)
	{
		copy_input = input;
		while(copy_input)
		{	
			if(copy_input % 10 == i)
				out = out * 10 + i;
			copy_input = copy_input / 10;
		}
	}

	return out;

}

//------------------public functions-----------------------------//

int array_fill(int ** array, int size_array)
{
	if( size_array <= 0)
                return SIZE_ERROR;

        if( *array != NULL)
                return ARRAY_NOT_EMPTY;

	*array = (int *) malloc( size_array * sizeof(int) );
        for (int i = 0; i < size_array; i++)
        {
                printf("[%i]:", i);
        	scanf("%i", *array + i);
        }
	
	return OK;
}    


int code_exit_print(int code)
{
	if( (code < 0) || (code > sizeof(ErrorNmes) / sizeof(ErrorNmes[0])) )
		return SIZE_ERROR;

	printf("%s\n", ErrorNmes[code]);
	return OK;
}

int array_print(int * array, int size)
{
	if( size <= 0 )
        	return SIZE_ERROR;

        if( array == NULL)
                return ARRAY_EMPTY;

	for(int i = 0; i < size; i++)
		printf("[%i]: %i \n", i , array[i]);
	return OK;
}


int array_remove(int ** array, int * size, int index)
{

	if( *size <= 0)
               return SIZE_ERROR;

        if( *array == NULL)
                return ARRAY_EMPTY;

	if( (index < 0) || (index > *size ))
		return INDEX_ERROR;

	for( int i = index; i < *size - 1; i++)
	{
		(*array)[i] = (*array)[i + 1];
	}

	*size = *size - 1;
	*array = realloc(*array, *size * sizeof(int));
	
	return OK;

}


int main_task(int ** arr_in, int * arr_in_size, int ** arr_out, int * arr_out_size)
{
	if( *arr_in == NULL)
		return ARRAY_EMPTY;
	if(*arr_out != NULL)
		return ARRAY_NOT_EMPTY;
	if( *arr_in_size <= 0 )
		return SIZE_ERROR;
	
	//find elements 
	
	for( int i = 0;  i < *arr_in_size; i++)
	{
		int new_value = max_module( (*arr_in)[i] );
		if( (*arr_in)[i] == new_value )
		{
			array_push(arr_out, arr_out_size, (*arr_in)[i]);
			array_remove(arr_in, arr_in_size, i--);
		}
		else
		{
			(*arr_in)[i] = new_value;
		}

	}
	return OK;
}

int array_push(int ** array, int * size, int element)
{
	if( *size < 0)
               return SIZE_ERROR;
	
	*array = realloc(*array, (*size + 1) * sizeof(int));
	(*array)[*size] = element;
	*size = *size + 1;
	
	return OK;
}


