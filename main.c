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

	array_push(&arr_in, &arr_in_size, 4);
	
	printf("changed array\n");
	array_print(arr_in, arr_in_size);


	array_remove(&arr_in, &arr_in_size, 0);

	printf("changed array\n");
	array_print(arr_in, arr_in_size);


	free(arr_in);
	return 0;
}




