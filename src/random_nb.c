#include "../include/nemergent.h"

int *get_rand_nb(int total)
{
	int	*arr;
	int	i;
	int	num;

	i = 0;
	num = 0;
	arr = malloc(sizeof(int) * total);
	if (!arr)
		return (perror("get_rand_nb: "), NULL);
	while (i < total)
	{
		num = rand(); 
		if (!is_duplicated(arr, i, num))
		{
			arr[i] = num; 
			i++;
		}
	}
	return (arr);
}

int is_duplicated(int *arr, int size, int value)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (arr[i] == value)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}