#include "sort.h"

/**
 * heap_sort - sorts an array of integers using
 * the heap algorithm.
 * @array: array of int.
 * @size: size of array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, max, left, right;
	int tmp;

	for (i = size / 2; i > 0; i--)
	{
		max = i - 1;
		left = 2 * (i - 1) + 1;
		right = 2 * (i - 1) + 2;
		if (left < size && array[left] > array[max])
			max = left;
		if (right < size && array[right] > array[max])
			max = right;
		if (max != i - 1)
		{
			tmp = array[i - 1];
			array[i - 1] = array[max];
			array[max] = tmp;
			print_array(array, size);
		}
	}

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
