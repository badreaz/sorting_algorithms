#include "sort.h"

/**
 * quick_sort - sorts an array of integers using
 * quick sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void quick_sort(int *array, size_t size)
{
	int pivot, i, j, tmp;

	for (i = 0; i < (int)size; i++)
	{
		pivot = array[size - i];
		for (j = i; j < (int)size - i; j++)
		{
			if (array[j] < pivot)
			{
				tmp = array[j];
				array[j] = pivot;
				array[size - i] = tmp;
			}
		}
		tmp = array[i + 1];
	}
}
