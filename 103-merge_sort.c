#include "sort.h"

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: array of int.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right, *new;
	int mid = size / 2, i, j, k;

	i = j = k = 0;
	if (size <= 1)
		return;
	left = array;
	right = array + mid;
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	new = malloc(size * sizeof(int));
	if (!new)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);
	while (i < mid && j < (int)size - mid)
	{
		if (left[i] <= right[j])
			new[k++] = left[i++];
		else
			new[k++] = right[j++];
	}
	for (; i < mid; i++)
		new[k++] = left[i];
	for (; j < (int)size - mid ; j++)
		new[k++] = right[j];
	for (i = 0; i < (int)size; i++)
		array[i] = new[i];
	printf("[Done]: ");
	print_array(array, size);
	free(new);
}
