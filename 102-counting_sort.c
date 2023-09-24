#include "sort.h"

/**
 * counting_sort - sorts an array of integers using
 * the counting sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void counting_sort(int *array, size_t size)
{
	int i, k = 0, *new, *sort;

	for (i = 0; i < (int)size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	sort = malloc(sizeof(int) * (k + 1));
	if (!sort)
	{
		free(new);
		return;
	}
	for (i = 0; i < (k + 1); i++)
		sort[i] = 0;
	for (i = 0; i < (int)size; i++)
		sort[array[i]] += 1;
	for (i = 1; i < (k + 1); i++)
		sort[i] += sort[i - 1];
	print_array(sort, k + 1);
	for (i = 0; i < (int)size; i++)
	{
		new[sort[array[i]] - 1] = array[i];
		sort[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new[i];
	free(sort);
	free(new);
}

