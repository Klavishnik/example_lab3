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
		printf("\n");
        }
	
	return OK;
}    


int code_exit_print(int code)
{
	if( (code < 0) || (code > sizeof(ErrorNmes / ErrorNmes[0]))
		return SIZE_ERROR;

	printf(ErrorNmes[code]);
	return OK;
}
