#include "sort.h"

void hoare_sort(int *array, int size, int lo, int hi);

/**
 * quick_sort_hoare - sort an array of integer using
 * quick sort algorithm.
 * @array: array of int.
 * @size: array size.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	hoare_sort(array, size,  0, size - 1);
}

/**
 * hoare_sort - implement quick sort using hoare partition
 * @array: array of int.
 * @size: array size.
 * @lo: start index/
 * @hi: end index/
 */
void hoare_sort(int *array, int size, int lo, int hi)
{
	int pivot, i, j, tmp;

	if (lo >= hi)
		return;
	pivot = array[hi];
	i = lo;
	j = hi;
	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	hoare_sort(array, size, lo, i - 1);
	hoare_sort(array, size, i, hi);
}
