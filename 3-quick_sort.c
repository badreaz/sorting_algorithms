#include "sort.h"

void partition(int *array, int size, int lo, int hi);

/**
 * quick_sort - sorts an array of integers using
 * quick sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void quick_sort(int *array, size_t size)
{
	partition(array, size, 0, size - 1);
}

/**
 * partition - divides array into twpo partitions then sort them
 * @array: array of int.
 * @size: array size.
 * @lo: lowest int.
 * @hi: highest int.
 */
void partition(int *array, int size, int lo, int hi)
{
	int *pivot, i, j, tmp;

	if (lo >= hi || lo < 0)
		return;
	pivot = array + hi;
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < *pivot && i < j)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i++;
			print_array(array, size);
		}
		else if (i > j)
			i++;
	}
	if (array[i] > *pivot)
	{
		tmp = array[hi];
		array[hi] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}

	if (hi - lo > 0)
	{
		partition(array, size, lo, i - 1);
		partition(array, size, i + 1, hi);

	}
}
