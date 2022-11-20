#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{

	int * arr_in = NULL;
	int * arr_out = NULL;

	int arr_in_size = 0;
	int arr_out_size = 0;
	
	int return_code = 0;

	printf("Helllo\n");
	printf("Enter size of array\n");
	scanf("%i",&arr_in_size);

	return_code = array_fill(&arr_in, arr_in_size);
	if(return_code)
	{
		code_exit_print(return_code);
		return 1;
	}

	array_print(arr_in, arr_in_size);
	

	



	free(arr_in);
	return 0;
}



