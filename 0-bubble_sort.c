#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm.
 * @array: array of integers.
 * @size: array size.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp, swap = 1;

	while (swap)
	{
		swap = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}

