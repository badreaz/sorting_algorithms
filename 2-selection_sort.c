#include "sort.h"

/**
 * selection_sort - sorts an array using the
 * selection sorting algorithm.
 * @array: array of integers.
 * @size: array size.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, loc;
	int tmp;

	for (i = 0; i < size; i++)
	{
		loc = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[loc])
				loc = j;

		}
		if (loc != i)
		{
			tmp = array[loc];
			array[loc] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
