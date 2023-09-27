#include "sort.h"

void sift_down(int *array, size_t start, size_t end, size_t size);



/**
 * heap_sort - sorts an array of integers using
 * the heap algorithm.
 * @array: array of int.
 * @size: size of array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = size - 2; (int)i >= 0; i--)
		sift_down(array, i, size -1, size);

	for (i = size - 1; i > 0;)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		i--;
		sift_down(array, 0, i, size);
	}
}

/**
 * sift_down - repair the heap whose root element is at index 'start'
 * @array: array to sort.
 * @start: start index.
 * @end: end index.
 * @size: array size.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, swap;
	int tmp;

	root = start;
	child = 2 * root + 1;
	while (child <= end)
	{
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		root = swap;
		print_array(array, size);
		child = 2 * root + 1;
	}
}
