#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the
 * shell sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 0;
	int tmp;

	while (gap < size / 3)
		gap = 3 * gap + 1;
	for (; gap >= 1; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[i])
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
