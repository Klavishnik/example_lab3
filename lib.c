//
//#include <stdlib.h>
//#include <stdio.h>
#include "lib.h"

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






//------------------private functions-----------------------------//
int max_module(int input)
{
	int out = 0;
	int local_max = 0;
	int copy_input = input;
	if (input <= 0)
		return -1;
	while(input)
	{	
		local_max = input % 10;
		while(copy_input)
		{
			int tmp = copy_input % 10;
			if( local_max < tmp )
				local_max = tmp;
			copy_input = copy_input / 10;
		}

		input = input / 10;
		copy_input = input;
		out = out * 10;
		out = out + local_max;
	}

	return out;

}


