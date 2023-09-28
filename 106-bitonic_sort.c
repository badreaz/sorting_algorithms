#include "sort.h"

void bitonic_seq(int *array, int low, int size, int ssize, int dir);
void merge(int *array, int low, int size, int ssize, int dir);


/**
 * bitonic_sort - sorts an array of integers using bitonic sort algorithm
 * @array: array to sort.
 * @size: array size.
 nt)*/
void bitonic_sort(int *array, size_t size)
{
	bitonic_seq(array, 0, size, size, 1);
}

/**
 * bitonic_seq - produce a bitonic sequence.
 * @array: array of int.
 * @low: start index.
 * @size: array size.
 * @ssize: subarray size.
 * @dir: sort direction.
 */
void bitonic_seq(int *array, int low, int size, int ssize, int dir)
{
	int k;

	if (ssize > 1)
	{
		k = ssize / 2;
		printf("Merging [%d/%d] (%s):\n", ssize, size, dir? "UP" : "DOWN");
		print_array(array + low, ssize);

		bitonic_seq(array, low, size, k, 1);
		bitonic_seq(array, low + k, size, k, 0);
		merge(array, low, size, ssize, dir);

		printf("Result [%d/%d] (%s):\n", ssize, size, dir? "UP" : "DOWN");
		print_array(array + low, ssize);
	}
}

/**
 * merge - merge a bitonic sequence in ascending oreder
 * @array: array of int.
 * @low: start index.
 * @size: array size.
 * @ssize: subarray size.
 * @dir: sort direction.
 */
void merge(int *array, int low, int size, int ssize, int dir)
{
	int i, k, tmp;

	if (ssize > 1)
	{
		k = ssize / 2;
		for (i = low; i < low + k; i++)
		{
			if ((dir && array[i] > array[i + k]) ||
			    (!dir && array[i] < array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		merge(array, low, size, k, dir);
		merge(array, low + k, size, k, dir);
	}
}
