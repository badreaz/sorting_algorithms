#include "sort.h"

int partition(int *array, int size, int lo, int hi);
void sort(int *array, int size, int lo, int hi);

/**
 * quick_sort - sorts an array of integers using
 * quick sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}

/**
 * sort - quick sort recursion
 * @array: array of int.
 * @size: array sizze.
 * @lo: start index.
 * @hi: end index.
 */
void sort(int *array, int size, int lo, int hi)
{
	int ret;

	if (hi - lo > 0)
	{
		ret = partition(array, size, lo, hi);
		sort(array, size, lo, ret - 1);
		sort(array, size, ret + 1, hi);
	}
}

/**
 * partition - divides array into twpo partitions then sort them
 * @array: array of int.
 * @size: array size.
 * @lo: lowest int.
 * @hi: highest int.
 *
 * Return: int.
 */
int partition(int *array, int size, int lo, int hi)
{
	int pivot, i, j, tmp;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot)
	{
		tmp = array[hi];
		array[hi] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}

	return (i);
}
