#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{

	char task[] = {"Для каждого элемента массива переделать его так, чтобы оно стало максимальным по модулю. Удалить из исходного массива элементы которые не изменились и добавить их во второй массив"};

	int * arr_in = NULL;
	int * arr_out = NULL;

	int arr_in_size = 0;
	int arr_out_size = 0;
	
	int return_code = 0;

	printf("%s\n", task);
	printf("Enter size of array\n");
	scanf("%i",&arr_in_size);

	return_code = array_fill(&arr_in, arr_in_size);
	if(return_code)
	{
		code_exit_print(return_code);
		return 1;
	}

	printf("Original array\n");
	array_print(arr_in, arr_in_size);
	

	return_code = main_task(&arr_in, &arr_in_size, &arr_out, &arr_out_size);
	if(return_code)
		code_exit_print(return_code);
		

	printf("Array 1\n");
	array_print(arr_in, arr_in_size);


	printf("Array 2\n");
	array_print(arr_out, arr_out_size);

	free(arr_in);
	free(arr_out);
	return 0;
}




